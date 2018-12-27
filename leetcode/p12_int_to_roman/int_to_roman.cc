#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
class Solution{
    public:
        //why static can't be removed?
        static bool cmp(const pair<int,string> &p1,const pair<int,string> &p2){
            return p1.first > p2.first;
        }
        string intToRoman(int num){
            //把map拆成key和value两个一维数组,可以避免使用map
            map<int,string> dict = {{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"},
                                    {4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"}};
            vector<pair<int,string> > vec;
            for(auto iter = dict.begin();iter != dict.end();++iter){
                vec.push_back(make_pair(iter->first,iter->second));
            }
            sort(vec.begin(),vec.end(),cmp);
            string ret = "";
            for(int i = 0;i < vec.size();++i){
                if (num >= vec[i].first){
                   int quotient = num / vec[i].first;
                   int remanider = num % vec[i].first;
                   num = remanider;
                   for(int j = 0;j < quotient;++j)
                       ret += vec[i].second;
               }
            }
            return ret;
        }
};
int main()
{
    Solution so = Solution();
    cout<<so.intToRoman(1994)<<endl;
    return 0;
}
