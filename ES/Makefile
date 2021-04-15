prog:es.o main.o
	gcc es.o main.o -o prog -lSDL -lSDL_image
main.o:main.c
	gcc main.c -c -lSDL -lSDL_image
es.o:es.c
	gcc es.c -c -lSDL -lSDL_image
execute:
	./prog