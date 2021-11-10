#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <cstdio>

const int ALPABATS = 26;

class Tri_Node {
private:
    Tri_Node* child[ALPABATS];

public:
    Tri_Node() {
        for (int i = 0; i < ALPABATS; i++)
            child[i] = NULL;
    }

    ~Tri_Node() {
        for (int i = 0; i < ALPABATS; i++)
            if (child[i] != NULL)
                delete child[i];
    }

    int tonum(char c) {        //문자를 숫자로 변환.
        return tolower(c) - 'a';    //대문자인 경우는 소문자로 변환.
    }

    void insert(const char* words, bool flag) {
        if (*words == '\0')        //입력받은 words가 '\0'일 경우, 즉 문자열 끝인 경우.
            return;

        int next = tonum(*words);

        bool flag_new = flag;
        if (!flag_new)
        {
            std::cout << words[0];
        }

        if (child[next] == NULL) {
            child[next] = new Tri_Node();
            if (!flag_new)
            {
                flag_new = true;
            }
        }

        child[next]->insert(words + 1, flag_new);
    }

    bool find(const char* words) {
        int next = tonum(*words);

        if (*words == '\0')
            return true;

        if (child[next] == NULL)
            return false;

        return child[next]->find(words + 1);
    }
};

std::unordered_map<std::string, int> map;

int mainD()
{
	int N;
	std::cin >> N;

	std::vector<std::string> L;

    Tri_Node tri;

	for (int i = 0; i < N; ++i)
	{
		std::string s;
		std::cin >> s;

		L.push_back(s);
        tri.insert(s.c_str(), false);

        if (map.find(s) == map.end())
        {
            map[s] = 0;
        }

        ++map[s];

        if (map[s] > 1)
        {
            std::cout << map[s];
        }

        std::cout << std::endl;
	}

    return 0;
}