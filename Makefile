arvoreB.o: arvoreB.h arvoreB.c
	gcc -c arvoreB.c

hash_lista.o: hash_lista.h hash_lista.c
	gcc -c hash_lista.c
	
hash_duplo.o: hash_duplo.h hash_duplo.c
	gcc -c hash_duplo.c

arvoreRetangulo.o: arvoreRetangulo.h arvoreB.h hash_lista.h hash_duplo.h arvoreRetangulo.c 
	gcc -c arvoreRetangulo.c

bdrr: main.o arvoreB.o arvoreRetangulo.o hash_lista.o hash_duplo.o
	gcc -o bdrr main.o arvoreB.o arvoreRetangulo.o hash_lista.o hash_duplo.o

main.o: main.c
	gcc -c main.c
