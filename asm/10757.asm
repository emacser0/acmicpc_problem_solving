        extern printf
        extern scanf
        extern strlen
        extern puts
        section .data
b:      dd 0
s:      dd 0
blen:   dd 0
slen:   dd 0
array_bf: times 20004 db '0'
scanf_format:   db "%s %s",0
        section .text
        global main
main:
        push ebp
        mov ebp,esp
get_input_and_init:
        mov byte[array_bf+10001],0
        mov byte[array_bf+20003],0
        lea eax,[array_bf+1]
        lea ebx,[array_bf+10002+1]
        push ebx
        push eax
        push scanf_format
        call scanf
        add esp,4
        mov eax,ebx
        call strlen
        add esp,4
        call strlen
        add esp,4
        cmp ebx,eax
        jbe else1
if1:
        mov dword[b],0
        jmp if1_end
else1:
        mov dword[b],1
if1_end:
        mov eax,dword[b]
        test eax,eax
        sete al
        movzx eax,al

        mov dword[s],eax
        mov eax,dword[b]
        imul eax,eax,10002
        add eax,array_bf
        push eax
        call strlen
        add esp,4
        mov dword[blen],eax
        mov eax,dword[s]
        imul eax,eax,10002
        add eax,array_bf
        push eax
        call strlen
        add esp,4
        mov dword[slen],eax
init_loop1:
        mov ecx,dword[slen]
        dec ecx
        mov edx,dword[b]
        imul edx,edx,10002
        add edx,array_bf
        add edx,dword[blen]
        sub edx,dword[slen]
loop1:
        mov eax,edx
        add eax,ecx
        mov ebx,dword[s]
        imul ebx,ebx,10002
        add ebx,ecx
        add ebx,array_bf
        mov bl,byte[ebx]
        mov byte[eax],bl
        dec ecx
        cmp ecx,1
        jae loop1
init_loop2:
        mov ecx,dword[blen]
        dec ecx
        mov edx,dword[b]
        imul edx,edx,10002
        add edx,array_bf
loop2:
        mov eax,edx
        add eax,ecx
        cmp byte[eax],58
        jb cmpj1
        sub byte[eax],10
        dec eax
        inc byte[eax]
cmpj1:
        dec ecx
        cmp ecx,1
        jae loop2
if2_cmp:
        mov eax,edx
        add eax,1
        cmp byte[eax],58
        jb else2
if2:
        sub byte[eax],10
        dec eax
        inc byte[eax]
        push eax
        call puts
        add esp,4
        jmp if2_end
else2:
        push eax
        call puts
        add esp,4
if2_end:
end_of_main:
        mov esp,ebp
        pop ebp
        mov eax,0
        ret
