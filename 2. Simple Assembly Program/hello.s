# Hello World in Assembly using printf

.global main

.text

main:
    enter $0, $0


    # PART1 TASK 1
    mov $message, %rdi
    mov $0, %al
    call printf


    # PART1 TASK 2
    mov $long_format, %rdi

    # Mathematical Operation: (2 * a + b * c) >> 4);
    mov a, %rsi
    add %rsi, %rsi
    mov b, %rdx
    mov c, %rcx
    imul %rdx, %rcx
    add %rcx, %rsi

    sar $4, %rsi

    # Register Use Order
    # rdi
    # rsi
    # %rdx
	# %rcx
    # %r8
	# %r9

    mov $0, %al
    call printf

    # PART2 TASK 1

    mov d, %rdi
    call labs

    mov $long_format, %rdi
    mov %rax, %rsi

    mov $0, %al
    call printf


    # PART2 TASK 2

    mov d, %rdi
    mov e, %rax

    imul %rax, %rdi

    sal $3, %rdi
    call labs

    mov $long_format, %rdi
    mov %rax, %rsi

    mov $0, %al
    call printf


    leave
    ret

.data

message:
   .asciz "Hello, World!\n"
a: 
    .quad 0x3908
b: 
    .quad 0x721
c: 
    .quad 16
d: 
    .quad -32
e: 
    .quad 64
long_format:
    .asciz "%ld\n"