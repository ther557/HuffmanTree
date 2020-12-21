crc=Fileread.c Frequence_Count.c BuildTree.c enCode.c structOfHuffmantree.c
cc=gcc
headfile_path=C:\Users\H\Documents\GitHub\HuffmanTree\include
target:
	${cc} -shared -fPIC -o libzip.so ${crc} -I ${headfile_path}
zip:
	gcc zip.c -L. -lzip -o for_zip

.PHONY: clean
clean:
	rm *.o
