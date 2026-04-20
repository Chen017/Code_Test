.global bad_1
.global bad_2
.type bad_1, @function
.type bad_2, @function
.extern printf
.type printf, @function

.text

# takes two int arguments and calls printf on 
# the result of dumb_2
bad_1:
    push %rbp
    mov %rsp, %rbp
    mov %edi, %r8d
    mov %esi, %r9d
    call bad_2
    mov %r10d, %esi
    lea format(%rip), %rdi
    xor %rax, %rax
    call printf
    leave
    ret

# Takes two arguments in r8d and r9d
# returns the sum in r10d
bad_2:
    push %rbp
    mov %rsp, %rbp
    mov %r9d, %r10d
    add %r8d, %r10d
    leave
    ret


.data
format: .asciz "from bad_1, bad_2's result is %d\n"
