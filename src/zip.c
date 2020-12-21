#include <Project.h>
#include <stdio.h>

int main (int argc,char **argv){
    if(argc!=3) {
        printf("Unknown error!");
        return 1;
    }
    char *fileInfoRead = NULL;

    ascFileRead(argv[1],&fileInfoRead);
    //puts(fileInfoRead);
    int Freq[256];
    char b[256];
    int setSize = Frequence_Count(fileInfoRead,Freq,b);
    HTNodep T=buildTree(setSize*2,Freq,b);
    FILE *fp=NULL;
    int sizeOfHuffman = setSize*2-1;

    sizeOfHuffman*=HUFFMAN_BASE_BLOCK_SIZE;

    char *huffmanTree = malloc(sizeOfHuffman);
    Code *Codep;
    char *encodedASC[256] = {0};
    int Len[256]={0};
    printf("%p\n",T);
    int l = printStruct(T,huffmanTree,encodedASC,0);
    for(int i = 0 ; i < 256 ; ++i){
        if(encodedASC[i]){
            Len[i] = strlen(encodedASC[i]);
        }
    }

    char *beg_file = fileInfoRead;
    int CurMaxLen = BUFSIZ+1;
    char *bitString = malloc(sizeof(char )*CurMaxLen);
    char *curPos = bitString;
    int curLen = 0;
    int fileLFinalStored = 0;
    while (*beg_file){
        int character = (char)(*beg_file);
        if(character>0) {
            if (Len[character]) {
                if (curLen + Len[character] + 1 > CurMaxLen) {
                    bitString = realloc(bitString, CurMaxLen + BUFSIZ);
                    CurMaxLen += BUFSIZ;
                }
                curPos = bitString + curLen;
                strcpy(curPos, encodedASC[character]);
                curLen += Len[character];
                ++fileLFinalStored;
            }
        }
        ++beg_file;
    }

    saveFile(argv[2],sizeOfHuffman,fileLFinalStored,huffmanTree,bitString);

}
