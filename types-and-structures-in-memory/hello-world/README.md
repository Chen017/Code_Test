# Hello world!

Very simple example showing how arguments are passed to functions using registers, and how strings
are represented in an executable.

1. Compile using `gcc -ggdb -o hello-world helloworld.c`.
2. Run `objdump -d hello-world` and look how strings are represented and passed to `printf`.
3. [Optional] Run `gdb hello-world`, use `break main`; `run`; and `stepi` to see how the code
	is executed and the values of `rdi`, and `rsi`.
