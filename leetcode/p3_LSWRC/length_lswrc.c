#include <stdio.h>
#include <string.h>
int max(int x,int y)
{
    if(x > y)
        return x;
    return y;
}
int lengthOfLongestSubstring(char* s) 
{
    int len = strlen(s);
    int ret = 0,i = 0,start = 0;
    int hash_table[200] = {0};
    while(i < 200)
        hash_table[i++] = -1;
    for(i = 0; i != len; ++i)
    {
        if(hash_table[s[i]] != -1)
        {
            ret = max(ret,i - start);
            start = max(start,hash_table[s[i]] + 1);
        }
        hash_table[s[i]] = i;
    }
    return max(ret,len - start);
}
int main()
{
    char *s  = "abcabcbb";
    printf("%d\n",lengthOfLongestSubstring(s));
    return 0;
}
