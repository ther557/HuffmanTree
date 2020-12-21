#include <Project.h>
int main (int argc,char **argv){
    if(argc!=3) {
        printf("Unknown error!");
        return 1;
    }
    char buff[256];
    FileRead(argv[1],buff);
    
}