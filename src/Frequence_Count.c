//
// Created by DevilInChina on 2020/12/18.
//
#include <Project.h>
int WeightInput(char buff[],int *freq,char *lett){
    char *beg = buff;
    int cnt[256] = {0};
    while (*beg){
        ++cnt[*beg];
        ++beg;
    }
    int ret = 0 ;

    for(int i = 0 ; i < 256 ; ++i){
        if(cnt[i]!=0){
            lett[ret] = (char)i;
            freq[ret] = cnt[i];
            ++ret;
        }
    }
    return ret;
}
