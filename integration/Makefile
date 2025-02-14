prog: main.o perso.o background.o enigme.o enigme6.o
	gcc main.o perso.o background.o enigme.o enigme6.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
perso.o:perso.c
	gcc -c perso.c -g
background.o:background.c
	gcc -c background.c -g
enigme.o:enigme.c
	gcc -c enigme.c
enigme6.o:enigme6.c
	gcc -c enigme6.c
