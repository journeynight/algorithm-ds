#include <stdio.h>
#include <stdlib.h>
#include <string.h>
short expandAroundCenter(char *s,const short low,const short high){
    short len = strlen(s);
    short left = low,right = high;
    while(left >= 0 && right < len && s[left] == s[right]){
        --left;
        ++right;
    }
    return right - left - 1;
}
char* longestPalindrome(char *s){
   short len = strlen(s);
   short len1,len2,lenMax;
   short maxLen = 1,start = 0,end = 0,i = 0;
   for(i = 0;i < len;++i){
        len1 = expandAroundCenter(s,i,i);
        len2 = expandAroundCenter(s,i,i+1);
        lenMax = len1 > len2 ? len1 : len2;
        if(lenMax > maxLen){
            start = i - (lenMax - 1) / 2;
            end = i + lenMax / 2;
            maxLen = lenMax;
        }
   }
   char *ret = (char *)malloc((maxLen + 1)* sizeof(char));
   strncpy(ret,s + start,maxLen);
   ret[maxLen] = '\0';
   return ret;
}
int main()
{
    char *s = "abcda";
    char *ret = longestPalindrome(s);
    printf("%s\n",ret);
    return 0;
}
