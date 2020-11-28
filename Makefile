cc=gcc
INCLUDE_DIR=include
SOURCE=src
BINARY=bin

HUFFMAN_LIB:
	${cc} ${SOURCE}\main.c ${SOURCE}\Fileread.c -o ${BINARY}\main -I ${INCLUDE_DIR}
