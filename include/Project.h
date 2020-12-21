#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

#define CODE 10000007
#define HUFFMAN_BASE_BLOCK_SIZE (sizeof(int)*3+sizeof(char))
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


int ascFileRead(const char *file,char **buff);
int ascFileWrite(const char *file,const char *buff);

int printStruct(HTNodep T,char *memory,char **Encoded,int turn);
int Frequence_Count(char buff[],int *freq,char *lett);
bool insert(minHeap H,HTNodep hTree);
bool IsFull(minHeap H);
bool IsEmpty(minHeap H);

HTNodep buildTree(int max,int freq[],char lett[]);
HTNodep DeleteMin(minHeap H);
HTNodep CreateHufNode(char letter,int weight,int order);
minHeap CreateMinHeap(int MaxSize);
minHeap buildMinHeap(minHeap H);

void writeBinaryFile(int length, const char *buf, const char *filePath);
void loadFile(const char *filePath, int *hufLength, int *bitLen,int *fileLength, char **huffmanTree, char **fileBit);
void saveFile(const char *filePath,int hufLen,int FileLength, const char *huffmanTree, const char *fileBit);
void decode_to_str(int strLen, const char *bit, char *str);
void encode_to_bit(const char *str, char *bit);
char *readBinaryFile(const char *filePath, int *memory);


#endif