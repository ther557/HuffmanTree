 //哈夫曼编码，通过父节点从下往上找
void createHuffCode()
{
    int i,j,length;
	FILE * fp;
	for(i=0;i<n;i++){
		length=0;
		j=i;
		//给每个字符进行编码
		while(ht[j].parent!=-1){
    		if(ht[ht[j].parent].left==j){
		    	hcd[i].code[length++]=0+'0';
			}else
		    	hcd[i].code[length++]=1+'0';
			j=ht[j].parent;
		}

		hcd[i].start=hcd[i].code[length-1]-'0';
		hcd[i].code[length]='\0';
		reverse(hcd[i].code);
	}
	//把hcd字符编码写入文件document/code.txt中
	if((fp=fopen("document/code.txt","w"))==NULL){
		printf("can not open the file character.txt");
		exit(0);
	}
    for(i=0;i<n;i++){
		fputc(ht[i].ch,fp);
		fputs("    ",fp);
		fputs(hcd[i].code,fp);
		fputc('\n',fp);
	}
	if(fclose(fp)){
		printf("can not close the file character.txt");
		exit(0);
	}
}

//哈夫曼解码，每次都从根节点开始搜索
int releaseHuffCode(char *str,char* code)
{
	int root=2*n-2;
	int length=0,i=0;
	while(code[i]){
		if(code[i]=='0'+0)
			root=ht[root].left;
		else if(code[i]=='0'+1)
			root=ht[root].right;
		else
			return 0;
		if(ht[root].left==-1 && ht[root].right==-1){
	    	str[length++]=ht[root].ch;
			root=2*n-2;
		}
		i++;
	}
	str[length]='\0';
	if(root==2*n-2)
		return 1;
	return 0;
}
