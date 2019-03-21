#include <iostream>
#include <vector>
using namespace std;
/*
 *以str[pivot]为轴心向两边扩展，寻找最长回文子串
*/
int MaxPalindromeAroundPivot(const string &str,int pivot){
    int size = str.size();
    int left = pivot - 1,right = pivot + 1;
    while(right < size && str[right] == str[pivot])
        ++right;
    while(left >= 0 && right < size && str[left] == str[right]){
        --left;
        ++right;
    }
    return right - left - 1;
}
int MaxPalindrome(const string & str){
    int size = str.size();
    int ans = 0;
    for(auto i = 0;i < size;++i){
        if(ans < MaxPalindromeAroundPivot(str,i))
            ans = MaxPalindromeAroundPivot(str,i);
    }
    return ans;
}

int MaxPalindromeDp(const string &str){
    int size = str.size();
    if(size <= 1 || (size ==2 && str[0] == str[1]))
        return size;
    if(size ==2 && str[0] != str[1])
        return 1;
    vector< vector<int> >dp(size);
    int i,j;
    int ans = 1;
    for(i = 0;i < size;++i)
        dp[i].resize(size);
    for(i = 0;i < size;++i){
        dp[i][i] = 1;
        if(i < size -1 && str[i] == str[i+1]){
            dp[i][i + 1] = 1;
            ans = 2;
        }
    }
    //外层循环为字串的长度
    for(i = 3; i <= size;++i){
        //内层循环为下标
        for(j = 0;j < size - i + 1;++j){
            if(str[j] == str[j + i - 1]){
                dp[j][j + i - 1] = dp[j + 1][j + i - 2];
                if(dp[j][j + i - 1])
                        ans = ans > i ? ans :i;
           }
        }
    }
    return ans;
}
int main()
{
    string str;
    while(cin >> str){
        cout<<MaxPalindromeDp(str)<<endl;
    }
    return 0;
}
