
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

int printStruct(HTNodep T,char *s)//存储结构为：节点编号+字符+权值，无分隔
{
    if(T){
        if(T->leftChild) {
            printf("%d %c %d %d\n", T->order, T->letter, T->leftChild->order, T->rightChild->order);
        }
        printStruct(T->leftChild,s);
        printStruct(T->rightChild,s);
    } else{
        return 0;
    }
}