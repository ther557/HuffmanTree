cc=gcc
INCLUDE_DIR=include
SOURCE=src
BINARY=bin
OUT_FILE_PREFIX=my

HUFFMAN_LIB:
	#将其他源文件编译为静态/动态库，推荐先编译为静态库
	${cc} {SOURCE}\Fileread.c -c -o ${BINARY}\main.o -I ${INCLUDE_DIR}

ZIP:HUFFMAN_LIB
	#添加引用的库对可执行文件进行编译
	${cc} ${SOURCE}\zip.c -o ${BINARY}\${OUT_FILE_PREFIX}zip
UNZIP:HUFFMAN_LIB
	${cc} ${SOURCE}\unzip.c ${BINARY}\${OUT_FILE_PREFIX}unzip
ALL:ZIP,UNZIP
	echo "done"