#ifndef _PROJECT_H_
#define _PROJECT_H_

void FileRead(FIle *fp,char *buff);
void BuildTree(char buff,HTNode *tree[]);
void Code(HTNode tree[],char *HuffCode[],int n);
void Uncode(char HuffCode,FILE *fp);

#endif
