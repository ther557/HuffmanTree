#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <stdio.h>

typedef struct huffmanTreeNode{
  char letter;
  int weight;
  struct huffmanTreeNode* leftChild;
  struct huffmanTreeNode* rightChild;
}HTNode,*HTNodep;

typedef struct {
    HTNodep* HT;
    int size;
    int maxSize;
}Heap,*minHeap;


void FileRead(const char *file,char *buff);
void Code(HTNode tree[],char *huffCode[],int n);
void Uncode(char huffCode[],FILE *fp);
void WeightInput(char buff[],int *freq[],char *lett[]);
void insert(minHeap H,HTNodep hTree);
HTNodep buildTree(int max,int freq[],char lett[]);
HTNodep deleteHeap(minHeap H);
minHeap sortHeap(minHeap H);
minHeap buildMinHeap(int max,int freq[],char lett[]);


#endif