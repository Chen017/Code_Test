# Using C from assembly to print a string

Very simple example showing a main function written in assembly, calling a function in C that takes a String as argument; see how the string is not part of any .data section in the assembly code.

1. Compile using `gcc -ggdb -o print-from-assembly printString.c usingPrintString.s`.
2. Run `objdump -d print-from-assembly` and look how the local array in `main` is represented and passed to `maximum`.
3. [Optional] Run `gdb print-from-assembly`:
  * Use `break main`; `break printString` to set breakpoints for both functions.
  * Use `run` to start the program.
  * Use `stepi` to go over each instruction; and `continue` to run until the next breakpoint.
