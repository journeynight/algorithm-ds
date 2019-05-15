#include <bits/stdc++.h>
using namespace std;

int strcmp1(const char *s1,const char *s2){
    assert(s1 && s2);
    int ret = 0;
    while(!(ret = *(unsigned char *)s1 - *(unsigned char *)s2) && *s1){
        ++s1;
        ++s2;
    }
    return ret;
}

int strcmp2(const char *s1,const char *s2){
    assert(s1 && s2);
    while(*s1 && *s1 == *s2){
        ++s1;
        ++s2;
    }
    return *(unsigned char*)s1 - *(unsigned char *)(s2);
}
int strcmp3(const char *s1,const char *s2){
    assert(s1 && s2);
    while(*s1 == *s2++){
        if(*s1++ == '\0')
            return 0;
    }
    return *(unsigned char*)s1 - *(unsigned char *)(--s2);
}
int main(){
    string s1,s2;
    while(cin >> s1 >> s2){
        cout<<strcmp1(s1.c_str(),s2.c_str())<<endl;
        cout<<strcmp2(s1.c_str(),s2.c_str())<<endl;
        cout<<strcmp3(s1.c_str(),s2.c_str())<<endl;
    }
    return 0;
}
