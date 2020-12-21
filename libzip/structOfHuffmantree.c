
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

char printStruct(HTNodep T,char *s)//存储结构为：节点编号+字符+权值，无分隔
{
    char str[1000];
    while (T)
    {
        MatchingString(*s,itoa(T->order,str,10));
        MatchingString(*s,T->letter);
        MatchingString(*s,itoa(T->weight,str,10));
        printStruct(T->leftChild,*s); 
		printStruct(T->rightChild,*s); 
    }
}