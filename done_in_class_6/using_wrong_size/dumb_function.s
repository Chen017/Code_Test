.global dumb
.type dump, @function

.text

dumb:
    push %rbp
    mov %rsp, %rbp
    mov $-1, %al
    leave
    ret