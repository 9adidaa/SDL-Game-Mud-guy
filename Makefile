game:  menu.o main.o 
	gcc main.o menu.o -o game -lSDL -lSDL_image -lSDL_mixer  -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
menu.o:menu.c
	gcc -c menu.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g



