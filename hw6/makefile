hw6: main.o deal.o det.o
	gcc -o hw6 main.o deal.o det.o

main.o: main.c head.h
	gcc -c main.c

deal.o: deal.c head.h
	gcc -c deal.c

det.o: det.c head.h
	gcc -c det.c

clean:
	rm hw6 main.o deal.o det.o
