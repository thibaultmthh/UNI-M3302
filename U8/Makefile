deps = image.o entree_sortie.o traitement.o 
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -std=c99

main: $(deps) main.o
	gcc main.o $(deps) -o main -O0

main.o: main.c image.h entree_sortie.h traitement.h
	$(CC) $(CFLAGS) -c $< -o $@

image.o: image.c image.h 
	$(CC) $(CFLAGS) -c $< -o $@

entree_sortie.o: entree_sortie.c image.h entree_sortie.h 
	$(CC) $(CFLAGS) -c $< -o $@


traitement.o: traitement.c image.h traitement.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f *.o main

