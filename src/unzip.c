#include <Project.h>

typedef struct HUFMANTREE_STORED{
    char let;
    int son[2];
}HUFMANTREE_STORED,*HUFMANTREE_STORED_p;
int main (int argc,char **argv){
    if(argc!=3) {
        printf("Unknown error!");
        return 1;
    }
    int hf,hl,flength;
    char *huffmantree;
    char *coded;
    loadFile(argv[1],&hf,&hl,&flength,&huffmantree,&coded);
    int l = hf/HUFFMAN_BASE_BLOCK_SIZE;
    HUFMANTREE_STORED_p beg = malloc(sizeof(HUFMANTREE_STORED)*(l+1));
    for(int i = 0,offset= 0 ; i < l ; ++i,offset+=HUFFMAN_BASE_BLOCK_SIZE){
        int *p = (int*)(huffmantree+offset+1);
        beg[*p].let = huffmantree[offset];
        beg[*p].son[0] = p[1];
        beg[*p].son[1] = p[2];

    }
    int cur_loc = l;


    char *s = malloc(sizeof(char )*(flength+1));
    int cnt = 0;

    for (char *co = coded ; *co ; ++co){
        cur_loc = beg[cur_loc].
                son[*co-'0'];
        if(beg[cur_loc].let!=-1){
            s[cnt++] = beg[cur_loc].let;
            cur_loc = l;
        }
    }
    s[cnt] = 0;
    ascFileWrite(argv[2],s);

}