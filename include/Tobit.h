#ifndef _PROJECT_H_
#define _PROJECT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CODE 10000007

void writeBinaryFile(int length, const char *buf, const char *filePath);
void loadFile(const char *filePath, int *hufLength, int *bitLen, char **huffmanTree, char **fileBit);
void saveFile(const char *filePath, const char *huffmanTree, const char *fileBit);
void decode_to_str(int strLen, const char *bit, char *str);
void encode_to_bit(const char *str, char *bit);
char *readBinaryFile(const char *filePath, int *memory);

#endif