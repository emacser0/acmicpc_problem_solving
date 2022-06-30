#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <unordered_map>
#include <regex>

// 전철역에서 운행하는 특정 호선에 대한 정보
struct StationLine
{
	StationLine() { }
	StationLine(int lineNumber, int timeSeconds) : lineNumber(lineNumber), timeSeconds(timeSeconds) { }

	// lineIndex: 해당 역의 호선 내에서의 순번
	// lineNumber: 호선 번호
	// timeSeconds: 전역으로부터 도착하는데 걸리는 시간

	int lineIndex = -1;
	int lineNumber = 0;
	int timeSeconds = 0;
};

// 전철역에 대한 정보
struct Station
{
	Station() { }
	Station(int index, const std::wstring& name, StationLine line)
		: index(index), name(name)
	{
		lines[line.lineNumber] = line;
	}

	int getFirstLine()
	{
		for (const auto& pair : lines)
		{
			auto& line = pair.second;
			return line.lineNumber;
		}

		return 0;
	}

	// index: 전체 역에서의 순번
	// lines: 해당 역에서 운행하는 호선에 대한 정보
	// name: 역 이름

	int index = -1;
	std::unordered_map<int, StationLine> lines;
	std::wstring name = L"";
};

// 전철 선에 대한 정보
struct Line
{
	Line() { }
	Line(int lineNumber) : lineNumber(lineNumber) { }

	int getNextIndex()
	{
		return stations.size();
	}

	int getLength()
	{
		return stations.size();
	}

	void addStation(Station* station)
	{
		station->lines[lineNumber].lineIndex = getNextIndex();
		stations.push_back(station);
	}

	// lineNumber: 호선 번호
	// stations: 정차역들의 리스트

	int lineNumber = 0;
	std::vector<Station*> stations;
};

// isFile: filePath의 경로가 실제로 파일인지 확인하는 함수.
// getStationFromTokens: 토큰에서 역 정보를 가져오는 함수.

bool isFile(const std::wstring& filePath);
Station* getStationFromTokens(const std::vector<std::wstring>& tokens);

int findPath(Station* current, Station* to, int elapsedTimeSeconds, std::vector<Station*> arrivedStations);

// findPath: 출발역에서 도착역까지 걸리는 최단시간과 경로를 구하는 함수.

#define ELAPSED_TIME_SECONDS_MAXIMUM 2147483637

// 최소 시간 경로
// findPath 함수에서 사용하는 전역 변수기도 함.
int minimumArrivedTimeSeconds = ELAPSED_TIME_SECONDS_MAXIMUM;
std::vector<Station*> minimumPath;

// stations: 이름으로 쿼리할 수 있도록 해시맵으로 구성
// lines: 호선 번호를 key로 가지는 해시맵으로 구성
// visited: findPath 내부에서 사용, 경로 탐색 시 해당 역을 방문했는지 체크하기 위함.
// 프로그램 실행 후 쿼리가 한번만 있으므로 전역 변수로 선언해도 지장없음.

std::unordered_map<std::wstring, Station*> stations;
std::unordered_map<int, Line> lines;
std::unordered_map<std::wstring, bool> visited;

// 입력 데이터 포맷
// 
// 아래 포맷을 가진 여러개의 줄이 입력으로 들어옴.
// 
// index,호선,역명,소요시간,거리,누적거리
// 
// index: 1부터 시작함.
// 호선: 1보다 크거나 같고 9보다 작거나 같음.
// 역명: 해당 역의 이름. ex) 서울역
// 소요시간: 이전 역에서 오는데 걸리는 시간, m(분):ss(초) 형식
// 거리: 이전 역에서 현재 역까지의 거리, km
// 누적거리: 첫 역부터 현재 역까지의 누적거리

// 모든 문자열은 한글이 있을 수 있음을 고려하여 wide string 사용.

int main()
{	
	std::wstring dataFilePath = L"data.csv";

	// 데이터 파일이 있는지 체크
	if (!isFile(dataFilePath))
	{
		std::wcerr << "[Error]: Input file is not available" << std::endl;
		return 1;
	}

	// format: 쉼표로 구분된 라인을 파싱하기 위한 정규식.
	std::wregex format(L"([^ ,]+)[, ]?", std::regex::optimize);	

	// 1~9호선 전철선을 초기화함.
	for (int i = 1; i <= 9; ++i)
	{
		lines[i] = Line(i);
	}

	wchar_t buf[512];

	std::wifstream stream(dataFilePath, std::ios_base::in);
	while (!stream.eof())
	{
		stream.getline(buf, 512);
		std::wstring lineStr(buf);

		std::vector<std::wstring> tokens;

		// 정규식을 이용해 현재 라인을 tokenize함.
		std::wsmatch matchResult;
		while (std::regex_search(lineStr, matchResult, format))
		{
			tokens.push_back(matchResult[1]);

			lineStr = matchResult.suffix();
		}

		// tokenize한 결과에서 역 정보를 추출함.
		Station* currentStation = getStationFromTokens(tokens);
		if (currentStation == nullptr)
		{
			continue;
		}

		StationLine& currentLine = currentStation->lines[currentStation->getFirstLine()];
		// 호선 안에서 몇번째 역인지 알아내어 갱신.
		currentLine.lineIndex = lines[currentLine.lineNumber].getNextIndex();

		// 현재 역이 stations에 존재하지 않을 경우 새로 추가함.
		if (stations.find(currentStation->name) == stations.end())
		{
			stations[currentStation->name] = currentStation;

			// 해당 호선의 역 리스트에 추가.
			lines[currentLine.lineNumber].addStation(currentStation);
		}
		// 이미 해당 역이 존재할 경우 현재 호선에 대한 정보만 추가함.
		else
		{
			stations[currentStation->name]->lines[currentLine.lineNumber] = currentLine;

			// 해당 호선의 역 리스트에 추가.
			lines[currentLine.lineNumber].addStation(stations[currentStation->name]);

			delete currentStation;
		}
	}

	/*
	// 노선도 디버깅용

	for (auto& pair : stations)
	{
		auto& station = pair.second;
		std::wcout << "역 이름: " << station.name << std::endl;
		std::wcout << "역 순번: " << station.index << std::endl;

		for (auto& pair : station.lines)
		{
			auto& stationLine = pair.second;
			std::wcout << "    " << stationLine.lineNumber << "호선 정보" << std::endl;
			std::wcout << "    " << "호선 내 역 순번: " << stationLine.lineIndex << std::endl;
			std::wcout << "    " << "소요시간(초): " << stationLine.timeSeconds << std::endl;
			std::wcout << std::endl;
		}

		std::wcout << std::endl;
	}
	 */

	std::wcout << "[출발역]: ";
	std::wcin.getline(buf, 512);

	std::wstring from(buf);

	if (stations.find(from) == stations.end())
	{
		std::wcout << "데이터에 존재하지 않는 역입니다.";
		return 1;
	}

	std::wcout << "[도착역]: ";
	std::wcin.getline(buf, 512);

	std::wstring to(buf);

	if (stations.find(to) == stations.end())
	{
		std::wcout << "데이터에 존재하지 않는 역입니다.";
		return 1;
	}

	
	for (const auto& pair : stations)
	{
		visited[pair.first] = false;
	}

	int elapsedTimeSeconds = findPath(stations[from], stations[to], 0, std::vector<Station*>());
	
	std::wcout << "[최단시간]: " << elapsedTimeSeconds / 60 << "분 " << elapsedTimeSeconds % 60 << "초" << std::endl;
	if (elapsedTimeSeconds < ELAPSED_TIME_SECONDS_MAXIMUM)
	{
		std::wcout << "[경유정거장]: " << from << " -> ";

		for (int i = 0; i < minimumPath.size(); ++i)
		{
			std::wcout << minimumPath[i]->name;
			if (i < minimumPath.size() - 1)
			{
				std::wcout << " -> ";
			}			
		}
		std::wcout << std::endl;
	}

	// 할당한 메모리 해제
	for (auto& pair : stations)
	{
		delete pair.second;
	}

	stations.clear();
	lines.clear();
}

bool isFile(const std::wstring& filePath)
{
	return std::filesystem::directory_entry(filePath).is_regular_file();
}

Station* getStationFromTokens(const std::vector<std::wstring>& tokens)
{
	if (tokens.size() != 6)
	{
		return nullptr;
	}

	// index: 역의 순번, 편의를 위해 0부터 시작하도록 함.
	// lineNumber: 호선 번호
	// timeSeconds: 계산하기 쉽도록 m:ss 포맷에서 초 단위로 변환한 소요시간.
	// name: 역 이름

	int index = std::stoi(tokens[0]) - 1;	
	int lineNumber = std::stoi(tokens[1]);
	int timeSeconds = (tokens[3][0] - L'0') * 60 + (tokens[3][2] - L'0') * 10 + tokens[3][3] - L'0';
	std::wstring name = tokens[2];

	StationLine currentLine(lineNumber, timeSeconds);

	return new Station(index, name, currentLine);
}


// 백트래킹 알고리즘으로 구현함.
// current: 현재 탐색중인 역
// to: 목적지 역
// elapsedTimeSeconds: 현재까지 걸린 시간
// currentPath: 현재 경로

int findPath(
	Station* current,
	Station* to,
	int elapsedTimeSeconds,
	std::vector<Station*> currentPath)
{
	if (current->name == to->name)
	{
		if (elapsedTimeSeconds < minimumArrivedTimeSeconds)
		{
			minimumArrivedTimeSeconds = elapsedTimeSeconds;
			minimumPath = currentPath;
		}

		return elapsedTimeSeconds;
	}
	
	// 현재까지 걸린 시간이 현재까지 구한 최소 시간보다 크면 더이상 탐색할 필요가 없음.
	if (elapsedTimeSeconds > minimumArrivedTimeSeconds)
	{
		return elapsedTimeSeconds;
	}

	visited[current->name] = true;

	int minimumTimeSeconds = ELAPSED_TIME_SECONDS_MAXIMUM;

	for (auto& pair : current->lines)
	{
		auto& stationLine = pair.second;
		int lineNumber = stationLine.lineNumber;
		int lineIndex = stationLine.lineIndex;

		auto& currentLine = lines[lineNumber];
		
		// 왼쪽 정류장이 있으면, 그리고 아직 탐색하지 않았으면 탐색
		if (lineIndex > 0 && !visited[currentLine.stations[lineIndex - 1]->name])
		{
			auto nextStation = currentLine.stations[lineIndex - 1];		

			currentPath.push_back(nextStation);

			int arriveTime = findPath(nextStation, to, elapsedTimeSeconds + stationLine.timeSeconds, currentPath);
			minimumTimeSeconds = minimumTimeSeconds < arriveTime ? minimumTimeSeconds : arriveTime;
			
			// 백트래킹을 위해 되돌림.
			currentPath.pop_back();
			visited[nextStation->name] = false;
		}
		// 오른쪽 정류장이 있으면, 그리고 아직 탐색하지 않았으면 탐색
		if (lineIndex < currentLine.getLength() - 1 && !visited[currentLine.stations[lineIndex + 1]->name])
		{
			auto nextStation = currentLine.stations[lineIndex + 1];

			currentPath.push_back(nextStation);

			int arriveTime = findPath(nextStation, to, elapsedTimeSeconds + nextStation->lines[lineNumber].timeSeconds, currentPath);
			minimumTimeSeconds = minimumTimeSeconds < arriveTime ? minimumTimeSeconds : arriveTime;

			// 백트래킹을 위해 되돌림.
			currentPath.pop_back();
			visited[nextStation->name] = false;
		}
	}

	return minimumTimeSeconds;
}
