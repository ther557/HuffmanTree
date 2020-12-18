#include <Project.h>
int main (int argc,char **argv){
    if(argc!=3) {
        // print error info
        return 1;
    }
    char *fileInfoRead = NULL;

    FileRead(argv[1],&fileInfoRead);

    puts(fileInfoRead);


}
