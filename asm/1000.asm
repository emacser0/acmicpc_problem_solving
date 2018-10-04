	extern printf
	extern scanf
        section .data
scanf_argv:      db "%d %d",0
printf_argv:      db "%d",10,0
        section .bss
n1:     resd 1
n2:     resd 1
        section .text
        global main
main:
        push n2
        push n1
        push scanf_argv
        call scanf
        add esp,12

        mov eax,dword[n1]
        add eax,dword[n2]

        push eax
        push printf_argv
        call printf
        add esp,8

        mov eax, 0
        ret
