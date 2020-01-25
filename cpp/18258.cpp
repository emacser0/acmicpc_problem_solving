#include <cstdio>
#include <cstring>
#include <initializer_list>
#include <functional>
template <typename T>
bool is_in(T value, T *list, size_t list_len)
{
    for(int i = 0; i < list_len; ++i)
    {
        if(value == list[i]) return true;
    }
    return false;
}
char* jump_space(char *ptr)
{
    char spaces[] = {' ', '\n'};
    while(is_in(*ptr, spaces, 2)) ++ptr;
    return ptr;
}
const int queue_max_size = 2100000;
int queue[2100000], fi, bi = -1, queue_size;
char command_name_list[][9] = {"push", "pop", "size", "empty", "front", "back"};
void (*command_func_list[])(char *) = 
{
    [](char *buffer_ptr)
    {
        int X;
        sscanf(buffer_ptr, "%d", &X);
        bi = (bi + 1) % queue_max_size;
        queue[bi] = X;
        queue_size += 1;
    },
    [](char *buffer_ptr)
    {
        if(!queue_size)
        {
            printf("%d\n", -1);
            return;
        }
        printf("%d\n", queue[fi]);
        fi = (fi + 1) % queue_max_size;
        queue_size -= 1;
    },
    [](char *buffer_ptr)
    {
        printf("%d\n", queue_size);
    },
    [](char *buffer_ptr)
    {
        printf("%d\n", queue_size == 0);
    },
    [](char *buffer_ptr)
    {
        printf("%d\n", queue_size ? queue[fi] : -1);
    },
    [](char *buffer_ptr)
    {
        printf("%d\n", queue_size ? queue[bi] : -1);
    }
};
int command_count = 6;
void run_command(char *command_name, char *buffer_ptr)
{
    for(int j = 0; j < command_count; ++j)
    {
        if(strcmp(command_name, command_name_list[j]) == 0)
        {
            command_func_list[j](buffer_ptr);
            break;
        }
    }
}
int main()
{
    int N;
    char buffer[999];
    fgets(buffer, 999, stdin);
    sscanf(buffer, "%d", &N);
    {
        for(int i = 0; i < N; ++i)
        {
            fgets(buffer, 999, stdin);
            char command[9];
            sscanf(buffer, "%s", command);
            char *buffer_ptr = jump_space(buffer + strlen(command));
            run_command(command, buffer_ptr);
        }
    }
}