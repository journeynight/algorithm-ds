#include <iostream>
#include <map>
using namespace std;
class Solution{
    public:
        int romanToInt(string x){
            int ret = 0;
            map<char,int> dict = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
            for(auto i = 0;i < dict.size();++i){
                if(i == dict.size() - 1 || dict[x[i+1]] <= dict[x[i]])
                    ret += dict[x[i]];
                else
                    ret -= dict[x[i]];
            }
            return ret;
        }       
};
int main()
{
     Solution s = Solution();
     cout<<s.romanToInt("DCXXI")<<endl;
     return 0;
}
