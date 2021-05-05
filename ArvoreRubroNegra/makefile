all: teste

teste: artigo.o ArvRN.o
	gcc -o teste artigo.o ArvRN.o

hospede.o: artigo.c ArvRN.h
	gcc -c -o artigo.o artigo.c -Wall

ArvBinAvl.o: ArvRN.c
	gcc -c -o ArvRN.o ArvRN.c -Wall

clean:
	rm artigo.o ArvRN.o teste
