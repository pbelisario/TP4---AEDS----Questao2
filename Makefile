FONTES = arquivo.c lista.c main.c
OBJETOS = arquivo.o lista.o main.o

all: main

main : $(OBJETOS)
	gcc $(OBJETOS) -o main 

$(OBJETOS) : $(FONTES)
	gcc -c $(FONTES)

clean :
	-@ rm -f $(OBJETOS)
