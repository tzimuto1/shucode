CFLAGS=-Wall -g

OBJECTS = shona_decompressor.o data.o

shona_decompressor : $(OBJECTS) 
	gcc -o shona_decompressor $(OBJECTS) -lm

shona_decompressor.o : shona_decompressor.c data.c data.h
data.o : data.c data.h

clean :
	rm -fr shona_decompressor
	rm -fr *.o

