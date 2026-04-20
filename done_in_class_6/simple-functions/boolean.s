.global not
.global and
.global or
.global xor
.global all
.type not, @function
.type and, @function
.type or, @function
.type xor, @function
.type all, @function

.text

# not function
# takes an unsigned char value
# returns TRUE if the value is 0, FALSE otherwise
not:
    push %rbp
    mov %rsp, %rbp
    mov %dil, %al        # move the argument's value into the return register
    add %al, %al         # add the first argument's value to itself
    setz %al             # set the return register to the value of the Zero Flag 
    leave
    ret

# #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #
# CAUTION: the following functions only work for 1 and 0
# #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #  #

# and function
# takes two unsigned char values
# returns TRUE iff both arguments are non-zero
and:
    push %rbp
    mov %rsp, %rbp
    mov %sil, %al   # move the second argument's value into the return register
    and %dil, %al   # calculate and of the first argument's value and the return register
                    # leaving the result on the second operand (the return register)
    leave
    ret
    
# or function
# takes two unsigned char values
# returns TRUE iff at least one argument is non-zero
or:
    push %rbp
    mov %rsp, %rbp
    mov %sil, %al   # move the second argument's value into the return register
    or %dil, %al    # calculate or of the first argument's value and the return register
                    # leaving the result on the second operand (the return register)
    leave
    ret

# xor function
# takes two unsigned char values
# return TRUE iff exactly only one argument is non-zero
xor:
    push %rbp
    mov %rsp, %rbp
    mov %sil, %al   # move the second argument's value into the return register
    xor %dil, %al   # calculate xor of the first argument's value and the return register
                    # leaving the result on the second operand (the return register)
    leave
    ret

# all function
# takes a pointer to a boolean array and a size
# returns TRUE iff all elements are non-zero
all:
    push %rbp
    mov %rsp, %rbp
    mov $0, %eax

all_loop:
    cmp %esi, %eax
    jge all_true
    cmpb $0, (%rdi,%rax,1)
    je all_false
    add $1, %eax
    jmp all_loop

all_true:
    mov $1, %eax
    leave
    ret

all_false:
    mov $0, %eax
    leave
    ret
