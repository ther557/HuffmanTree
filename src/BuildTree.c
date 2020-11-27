#include <stdio.h>
#include <malloc.h>
#include "Project.h"

minHeap sortHeap(minHeap H){
    int i,parent,child;
    HTNodep temp;
    for(i=H->size/2;i>=1;i--){
        for(parent=i;2*parent<=H->size;parent=child){
            child = 2*parent;
            if(child!=H->size && (H->HT[child]->weight>H->HT[child+1]->weight)){
                child++;
            }
            if(H->HT[parent]->weight > H->HT[child]->weight){
               temp = H->HT[parent];
               H->HT[parent] = H->HT[child];
               H->HT[child] = temp;
            }
        }
    }
    return H;
}

minHeap buildMinHeap(int max,int freq[],char lett[]){
    minHeap H=(minHeap)malloc(sizeof(Heap));
    H->size=0;
    H->maxSize=max;
    H->HT=(HTNodep*)malloc((H->maxSize+1)*sizeof(HTNodep));
    H->HT[0]=NULL;
    for (int i = 1; i <= H->maxSize; i++)
    {
        H->HT[i]=(HTNodep)malloc(sizeof(HTNode));
        H->HT[i]->weight=freq[i];
        H->HT[i]->leftChild=NULL;
        H->HT[i]->rightChild=NULL;
        H->HT[i]->letter=lett[i];
        H->size++;
    }
    return sortHeap(H);
}

HTNodep deleteHeap(minHeap H){
    HTNodep temp;
    temp=H->HT[1];
    H->HT[1]=H->HT[H->size--];
    H=sortHeap(H);
    return temp;
}

void insert(minHeap H,HTNodep hTree){
    H->size++;
    H->HT[H->size] = hTree;
    H = sortHeap(H);
}

HTNodep buildTree(int max,int freq[],char lett[]){
    HTNodep hTree;
    int n;
    minHeap H=buildMinHeap(max,freq,lett);
    n=H->size;
    for(int i=0;i<n;i++){
        hTree=(HTNodep)malloc(sizeof(HTNode));
        hTree->leftChild=deleteHeap(H);
        hTree->rightChild=deleteHeap(H);
        hTree->weight=hTree->leftChild->weight+hTree->rightChild->weight;
        insert(H,hTree);
    }
    hTree=deleteHeap(H);
    free(H);
    return hTree;
}