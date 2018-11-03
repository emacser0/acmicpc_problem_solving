        extern printf
        extern scanf
        section .data
a:      dd 0
b:      dd 0
c:      dd 0
scanf_format: db "%d %d",0
printf_format: db "%.10f",10,0
        section .text
        global main
main:
        push ebp
        mov ebp,esp

        push b
        push a
        push scanf_format
        call scanf
        add esp,12

        mov eax,dword[a]
        finit
        mov eax,a
        fild dword[eax]
        mov eax,b
        fidiv dword[eax]
        fstp qword[eax]
        push dword[eax+4]
        push dword[eax]
        push printf_format
        call printf
        add esp,8
        mov esp,ebp
        pop ebp
        mov eax,0
        ret
