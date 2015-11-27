#Shona Huffman Compressor and Decompressor (shucode)

This project comprises of compression and decompression components. Huffman coding is the alogorithm of choice. The project uses [Canonical Huffman Code](https://en.wikipedia.org/wiki/Canonical_Huffman_code) , a special type of Huffman codes.

##Symbols

In many Huffman codes used for ASCII text, the symbols are individual ASCII characters. However, in this project the symbols consists of all printable ASCII[1] characters and all [Shona language](https://en.wikipedia.org/wiki/Shona_language) syllables. Shona consists of around 310 syllables. In this projects the variations of the syllables included in the set of symbols are as follows:

    1. All syllables with all the characters in lowercase
    2. All syllables with all characters in lowercase except for the first character

So, the set of all variations of Shona syllables is about 310 * 2 = 620.

I could have included the syllables with all the characters in uppercase. I didn't do this because most text exist in the two forms above. If a document has all uppercase characters, the Huffman coding will operate as usual with the characters as the symbols.

##Compression Ratios


| Input File Size | Output File Site | Compression | Notes                                                             |
| --------------- | ---------------- | ----------- | ----------------------------------------------------------------- |
| 255K            | 117K             | 54%         | Shona Text: From Wikipedia and news articles                      |
| 5.3M            | 3.0M             | 43%         | English Text: All works by Shakespeare                            |
| 6.4M            | 3.4M             | ~47%        | Shona Text: Shona Bible with about 2KB or nonprintable characters |


[1] The nonprintable ascii characters are ignored if they exist in the document. Since compression can produce any extended ASCII character, printable or not, we can't compress the result of compression and still recover the orginal file. Using one level of compression, we recover the original file.

