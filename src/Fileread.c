#include "../include/Project.h"
#include <stdio.h>
void FileRead(const char *file,char *buff){
	FILE*fp=fopen(file,"r");
	puts(file);
	if(fp==NULL){
	    printf("file doesn't exist\n");
	}else {
        fread(buff, 256, 256, fp);
        puts(buff);
	}
}
