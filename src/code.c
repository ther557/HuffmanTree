/**
 *  @author 2020011677 #？王渝浪
 */
 //哈夫曼编码
void Code(HTNodep T,int n){
  FILE *fid;
	fid = fopen("binary.dat","wb");
	if(fid == NULL)
	{
		printf("写出文件出错");
		return;
	}
int i;
for(i=0;i<n;i++){
  while(T){
	  T=T->leftChild;
	  fwrite(0,sizeof(double),fid);
      T=T->rightChild;
	  fwrite(1,sizeof(double),fid);
  }
  fclose(fid);
}
  
  