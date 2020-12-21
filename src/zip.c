#include <Project.h>
#include <stdio.h>

int main (int argc,char **argv){
    if(argc!=3) {
        printf("Unknown error!");
        return 1;
    }
    char *fileInfoRead = NULL;

    FileRead(argv[1],&fileInfoRead);
    puts(fileInfoRead);
    int Freq[256];
    char b[256];
    int setSize = Frequence_Count(fileInfoRead,Freq,b);
    HTNodep T=buildTree(setSize*2,Freq,b);
    FILE *fp=NULL;
    char *huffmanTree;
    Code *Codep;
    printf("%p\n",T);
    printStruct(T,NULL);
}
