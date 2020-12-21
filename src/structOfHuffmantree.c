
#include <stdio.h>
#include <Project.h>

void printStruct(HTNodep T,FILE *fp)
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
}