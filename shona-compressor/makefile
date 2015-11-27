CFLAGS=-Wall -g

OBJECTS = shona_compressor.o data.o huffman_util.o compression_util.o

shona_compressor : $(OBJECTS) 
	gcc -o shona_compressor $(OBJECTS)

shona_compressor.o : shona_compressor.c data.c data.h
data.o : data.c data.h
huffman_util.o : huffman_util.c huffman_util.h data.c data.h
compression_util.o : compression_util.c compression_util.h data.c data.h
clean :
	rm -fr shona_compressor
	rm -fr *.o

