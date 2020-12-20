#include <Project.h>

bool  IsFull(minHeap H)
{
	return (H->size == H->maxSize);
}
 
bool IsEmpty(minHeap H)
{
	return (H->size == 0);
}

minHeap CreateMinHeap(int MaxSize)
{ 
	minHeap H = (minHeap)malloc(sizeof(Heap));
	H->HT = (HTNodep*)malloc((MaxSize+1) * sizeof(HTNodep));
	H->size = 0;
	H->maxSize = MaxSize;
	HTNodep T = NewHuffmanNode();
	T->weight = -1;
    T->letter= '0';
	H->HT[0] = T;
	return H;
}

HTNodep NewHuffmanNode()
{
	HTNodep BST = (HTNodep)malloc(sizeof(HTNode));
	BST->weight = 0;
    BST->letter = '0';
	BST->leftChild = BST->rightChild = NULL;
	return BST;
} 

minHeap buildMinHeap(minHeap H){
    int i,parent,child;
	HTNodep temp;
	for(i=H->size/2;i>0;i--){
		temp = H->HT[i];
		for(parent=i; parent*2<=H->size; parent=child){
			child = parent*2;
		    if((child != H->size) && (H->HT[child]->weight > H->HT[child+1]->weight)){
			    child++;
		    }
		    if(temp->weight > H->HT[child]->weight){
			    H->HT[parent] = H->HT[child];
		    }else{
			    break;
		    }
	    }
		H->HT[parent] = temp;
	} 
	return H; 
}

HTNodep DeleteMin(minHeap H)
{/*从最小堆H中取出权值为最小的元素，并删除一个结点*/
	int parent,child;
	HTNodep MinItem,temp = NULL;
	if( IsEmpty(H) ){
		printf("最小堆为空\n");
		return NULL;
	}
	MinItem = H->HT[1];  
	temp = H->HT[H->size--];  
	for(parent=1; parent*2<=H->size; parent=child){
		child = parent*2;
		if((child != H->size) && (H->HT[child]->weight > H->HT[child+1]->weight)){
			child++;  
		}
		if(temp->weight > H->HT[child]->weight){
			H->HT[parent] = H->HT[child];  
		}else{
			break;  
		}
	} 
	H->HT[parent] = temp;  
	
	return MinItem; 
}

bool insert(minHeap H,HTNodep hTree)
{
	int i;
	if( IsFull(H) ){
		printf("最小堆已满\n");
		return false;
	}
	i = ++H->size;  
	for(; H->HT[i/2]->weight > hTree->weight; i/=2)   
	    H->HT[i] = H->HT[i/2];  
	H->HT[i] = hTree;    
	return true;
}

HTNodep buildTree(int max,int freq[],char lett[]){
    minHeap H=CreateMinHeap(max);
    HTNodep T;
    for (int i = 1; i <=H->maxSize/2; i++)//存储权值及对应字符
    {
        T=NewHuffmanNode();
        T->weight=freq[i-1];
        T->letter=lett[i-1];
        H->HT[++(H->size)]=T;
    }
    buildMinHeap(H);
    int i,num;
	num = H->size;     
	for(i=1; i<num; i++){
		T = NewHuffmanNode();  //建立一个新的根结点 
		T->leftChild = DeleteMin(H);
		T->rightChild = DeleteMin(H); 
		T->weight = T->leftChild->weight+T->rightChild->weight;
		insert(H,T);
	} 
	T = DeleteMin(H);
	return T; 
}