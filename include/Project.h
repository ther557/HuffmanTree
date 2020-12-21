#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#define BUFFSIZE 256
int NUM=0;

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
void enCode(HTNodep T, char *s, Code *Codep);
char printStruct(HTNodep T,char *s);
int Frequence_Count(char buff[],int *freq,char *lett);
bool insert(minHeap H,HTNodep hTree);
bool IsFull(minHeap H);
bool IsEmpty(minHeap H);
char *MatchingString(char *s1, char *s2);
void Translate(char str[],HTNodep T,FILE *fp);
HTNodep buildTree(int max,int freq[],char lett[]);
HTNodep DeleteMin(minHeap H);
HTNodep NewHuffmanNode();
minHeap CreateMinHeap(int MaxSize);
minHeap buildMinHeap(minHeap H);


#endif