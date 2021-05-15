# Bu bir makefile
# Yorum satırı

CC = gcc
OBJ = main.o fields.o jval.o jrb.o

all: main


main: main.o fields.o jval.o jrb.o
	$(CC) $(OBJ) -o $@

main.o: main.c
	$(CC) -c $<
#	gcc -c p3.c

fields.o: ./libfdr/fields.c ./libfdr/fields.h
	$(CC) -c $<
# 	gcc p3.o fields.o -o p3
jval.o: ./libfdr/jval.c ./libfdr/jval.h
	$(CC) -c $<
jrb.o: ./libfdr/jrb.c ./libfdr/jrb.h
	$(CC) -c $<
clean:
	rm *.o

vclean:
	rm -rf *.o
	rm main
