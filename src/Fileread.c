#include <Project.h>
#include <stdio.h>
int FileRead(const char *file,char **buff) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        printf("file doesn't exist\n");
        return 0;
    } else {
        int curSize = 1 + BUFFSIZE;
        *buff = malloc(curSize * sizeof(char));
        char *anchor = *buff;
        int readB = 0;
        while ((readB = fread(anchor, sizeof(char), BUFFSIZE, fp)) != 0) {
            if (readB == BUFFSIZE) {
                curSize += BUFFSIZE;
                *buff = realloc(*buff, curSize * sizeof(char));
                anchor = *buff + curSize - BUFFSIZE - 1;
                *anchor=0;
            }
        }
    }
    if(fclose(file)==EOF) printf("error when closing file");
    return 1;
}