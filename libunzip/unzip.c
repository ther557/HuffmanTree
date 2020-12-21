#include <Project.h>
int main (int argc,char **argv){
    if(argc!=3) {
        printf("Unknown error!");
        return 1;
    }
    char buff[256];
    FileRead(argv[1],buff);
    //...
    FILE *fp;
    fp=fopen("C:/Users/H/Documents/GitHub/HuffmanTree/bin/for_zip.ezip","r");
    if(fp==NULL) printf("File doesn't exist!");
}