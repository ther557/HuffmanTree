#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#define BUFFSIZE 256
#define CODE 10000007

typedef struct huffmanTreeNode{
  char letter;
  int weight;
  struct huffmanTreeNode* leftChild;
  struct huffmanTreeNode* rightChild;
  int order;
}HTNode,*HTNodep;


typedef struct {
    HTNodep* HT;
    int size;
    int maxSize;
}Heap,*minHeap;

typedef struct
{
    char ch;
    char *s;
}Code;


int FileRead(const char *file,char **buff);

int printStruct(HTNodep T,char *s);
int Frequence_Count(char buff[],int *freq,char *lett);
bool insert(minHeap H,HTNodep hTree);
bool IsFull(minHeap H);
bool IsEmpty(minHeap H);

HTNodep buildTree(int max,int freq[],char lett[]);
HTNodep DeleteMin(minHeap H);
HTNodep NewHuffmanNode();
minHeap CreateMinHeap(int MaxSize);
minHeap buildMinHeap(minHeap H);

void writeBinaryFile(int length, const char *buf, const char *filePath);
void loadFile(const char *filePath, int *hufLength, int *bitLen, char **huffmanTree, char **fileBit);
void saveFile(const char *filePath, const char *huffmanTree, const char *fileBit);
void decode_to_str(int strLen, const char *bit, char *str);
void encode_to_bit(const char *str, char *bit);
char *readBinaryFile(const char *filePath, int *memory);


#endif