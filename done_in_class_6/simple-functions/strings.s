.global write
.global strLength
.global length
.global char_at
.global indexOf
.global lastIndexOf
.global toUppercase
.global toLowercase
.global digitToChar
.type write, @function
.type strLength, @function
.type length, @function
.type char_at, @function
.type indexOf, @function
.type lastIndexOf, @function
.type toUppercase, @function
.type toLowercase, @function
.type digitToChar, @function

.text

.EQU SYSCALL_WRITE, 1
.EQU STDOUT, 1

# write function
# takes a pointer to a string and an amount of characters (bytes) to write
# returns the amount of written bytes
write:
    push %rbp
    mov %rsp, %rbp
    mov %rdi, %r8
    mov $SYSCALL_WRITE, %rax
    mov $STDOUT, %rdi
    mov %esi, %edx
    mov %r8, %rsi
    syscall
    leave
    ret

# strLength function
# takes a pointer to a null-terminated string and returns how many characters it has
# returns the length of the string
strLength:
    push %rbp
    mov %rsp, %rbp
    mov $0, %eax

strLength_loop:
    cmpb $0, (%rdi,%rax,1)
    je strLength_done
    add $1, %eax
    jmp strLength_loop

strLength_done:
    leave
    ret

# length function
# same as strLength
length:
    push %rbp
    mov %rsp, %rbp
    mov $0, %eax

length_loop:
    cmpb $0, (%rdi,%rax,1)
    je length_done
    add $1, %eax
    jmp length_loop

length_done:
    leave
    ret

# char_at function
# takes a pointer to a string and an index
# returns the character at that index
char_at:
    push %rbp
    mov %rsp, %rbp
    movzbl (%rdi,%rsi,1), %eax
    leave
    ret

# indexOf function
# takes a pointer to a string and a character (1 byte) as arguments
# returns the first i such that string[i] == character, -1 if no i exists
indexOf:
    push %rbp
    mov %rsp, %rbp
    mov $0, %eax

indexOf_loop:
    cmpb $0, (%rdi,%rax,1)
    je indexOf_not_found
    cmp %sil, (%rdi,%rax,1)
    je indexOf_found
    add $1, %eax
    jmp indexOf_loop

indexOf_found:
    leave
    ret

indexOf_not_found:
    mov $-1, %eax
    leave
    ret

# lastIndexOf function
# takes a pointer to a string and a character (1 byte) as arguments
# returns the last i such that string[i] == character, -1 if no i exists
lastIndexOf:
    push %rbp
    mov %rsp, %rbp
    mov $0, %eax
    mov $-1, %edx

lastIndexOf_loop:
    cmpb $0, (%rdi,%rax,1)
    je lastIndexOf_done
    cmp %sil, (%rdi,%rax,1)
    jne lastIndexOf_next
    mov %eax, %edx

lastIndexOf_next:
    add $1, %eax
    jmp lastIndexOf_loop

lastIndexOf_done:
    mov %edx, %eax
    leave
    ret

.EQU LOWER_FST_VALUE, 97
.EQU LOWER_LST_VALUE, 122
.EQU UPPER_FST_VALUE, 65
.EQU UPPER_LST_VALUE, 90
.EQU LOWER_UPPER_DIFF, 32

# toUppercase function
# takes a string as argument
# returns a string with every letter in upper case
toUppercase:
    push %rbp
    mov %rsp, %rbp
    mov %rdi, %rax

toUppercase_loop:
    mov (%rdi), %dl
    cmp $0, %dl
    je toUppercase_done
    cmp $LOWER_FST_VALUE, %dl
    jl toUppercase_next
    cmp $LOWER_LST_VALUE, %dl
    jg toUppercase_next
    sub $LOWER_UPPER_DIFF, %dl
    mov %dl, (%rdi)

toUppercase_next:
    add $1, %rdi
    jmp toUppercase_loop

toUppercase_done:
    leave
    ret

# toLowerrcase function
# takes a string as argument
# returns a string with every letter in lower case
toLowercase:
    push %rbp
    mov %rsp, %rbp
    mov %rdi, %rax

toLowercase_loop:
    mov (%rdi), %dl
    cmp $0, %dl
    je toLowercase_done
    cmp $UPPER_FST_VALUE, %dl
    jl toLowercase_next
    cmp $UPPER_LST_VALUE, %dl
    jg toLowercase_next
    add $LOWER_UPPER_DIFF, %dl
    mov %dl, (%rdi)

toLowercase_next:
    add $1, %rdi
    jmp toLowercase_loop

toLowercase_done:
    leave
    ret

.EQU DIGIT_ZERO_ASCII, 48

# digitToChar function
# takes an unsigned int as argument (digit)
# returns an ASCII representation of digit (or 0 if digit is not a number)
digitToChar:
    push %rbp
    mov %rsp, %rbp
    cmp $9, %edi
    jg digitToChar_invalid
    mov %edi, %eax
    add $DIGIT_ZERO_ASCII, %eax
    leave
    ret

digitToChar_invalid:
    mov $0, %eax
    leave
    ret
