        extern printf
        section .data
num8: db '    8888888888  888    88888',10, \
        '   88     88   88 88   88  88',10, \
        '    8888  88  88   88  88888',10, \
        '       88 88 888888888 88   88',10, \
        '88888888  88 88     88 88    888888',10, \
        10, \
        '88  88  88   888    88888    888888',10, \
        '88  88  88  88 88   88  88  88',10, \
        '88 8888 88 88   88  88888    8888',10, \
        ' 888  888 888888888 88  88      88',10, \
        '  88  88  88     88 88   88888888',10
        section .text
        global main
main:
        push ebp
        mov ebp,esp
        push num8
        call printf
        add esp,4

        mov esp,ebp
        pop ebp
        mov eax,0
        ret
