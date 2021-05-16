
CC = gcc
OBJ = main.o fields.o jval.o jrb.o

hepsi: main


main: main.o fields.o jval.o jrb.o
	$(CC) $(OBJ) -o $@

main.o: main.c
	$(CC) -c $<

#	gcc -c p3.c
# libfdr kütüphanesi fields kaynak ve başlık dosyası işlemleri
fields.o: ./libfdr/fields.c ./libfdr/fields.h
	$(CC) -c $<

# 	gcc p3.o fields.o -o p3
# libfdr kütüphanesi jval kaynak ve başlık dosyası işlemleri
jval.o: ./libfdr/jval.c ./libfdr/jval.h
	$(CC) -c $<

# libfdr kütüphanesi jrb kaynak ve başlık dosyası işlemleri
jrb.o: ./libfdr/jrb.c ./libfdr/jrb.h
	$(CC) -c $<

# .o dosyaları temizlenir
temizle:
	rm *.o

vtemizle:
	rm -rf *.o
	rm main
