.global isEven
.global isOdd
.global max
.global maximum
.type isEven, @function
.type isOdd, @function
.type max, @function
.type maximum, @function

.text

# isEven function
# takes one integer number as argument
# returns true (1) iff the argument is even
isEven:
    push %rbp
    mov %rsp, %rbp
    mov %edi, %eax
    and $1, %eax
    cmp $0, %eax
    sete %al
    leave
    ret

# isOdd function
# takes one integer number as argument
# returns true (1) iff the argument is odd
isOdd:
    push %rbp
    mov %rsp, %rbp
    mov %edi, %eax
    and $1, %eax
    cmp $1, %eax
    sete %al
    leave
    ret

# max function
# takes two integer numbers as arguments
# returns the maximum of the two
max:
    push %rbp
    mov %rsp, %rbp
    mov %edi, %eax
    cmp %esi, %edi
    jge max_done
    mov %esi, %eax
max_done:
    leave
    ret

# maximum function
# takes a pointer to an int array and its size
# returns the biggest value in the array
maximum:
    push %rbp
    mov %rsp, %rbp

    cmp $0, %esi
    jg maximum_has_elements
    mov $0, %eax
    leave
    ret

maximum_has_elements:
    mov (%rdi), %eax
    mov $1, %ecx

maximum_loop:
    cmp %esi, %ecx
    jge maximum_done

    mov (%rdi,%rcx,4), %edx
    cmp %edx, %eax
    jge maximum_next
    mov %edx, %eax

maximum_next:
    add $1, %ecx
    jmp maximum_loop

maximum_done:
    leave
    ret
