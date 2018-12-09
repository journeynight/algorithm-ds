#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Solution{
    public:
        string longestPalindrome(string s){
            const short len = s.size();
            //dp[i][j] means s[i,...,j] is palindrome or not
            short **dp = new short *[len];
            short i,j;
            for(i = 0;i < len ; ++i)
                dp[i] = new short[len];
            //init dp tables
            for(i = 0;i < len ; ++i)
                 memset(dp[i],0,len * sizeof(short));
            for(i = 0;i < len;++i)
                for(j = 0;j < i + 1; ++j)
                    dp[i][j] = 1;
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
            for(i = 0;i < len;++i)
                delete[] dp[i];
            delete[] dp;
            return s.substr(start,maxLen);
        }
};
int main()
{
    string s = "babad";
    Solution obj = Solution();
    cout<<obj.longestPalindrome(s)<<endl;
    return 0;
}
