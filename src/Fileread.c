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
    return 1;
}
-void encode()
{
	int i=0,j,f=1;
	char str[50];
	char code[500]={'\0'};
	printf("\n请输入要编码的字符串(length<50)\n");
	scanf("%s",str);
	while(str[i]){
		if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
    		for(j=0;j<n;j++)
	    		if(str[i]==ht[j].ch){
		    		strcat(code,hcd[j].code);
			    	break;
			}
	    	i++;
		}else{
			f=0;
			break;
		}
	}
	if(f)
    	puts(code);
	else
		printf("你输入的字符串错误！\n");
	printf("按任意键后重新选择！\n");
	getch();
}

//用户输入解码字串
void  decode()
{
	char str[50];
	char code[500];
	printf("\n请输入要解码的字串(用0和1表示)\n");
	scanf("%s",code);
	if(releaseHuffCode(str,code))
		puts(str);
	else
		printf("你输入的字串错误！\n");
	
	printf("按任意键后重新选择！\n");
	getch();
}
