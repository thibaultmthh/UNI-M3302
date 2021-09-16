deps = entree_sortie.o image.o traitement.o 

main: $(deps) main.o
	gcc main.o $(deps) -o main -O0
	make clean

image.o: image.c
	$(CC) $(CFLAGS) -c $< -o $@

entree_sortie.o: entree_sortie.c
	$(CC) $(CFLAGS) -c $< -o $@


traitement.o: traitement.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o 


