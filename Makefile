
nomeAula=Janelas

all: $(nomeAula)

$(nomeAula): Janelas.o funcoes.o
	gcc -o $(nomeAula) Janelas.o funcoes.o

Janelas.o: Janelas.c
	gcc -c Janelas.c 

funcoes.o: funcoes.c
	gcc -c funcoes.c 
clean:
	rm -f *.o *.gch $(nomeAula)
