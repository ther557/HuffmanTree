
#include <stdio.h>
#include <Project.h>


/*void printStruct(HTNodep T,FILE *fp)
{
    char str[100]={0};
    fputs("BeginHuffmanTree\n",fp);
	if( T ){
        fputs(itoa(T->order,str,10),fp);
        fputs(" ",fp);
		fputs(itoa(T->weight,str,10),fp);
        fputs(" ",fp);
        fputs(T->letter,fp);
        fputs("\n",fp);
		printStruct(T->leftChild,fp); 
		printStruct(T->rightChild,fp); 
	}
    fputs("EndHuffmanTree\n",fp);
}*/
char tempBuffer[1024];
int printStruct(HTNodep T,char *memory,char **Encoded,int turn)//
{
    if(T){
        int cnt = 1;
        int offset = T->order-1;
        char *beg = memory + offset * (HUFFMAN_BASE_BLOCK_SIZE);
        *beg = T->letter;
        int *p = (int*)(beg+1);
        *p = T->order;

        if(T->leftChild)
            *(p+1) = T->leftChild->order;
        else
            *(p+1)=0;

        if(T->rightChild)
            *(p+2) = T->rightChild->order;
        else
            *(p+2)=0;

        if(T->letter!=-1){
            Encoded[T->letter] = malloc(turn+1);
            memcpy(Encoded[T->letter],tempBuffer,sizeof(char )*turn);
            Encoded[T->letter][turn] = 0;

        }
        tempBuffer[turn] = '0';
        cnt+=printStruct(T->leftChild, memory,Encoded,turn+1);

        tempBuffer[turn] = '1';
        cnt+=printStruct(T->rightChild, memory,Encoded,turn+1);
        return cnt;
    } else{
        return 0;
    }
}