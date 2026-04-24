# Using structures, full C

Very simple example showing how structure values are represented, and how these are passed to and from functions.

1. Compile using `gcc -ggdb -o books books.c`.
2. Run `objdump -d books` and look how struc values are represented in `main`, and how they are passed, used, and returned by and from functions.
3. [Optional] Run `gdb books`:
  * Use `break <function>` to set breakpoints for any function to want to check.
  * Use `run` to start the program (you can pass arguments after `run` and will be used as command-line arguments.
  * Use `stepi` to go over each instruction; and `continue` to run until the next breakpoint.
