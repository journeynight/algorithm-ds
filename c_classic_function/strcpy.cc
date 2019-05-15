#include <bits/stdc++.h>
using namespace std;
char *strcpy1(char *des,const char *src){
    assert(src && des);
    char *ret = des;
    while((*des++ = *src++) != '\0')
        ;
    return ret;
}

/*考虑内存重叠的实现*/
char *strcpy2(char *des,const char *src){
    int sz = strlen(src);
    char *ret = des;
    if(src < des && src + sz > des){
        src = src + sz - 1;
        des = des + sz - 1;
        while(sz--)
           *des-- = *src--;
    }
    else{
        while(sz--)
            *des++ = *src++;
    }
    return ret;
}

int main(){
   char src[20] = "abcdef";
   char *addr = strcpy2(src + 3,src);
   cout<<addr<<endl;
}
