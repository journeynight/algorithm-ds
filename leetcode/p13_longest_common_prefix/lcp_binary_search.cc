#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
       bool isAnswer(vector<string> &strs,int endPos){
           for(auto i = 1;i < strs.size();++i){
               for(auto j = 0;j < endPos;++j){
                   if(strs[i][j] != strs[0][j])
                       return false;
               }
           }
           return true;
       }
       string longestCommonPrefix(vector<string> &strs){
           if(strs.size() == 0)
               return "";
           int minLen = strs[0].length();
           if(minLen == 0)
               return "";
           for(auto i = 1;i < strs.size();++i){
               if(strs[i].length() < minLen)
                   minLen = strs[i].length();
           }
           int low = 0,high = minLen,mid;
           while(low <= high){
               mid = (low + high) >> 1;
               if(isAnswer(strs,mid))
                   low = mid + 1;
               else
                   high = mid - 1; 
           }
           return strs[0].substr(0,(low + high) >> 1);
       }
};
int main()
{
    vector<string> strs = {"flower","flight","fly"};
    Solution so = Solution();
    cout<<so.longestCommonPrefix(strs)<<endl;
    return 0;
}
