#include <Project.h>
int main (int argc,char **argv){
    if(argc!=3) {
        // print error info
        return 1;
    }
    char *fileInfoRead = NULL;

    FileRead(argv[1],&fileInfoRead);

    int Freq[256];
    char b[256];
    int setSize = WeightInput(fileInfoRead,Freq,b);

    for(int i = 0 ; i < setSize;++i){
        printf("%c:%d\n",b[i],Freq[i]);
    }

}
