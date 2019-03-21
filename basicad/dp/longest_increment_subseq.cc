#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iterator>
#include <unistd.h>
using namespace std;
const int N = 7;
/*
 *max - min + 1 should be greater than N
*/
void GenRandSeq(int min,int max,vector<int> &arr)
{
    vector<int> all(max - min + 1);
    int i;
    for(i = 0;i < max - min + 1;++i)
        all[i] = min + i;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(all.begin(),all.end(),std::default_random_engine(seed));
    copy(all.begin(),all.begin() + N,arr.begin());
}
int main()
{
   vector<int> vec(N);
   GenRandSeq(1,20,vec);
   /*
    *dp[i]记录了以vec[i]结尾的最长递增子序列的长度 
   */
   vector<int> dp(N,1);
   int i,j,ans = dp[0];
   for(i = 1;i < N;++i)
   {
        for(j = 0;j < i;++j)
        {
            if(vec[j] >= vec[i])
                continue;
            if(dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;

        }
        if(dp[i] > ans)
            ans = dp[i];
   }
   cout<<"orign vector :";
   copy(vec.begin(),vec.end(),std::ostream_iterator<int>(std::cout," "));
   cout<<endl<<"max length of LCS is :"<<ans<<endl;
   return 0;
}
