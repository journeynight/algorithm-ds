#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <iterator>
using namespace std;
void split(string str,string pattern,vector<int> &vec){
    str += pattern;
    int len1 = str.size(),len2 = pattern.size();
    int pos = 0,i = 0,index = 0;
    for(i = 0;i < len1;++i){
        pos = str.find(pattern,i);
        if(pos < len1){
            vec[index ++] = (stoi(str.substr(i,pos - i)));
            i = pos + len2 - 1;
        }
    }
    //copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
    //cout<<endl;
}
int main()
{
    int N;
    cout<<"input lines:";
    cin >> N;
    int i,j,k;
    vector< vector<int> > nums(N);
    for(i = 0;i < N;++i){
        nums[i].resize(i + 1);
    }
    string buf = "";
    cout<<"input nums line by line:"<<endl;
    cin.ignore(INT_MAX,'\n');//this line can not be deleted!
    for(i = 0;i < N;++i){
        getline(cin,buf);
        split(buf," ",nums[i]);
    }
    /*
    *dp[i][j]记录了从顶层到nums[i][j]的最短路径   
    */
    vector< vector<int> >dp(N);
    for(i = 0;i < N;++i){
        dp[i].resize(i + 1);
    }
    dp[0][0] = nums[0][0];
    for(i = 1;i < N;++i){
        for(j = 0;j < i + 1;++j)
            dp[i][j] = INT_MAX;
    }
    for(i = 1;i < N;++i){
        for(j = 0;j < i + 1;++j){
            int low = j,high = j;
            if(j > 0)
                low -= 1;
            if(j < i - 1)
                high += 1;
            if(j == i)
                high = low;
            for(k = low;k < high + 1; ++k){
                dp[i][j] = min(dp[i-1][k] + nums[i][j],dp[i][j]);
            }
        }
    }
    int ans = INT_MAX;
    for(i = 0;i < N;++i)
        ans = min(ans,dp[N - 1][i]);
    cout<<"ans = "<<ans<<endl;
    return 0;
}
