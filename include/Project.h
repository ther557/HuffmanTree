#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <stdio.h>

typedef struct huffmanTreeNode{
  char letter;
  int weight;
  struct huffmanTreeNode* leftChild;
  struct huffmanTreeNode* rightChild;
}HTNode,*HTNodep;


hTree->leftchild->weight

typedef struct {
    HTNodep* HT;
    int size;
    int maxSize;
}Heap,*minHeap;


void FileRead(const char *file,char *buff);
void Code(HTNodep hTree,int *huffCode[],int n);
void Uncode(char huffCode[],FILE *fp);
void WeightInput(char buff[],int *freq[],char *lett[]);
bool insert(minHeap H,HTNodep hTree);
bool IsFull(minHeap H);
bool IsEmpty(minHeap H);
HTNodep buildTree(int max,int freq[],char lett[]);
HTNodep DeleteMin(minHeap H);
HTNodep NewHuffmanNode();
minHeap CreateMinHeap(int MaxSize);
minHeap buildMinHeap(minHeap H);


#endif