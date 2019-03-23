#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
int Unique_Paths(const int &row,const int &col){
    assert(row > 0 && col > 0);
    /*
     *dp[i][j] means numbers of paths to grid[i][j]
    */
    vector< vector<int> > dp(row ,vector<int>(col ,0));
    for(auto i = 0;i < row;++i){
        for(auto j = 0;j< col;++j){
            if(i == 0 || j ==0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j - 1];
        }
    }
    return dp[row - 1][col - 1];
}
int main()
{
    int row,col;
    while(cin>>row>>col)
        cout<<Unique_Paths(row,col)<<endl;
   return 0;
}
