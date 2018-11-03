        extern printf
        section .data
animal1: db '|\_/|',10,0
animal2: db '|q p|   /}',10,0
animal3: db '( 0 )"""\',10,0
animal4: db '|"^"`    |',10,0
animal5: db '||_/=\\__|',10,0
printf_format: db '%s%s%s%s%s',0
        section .text
        global main
main:
        push ebp
        mov ebp,esp
        push animal5
        push animal4
        push animal3
        push animal2
        push animal1
        push printf_format
        call printf
        add esp,24
end_of_main:
        mov esp,ebp
        pop ebp
        mov eax,0
        ret
