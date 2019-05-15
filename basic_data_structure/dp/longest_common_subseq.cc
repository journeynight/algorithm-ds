#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str1 ;
    string str2 ;
    cout<<"input str1 and str2 :"<<endl;
    cin>>str1;
    cin>>str2;
    int len1 = str1.size(),len2 = str2.size();
    /*
     *dp[i][j]记录了str1[0...i]和str2[0...j]最长公共子序列长度
     * */
    vector< vector<int> > dp(len1);
    int i,j;
    for(i = 0;i < len1;++i)
        dp[i].resize(len2);
    for(i = 0;i < len1; ++i)
        dp[i][0] = (str1[i] == str2[0]) ? 1 : 0;
    for(j = 0;j < len2; ++j)
        dp[0][j] = (str1[0] == str2[j]) ? 1 : 0;
    for(i = 1;i < len1; ++i)
    {
        for(j = 1;j < len2; ++j)
        {
           if (str1[i] == str2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
           else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<"length of lcs:"<<dp[len1 - 1][len2 - 1]<<endl;
    return 0;
}

