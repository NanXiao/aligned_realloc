main: main.c aligned_realloc.c
	cc -std=c11 $^ -o $@
clean:
	rm -rf main
