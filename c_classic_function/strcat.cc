#include <bits/stdc++.h>
using namespace std;
char *strcat(char *src, const char *des){
    assert(src && des);
    char *ret = src;
    while(*src != '\0')
        ++src;
    while((*src++ = *des++) != '\0')
        ;
    return ret;
}
int main(){
    string s1,s2;
    while(cin >> s1 >> s2)
        cout<<strcat(const_cast<char *>(s1.c_str()),s2.c_str())<<endl;
    return 0;
}
