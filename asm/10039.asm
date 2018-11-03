        extern scanf
        extern printf
        section .data
s:      dd 0
t:      dd 0
i:      dd 0
scanf_format: db "%d",0
printf_format: db "%d",10,0
        section .text
        global main
main:
        push ebp
        mov ebp,esp
        mov ecx,5
loop1:
        push ecx
        push t
        push scanf_format
        call scanf
        add esp,8
        pop ecx
        mov eax,dword[t]
        cmp eax,40
        ja max1
        mov eax,40
max1:
        add [s],eax
        dec ecx
        cmp ecx,0
        ja loop1

        mov eax,dword[s]
        mov edx,0
	mov ebx,5
	div ebx
	push eax
        push printf_format
        call printf
        add esp,8

        mov esp,ebp
        pop ebp
        mov eax,0
        ret
