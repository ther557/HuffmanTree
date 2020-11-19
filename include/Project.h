#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <stdio.h>
typedef struct HTNode{

}HTNode;
void FileRead(const char *file,char *buff);
void BuildTree(char buff,HTNode *tree[]);
void Code(HTNode tree[],char *HuffCode[],int n);
void Uncode(char HuffCode[],FILE *fp);
void WeightInput(char buff[],char *weight[]);

#endif
