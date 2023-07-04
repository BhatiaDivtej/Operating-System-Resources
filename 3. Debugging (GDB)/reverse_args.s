
.global main

.text

main:
  # we are using callee-save registers to preserve information when calling printf
  push %r12
  push %r13
  push %r14
  push %r15
  enter $8, $0

  mov %rdi, %r12   # number of arguments
  mov %rsi, %r13   # argument addresses
  movq $1, %r14     # counter
  mov $1, %r15

loop:

  cmp %r12, %r14
  jge loop2

  movq (%r13, %r14, 8), %rdi

  call atol

  push %rax

  inc %r14
  jmp loop


loop2:

  cmp %r12, %r15
  jge loop_end

  mov $format, %rdi
  pop %rsi

  mov $0, %al
  call printf

  mov $message, %rdi
  movq $0, %rsi
  mov $0, %al
  call printf

  inc %r15
  jmp loop2
  
loop_end:

  leave

  pop %r15
  pop %r14
  pop %r13
  pop %r12

  ret

.data

format: 
  .asciz "%ld"

message:
  .asciz " "


