        extern printf
        extern scanf
        section .data
scanf_argv:     db "%s",0
printf_argv:    db "%d",10,0
printf_argv2:   db "%s",10,0
cnt:    dd 0
buf:    times 1000000 db 0
        section .text
        global main
        global loop
        global end_of_loop
main:
        push ebp
        mov ebp,esp
loop:
        push buf
        push scanf_argv
        call scanf
        add esp, 8
        cmp eax, -1
        je end_of_loop
        add dword[cnt],1
        jmp loop
end_of_loop:
        push dword[cnt]
        push printf_argv
        call printf
        add esp, 8
        mov esp,ebp
        pop ebp
        mov eax, 0
        ret
