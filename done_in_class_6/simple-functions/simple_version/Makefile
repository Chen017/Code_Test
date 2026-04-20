.PHONY: compile
.PHONY: clean

compile: simple simple_assembly

simple: simple.c functions.c
	gcc -o simple simple.c functions.c

simple_assembly: simple.c functions_no_booleans.c boolean.s
	gcc -o simple_assembly simple.c functions_no_booleans.c boolean.s

clean:
	find . -name '*.o' -delete
	find . -name 'simple' -delete
	find . -name 'simple_assembly' -delete