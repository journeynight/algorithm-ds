#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
int Unique_Paths(const vector< vector<int> > &grid){
    int row = grid.size();
    assert(row > 0);
    int col = grid[0].size();
    assert(col > 0);
    /*
     *dp[i][j] means numbers of paths to grid[i][j]
    */
    vector< vector<int> > dp(row,vector<int>(col,0));
    int firstBadPos = 0;
    while(firstBadPos < col &&  grid[0][firstBadPos] == 0)
        ++firstBadPos;
    for(auto i = 0;i < firstBadPos;++i)
        dp[0][i] = 1;
    for(auto i = firstBadPos;i < col;++i)
        dp[0][i] = 0;
    firstBadPos = 0;
    while(firstBadPos < row && grid[firstBadPos][0] == 0)
        ++firstBadPos;
    for(auto i = 0;i < firstBadPos;++i)
        dp[i][0] = 1;
    for(auto i = firstBadPos;i < row;++i)
        dp[i][0] = 0;

    for(auto i = 1;i < row;++i){
        for(auto j = 1;j< col;++j){
            if(grid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j - 1];
        }
    }
    return dp[row - 1][col - 1];
}
int main()
{
    vector< vector<int> > grid = {{0,0,0},
                                  {0,1,0},
                                  {0,0,0}};
    cout<<Unique_Paths(grid)<<endl;
    return 0;
}
