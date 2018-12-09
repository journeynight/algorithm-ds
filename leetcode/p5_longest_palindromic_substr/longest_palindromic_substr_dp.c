#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* longestPalindrome(char *s){
    //dp[i][j] means s[i,...,j] is palindrome or not
    short **dp;
    const short len = strlen(s);
    dp = (short **)malloc(len * sizeof(short *));
    short i,j;
    for(i = 0;i < len ; ++i)
        dp[i] = (short *)malloc(len * sizeof(short));
   //init dp tables
   for(i = 0;i < len ; ++i)
       memset(dp[i],0,len * sizeof(short));
   for(i = 0;i < len;++i){
       for(j = 0;j < i + 1; ++j)
           dp[i][j] = 1;
   }
   short maxLen = 1,start = 0,end = 0;
   for(j = 1;j < len; ++j){
       for(i = 0;i < j ; ++i){
            if(s[i] != s[j]){
                continue;
            }
            else{
                dp[i][j] = dp[i + 1][j - 1];
                if(dp[i][j] == 1 && (j - i + 1 > maxLen)){
                    maxLen = j - i + 1;
                    start = i;
                    end = j;
                }
            }
       }
   }
   for(i = 0;i < len;++i){
       free(dp[i]);
       dp[i] = NULL;
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
