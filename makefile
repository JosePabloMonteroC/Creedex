Creedex.exe: Creedex.o funciones.o
	gcc Creedex.o funciones.o -o Creedex.exe

Creedex.o: Creedex.c
	gcc -c Creedex.c

funciones.o: funciones.c
	gcc -c funciones.c
