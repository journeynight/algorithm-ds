#include <iostream>
#include <vector>
using namespace std;
const int W = 11;
const int N = 5;
int max(int x,int y){
    return x > y ? x :y;
}
int main()
{
    vector<int> weight  = {0,5,4,7,2,6};
    vector<int> value = {0,12,3,10,3,6};
    /*
    *dp[i][j] means maxmimum return,when W = j,i items in front.
    */
    vector< vector<int> > dp(N + 1);
    int i,j;
    for(i = 0;i < N + 1;++i)
        dp[i].resize(W + 1);
    for(i = 0;i < N + 1;++i)
        dp[i][0] = 0;
    for(j = 0;j < W + 1;++j)
        dp[0][j] = 0;
    for(i = 1;i < N + 1;++i){
        for(j = 1;j < W + 1;++j){
            if(weight[i] > j){
                dp[i][j] = dp[i-1][j];
                //cout<<"in if"<<i<<","<<j<<" "<<dp[i][j]<<endl;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j - weight[i]] + value[i]);
                //cout<<"in else"<<i<<","<<j<<" "<<dp[i][j]<<endl;
           }
        }
    }
    for(i = 0;i < N + 1;++i){
        for(j = 0;j < W + 1;++j){
            cout<<dp[i][j] <<"  ";
        }
        cout<<endl;
    }
    return 0;
}
