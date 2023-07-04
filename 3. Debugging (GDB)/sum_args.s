
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
  movq $0, %r15

  mov $message, %rdi
  mov $0, %al
  call printf


loop:

  cmp %r12, %r14
  jge loop_end

  movq (%r13, %r14, 8), %rdi

  call atol
  addq %rax, %r15

  inc %r14
  jmp loop
  
loop_end:

  mov $format, %rdi
  movq %r15, %rsi 
  mov $0, %al

  call printf

  leave
  pop %r15
  pop %r14
  pop %r13
  pop %r12
  ret

.data

format: 
  .asciz "%ld\n"

message:
  .asciz "Sum: "

