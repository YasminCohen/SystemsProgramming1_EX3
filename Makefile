CC=gcc
Ar=ar
FLAGS = -Wall -g
Isort_MAIN = isort.o
Txtfind_MAIN = txtfind.o

all: isort.o txtfind.o isort txtfind

isort: $(Q1_MAIN)
	$(CC) $(FLAGS) -o isort $(Isort_MAIN)

txtfind: $(Q2_MAIN)
	$(CC) $(FLAGS) -o txtfind $(Txtfind_MAIN)

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so $(NAME) isort txtfind