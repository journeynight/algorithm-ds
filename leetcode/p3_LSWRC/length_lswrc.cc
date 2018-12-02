#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char,int> str_map;
        int i = 0,len = s.size();
        int ret = 0,start = 0;
        for(i = 0;i != len ; ++i)
        {
            if(str_map.find(s[i]) != str_map.end())
            {
                ret = max(ret,i - start);
                start = max(start,str_map[s[i]] + 1);
            }
            str_map[s[i]] = i;
        }
        return max(ret,len - start);
    }
};
int main()
{
    string str = "a";
    Solution obj = Solution();
    cout<<obj.lengthOfLongestSubstring(str)<<endl;
    return 0;
}

