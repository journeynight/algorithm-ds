#include <iostream>
#include <vector>
using namespace std;
bool IsMatch(const string &s,const string &p){
   int lens = s.size();
   int lenp = p.size();
   /*
    *dp[i][j] means whether s[0...i-1] and p[0...j-1] matches or not
   */
   vector< vector<bool> >dp(lens + 1,vector<bool>(lenp + 1,false));
   dp[0][0] = true;
   for(auto i = 1;i <= lenp;++i){
        if(p[i - 1] == '*')
           dp[0][i] = dp[0][i - 1];
   }
   for(auto i = 1;i <= lens;++i){
        for(auto j = 1;j <= lenp;++j){
            if(p[j - 1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j - 1];
            }
            else{
                dp[i][j] = (p[j-1] == '?' || p[j-1] == s[i-1]) && dp[i-1][j-1];
            }
        }
   }
   return dp[lens][lenp];
}
int main()
{
    string s,p;
    while(cin >>s >>p)
        cout<<IsMatch(s,p)<<endl;
    return 0;
}
