# Maximum

Very simple example showing how arguments are passed to functions using registers, and how arrays
are represented in an executable.

1. Compile using `gcc -ggdb -o maximum maximum.c`.
2. Run `objdump -d maximum` and look how the local array in `main` is represented and passed to `maximum`.
3. [Optional] Run `gdb maximum`:
  * Use `break main`; `break maximum` to set breakpoints for both functions.
  * Use `run` to start the program (you can pass arguments after `run` and will be used as command-line arguments.
  * Use `stepi` to go over each instruction; and `continue` to run until the next breakpoint.
