crc=Fileread.c Frequence_Count.c BuildTree.c code.c 
cc=gcc
headfile_path=C:\Users\H\Documents\GitHub\HuffmanTree\include
lib_path=C:\Users\H\Documents\GitHub\HuffmanTree\lib

target:
    ${cc} -shared -fPIC -o libzip.so ${crc} -I ${headfile_path}
zip:
    ${cc}  zip.c -o for_zip -I ${headfile_path}  -lzip  -L${lib_path}

.PHONY: clean
clean:
    rm *.o