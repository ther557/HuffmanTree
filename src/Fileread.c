#include "../include/Project.h"
#include <stdio.h>
void FileRead(const char *file,char *buff){
	FILE*fp=fopen(file,"r");
	if(fp==NULL){
	    printf("file doesn't exist\n");
	}else {
        fread(buff, 0x3f3f3f3f, 0x3f3f3f3f, fp);
        puts(buff);
	}
}
