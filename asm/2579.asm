        extern printf
        extern scanf
        section .data
scanf_format: db "%d",0
printf_format: db "%d",10,0
        section .bss
n:      resd 1
t:      resd 1
stairs: resd 302
dp:     resd 302
        section .text
        global main
main:
        push ebp
        mov ebp,esp
        push n
        push scanf_format
        call scanf
        add esp,8
        mov ecx,0
read_stairs:
        cmp ecx,dword[n]
        jae init_dp

        pushf
        push ecx
        push t
        push scanf_format
        call scanf
        add esp,8
        pop ecx
        popf
        mov eax,dword[t]
        mov dword[stairs+ecx*4],eax
        inc ecx
        jb read_stairs
init_dp:
        mov eax,dword[stairs]
        mov dword[dp],eax
        add eax,dword[stairs+4]
        mov dword[dp+4],eax
        sub eax,dword[stairs+4]
        mov ebx,dword[stairs+8]
        add eax,ebx
        add ebx,dword[stairs+4]
        cmp eax,ebx
        ja max1
        mov eax,ebx
max1:
        mov dword[dp+8],eax
init_loop1:
        mov ecx,3
loop1:
        cmp ecx,dword[n]
        jae print1
        mov eax,dword[dp+ecx*4-8]
        add eax,dword[stairs+ecx*4]
        mov ebx,dword[dp+ecx*4-12]
        add ebx,dword[stairs+ecx*4-4]
        add ebx,dword[stairs+ecx*4]
        cmp eax,ebx
        ja max2
        mov eax,ebx
max2:
        mov dword[dp+ecx*4],eax
        inc ecx
        cmp ecx,dword[n]
        jb loop1
print1:
        mov eax, dword[n]
        push dword[dp+eax*4-4]
        push printf_format
        call printf
        add esp,12
end_of_main:
        mov esp,ebp
        pop ebp
        mov eax,0
        ret
