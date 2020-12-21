#include <Project.h>

void Translate(char str[],HTNodep T,FILE *fp){//str为huffman编码01序列,T为huffmantree根节点
    int i=0,cnt=0;
    HTNodep flag=T;
    while(str[i]){
        if(cnt==NUM) break;
        if(str[i]==0) flag=flag->leftChild;
        else if(str[i]==1) flag=flag->rightChild;
        if(flag->leftChild==NULL) fputs(flag->letter,fp);
        flag=T;
        cnt++;
        i++;
    }
}