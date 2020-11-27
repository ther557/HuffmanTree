#include <stdio.h>
#include <malloc.h>
#include "Project.h"
/**
 *  @author 2020011678 #?吴麒
 */
minHeap sortHeap(minHeap H){        //最小堆排序
    int i,parent,child;
    HTNodep temp;
    for(i=H->size/2;i>=1;i--){
        for(parent=i;2*parent<=H->size;parent=child){
            child = 2*parent;
            if(child!=H->size && (H->HT[child]->weight>H->HT[child+1]->weight)){//有rightchild并且leftchild权值较大
                child++;        //child移向权值较小者
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

minHeap buildMinHeap(int max,int freq[],char lett[]){       //将数组数据存入结点并进行最小堆排序
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

HTNodep deleteHeap(minHeap H){      //取出第一个即最小值结点，并删除
    HTNodep temp;
    temp=H->HT[1];
    H->HT[1]=H->HT[H->size--];
    H=sortHeap(H);
    return temp;
}

void insert(minHeap H,HTNodep hTree){       //将结点插入到序列末尾
    H->size++;
    H->HT[H->size] = hTree;
    H = sortHeap(H);
}

HTNodep buildTree(int max,int freq[],char lett[]){      //建立Huffman树
    HTNodep hTree;
    int n;
    minHeap H=buildMinHeap(max,freq,lett);
    n=H->size;
    for(int i=0;i<n;i++){
        hTree=(HTNodep)malloc(sizeof(HTNode));
        hTree->leftChild=deleteHeap(H);     //将最小和次小权值的结点分别分给左右儿子
        hTree->rightChild=deleteHeap(H);
        hTree->weight=hTree->leftChild->weight+hTree->rightChild->weight;       //权值为二者之和
        insert(H,hTree);
    }
    hTree=deleteHeap(H);        //传出Huffman树的根节点
    free(H);
    return hTree;
}