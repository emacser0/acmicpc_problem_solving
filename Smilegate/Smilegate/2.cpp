#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <unordered_map>
#include <regex>

// ��ö������ �����ϴ� Ư�� ȣ���� ���� ����
struct StationLine
{
	StationLine() { }
	StationLine(int lineNumber, int timeSeconds) : lineNumber(lineNumber), timeSeconds(timeSeconds) { }

	// lineIndex: �ش� ���� ȣ�� �������� ����
	// lineNumber: ȣ�� ��ȣ
	// timeSeconds: �������κ��� �����ϴµ� �ɸ��� �ð�

	int lineIndex = -1;
	int lineNumber = 0;
	int timeSeconds = 0;
};

// ��ö���� ���� ����
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

	// index: ��ü �������� ����
	// lines: �ش� ������ �����ϴ� ȣ���� ���� ����
	// name: �� �̸�

	int index = -1;
	std::unordered_map<int, StationLine> lines;
	std::wstring name = L"";
};

// ��ö ���� ���� ����
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

	// lineNumber: ȣ�� ��ȣ
	// stations: ���������� ����Ʈ

	int lineNumber = 0;
	std::vector<Station*> stations;
};

// isFile: filePath�� ��ΰ� ������ �������� Ȯ���ϴ� �Լ�.
// getStationFromTokens: ��ū���� �� ������ �������� �Լ�.

bool isFile(const std::wstring& filePath);
Station* getStationFromTokens(const std::vector<std::wstring>& tokens);

int findPath(Station* current, Station* to, int elapsedTimeSeconds, std::vector<Station*> arrivedStations);

// findPath: ��߿����� ���������� �ɸ��� �ִܽð��� ��θ� ���ϴ� �Լ�.

#define ELAPSED_TIME_SECONDS_MAXIMUM 2147483637

// �ּ� �ð� ���
// findPath �Լ����� ����ϴ� ���� �����⵵ ��.
int minimumArrivedTimeSeconds = ELAPSED_TIME_SECONDS_MAXIMUM;
std::vector<Station*> minimumPath;

// stations: �̸����� ������ �� �ֵ��� �ؽø����� ����
// lines: ȣ�� ��ȣ�� key�� ������ �ؽø����� ����
// visited: findPath ���ο��� ���, ��� Ž�� �� �ش� ���� �湮�ߴ��� üũ�ϱ� ����.
// ���α׷� ���� �� ������ �ѹ��� �����Ƿ� ���� ������ �����ص� �������.

std::unordered_map<std::wstring, Station*> stations;
std::unordered_map<int, Line> lines;
std::unordered_map<std::wstring, bool> visited;

// �Է� ������ ����
// 
// �Ʒ� ������ ���� �������� ���� �Է����� ����.
// 
// index,ȣ��,����,�ҿ�ð�,�Ÿ�,�����Ÿ�
// 
// index: 1���� ������.
// ȣ��: 1���� ũ�ų� ���� 9���� �۰ų� ����.
// ����: �ش� ���� �̸�. ex) ���￪
// �ҿ�ð�: ���� ������ ���µ� �ɸ��� �ð�, m(��):ss(��) ����
// �Ÿ�: ���� ������ ���� �������� �Ÿ�, km
// �����Ÿ�: ù ������ ���� �������� �����Ÿ�

// ��� ���ڿ��� �ѱ��� ���� �� ������ ����Ͽ� wide string ���.

int main()
{	
	std::wstring dataFilePath = L"data.csv";

	// ������ ������ �ִ��� üũ
	if (!isFile(dataFilePath))
	{
		std::wcerr << "[Error]: Input file is not available" << std::endl;
		return 1;
	}

	// format: ��ǥ�� ���е� ������ �Ľ��ϱ� ���� ���Խ�.
	std::wregex format(L"([^ ,]+)[, ]?", std::regex::optimize);	

	// 1~9ȣ�� ��ö���� �ʱ�ȭ��.
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

		// ���Խ��� �̿��� ���� ������ tokenize��.
		std::wsmatch matchResult;
		while (std::regex_search(lineStr, matchResult, format))
		{
			tokens.push_back(matchResult[1]);

			lineStr = matchResult.suffix();
		}

		// tokenize�� ������� �� ������ ������.
		Station* currentStation = getStationFromTokens(tokens);
		if (currentStation == nullptr)
		{
			continue;
		}

		StationLine& currentLine = currentStation->lines[currentStation->getFirstLine()];
		// ȣ�� �ȿ��� ���° ������ �˾Ƴ��� ����.
		currentLine.lineIndex = lines[currentLine.lineNumber].getNextIndex();

		// ���� ���� stations�� �������� ���� ��� ���� �߰���.
		if (stations.find(currentStation->name) == stations.end())
		{
			stations[currentStation->name] = currentStation;

			// �ش� ȣ���� �� ����Ʈ�� �߰�.
			lines[currentLine.lineNumber].addStation(currentStation);
		}
		// �̹� �ش� ���� ������ ��� ���� ȣ���� ���� ������ �߰���.
		else
		{
			stations[currentStation->name]->lines[currentLine.lineNumber] = currentLine;

			// �ش� ȣ���� �� ����Ʈ�� �߰�.
			lines[currentLine.lineNumber].addStation(stations[currentStation->name]);

			delete currentStation;
		}
	}

	/*
	// �뼱�� ������

	for (auto& pair : stations)
	{
		auto& station = pair.second;
		std::wcout << "�� �̸�: " << station.name << std::endl;
		std::wcout << "�� ����: " << station.index << std::endl;

		for (auto& pair : station.lines)
		{
			auto& stationLine = pair.second;
			std::wcout << "    " << stationLine.lineNumber << "ȣ�� ����" << std::endl;
			std::wcout << "    " << "ȣ�� �� �� ����: " << stationLine.lineIndex << std::endl;
			std::wcout << "    " << "�ҿ�ð�(��): " << stationLine.timeSeconds << std::endl;
			std::wcout << std::endl;
		}

		std::wcout << std::endl;
	}
	 */

	std::wcout << "[��߿�]: ";
	std::wcin.getline(buf, 512);

	std::wstring from(buf);

	if (stations.find(from) == stations.end())
	{
		std::wcout << "�����Ϳ� �������� �ʴ� ���Դϴ�.";
		return 1;
	}

	std::wcout << "[������]: ";
	std::wcin.getline(buf, 512);

	std::wstring to(buf);

	if (stations.find(to) == stations.end())
	{
		std::wcout << "�����Ϳ� �������� �ʴ� ���Դϴ�.";
		return 1;
	}

	
	for (const auto& pair : stations)
	{
		visited[pair.first] = false;
	}

	int elapsedTimeSeconds = findPath(stations[from], stations[to], 0, std::vector<Station*>());
	
	std::wcout << "[�ִܽð�]: " << elapsedTimeSeconds / 60 << "�� " << elapsedTimeSeconds % 60 << "��" << std::endl;
	if (elapsedTimeSeconds < ELAPSED_TIME_SECONDS_MAXIMUM)
	{
		std::wcout << "[����������]: " << from << " -> ";

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

	// �Ҵ��� �޸� ����
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

	// index: ���� ����, ���Ǹ� ���� 0���� �����ϵ��� ��.
	// lineNumber: ȣ�� ��ȣ
	// timeSeconds: ����ϱ� ������ m:ss ���˿��� �� ������ ��ȯ�� �ҿ�ð�.
	// name: �� �̸�

	int index = std::stoi(tokens[0]) - 1;	
	int lineNumber = std::stoi(tokens[1]);
	int timeSeconds = (tokens[3][0] - L'0') * 60 + (tokens[3][2] - L'0') * 10 + tokens[3][3] - L'0';
	std::wstring name = tokens[2];

	StationLine currentLine(lineNumber, timeSeconds);

	return new Station(index, name, currentLine);
}


// ��Ʈ��ŷ �˰������� ������.
// current: ���� Ž������ ��
// to: ������ ��
// elapsedTimeSeconds: ������� �ɸ� �ð�
// currentPath: ���� ���

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
	
	// ������� �ɸ� �ð��� ������� ���� �ּ� �ð����� ũ�� ���̻� Ž���� �ʿ䰡 ����.
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
		
		// ���� �������� ������, �׸��� ���� Ž������ �ʾ����� Ž��
		if (lineIndex > 0 && !visited[currentLine.stations[lineIndex - 1]->name])
		{
			auto nextStation = currentLine.stations[lineIndex - 1];		

			currentPath.push_back(nextStation);

			int arriveTime = findPath(nextStation, to, elapsedTimeSeconds + stationLine.timeSeconds, currentPath);
			minimumTimeSeconds = minimumTimeSeconds < arriveTime ? minimumTimeSeconds : arriveTime;
			
			// ��Ʈ��ŷ�� ���� �ǵ���.
			currentPath.pop_back();
			visited[nextStation->name] = false;
		}
		// ������ �������� ������, �׸��� ���� Ž������ �ʾ����� Ž��
		if (lineIndex < currentLine.getLength() - 1 && !visited[currentLine.stations[lineIndex + 1]->name])
		{
			auto nextStation = currentLine.stations[lineIndex + 1];

			currentPath.push_back(nextStation);

			int arriveTime = findPath(nextStation, to, elapsedTimeSeconds + nextStation->lines[lineNumber].timeSeconds, currentPath);
			minimumTimeSeconds = minimumTimeSeconds < arriveTime ? minimumTimeSeconds : arriveTime;

			// ��Ʈ��ŷ�� ���� �ǵ���.
			currentPath.pop_back();
			visited[nextStation->name] = false;
		}
	}

	return minimumTimeSeconds;
}
