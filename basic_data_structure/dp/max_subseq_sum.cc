#include <iostream>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>
using namespace std;
const int N = 10;
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
int Max_SubSeq_Sum(vector<int> &arr)
{
    /*
     *dp[i] means max sum of subsequences ending in arr[i]
    */
    int *dp = new int[N];
    dp[0] = arr[0];
    int ans = dp[0];
    for(int i = 1;i < N;++i){
        if(dp[i-1] < 0)
            dp[i] = arr[i];
        else
            dp[i] = dp[i - 1] + arr[i];
        if(dp[i] > ans)
            ans = dp[i];
    }
    delete [] dp;
    return ans;

}
int main()
{
    vector<int> arr(N,0);
    GenRandSeq(-10,10,arr);
    cout<<"origin arr :";
    copy(arr.begin(),arr.end(),std::ostream_iterator<int>(std::cout," "));
    cout<<endl<<"Max SubSeq Sum :"<<Max_SubSeq_Sum(arr)<<endl;
    return 0;
}
