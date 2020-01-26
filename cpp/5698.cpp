#include <cstdio>
#include <cstring>
#include <cctype>
char buf[9999];
bool is_tautogram(char *buf)
{
    char prev_first_letter = tolower(buf[0]);
    buf = strtok(buf, " ");
    while(buf != NULL)
    {
        if(tolower(buf[0]) != prev_first_letter) return false;
        prev_first_letter = tolower(buf[0]);
        buf = strtok(NULL, " ");
    }
    return true;
}

int main()
{
    while(fgets(buf, 9999, stdin) != NULL)
    {
        if(buf[0] == '*') break;
        printf(is_tautogram(buf) ? "Y\n" : "N\n");
    }
}