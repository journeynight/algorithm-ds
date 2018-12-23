#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Solution{
    public:
        int maxArea(vector<int> &height){
            int size = height.size();
            int i = 0,j = size - 1;
            int maxWater = min(height[size - 1],height[0]) * (size - 1);
            while(i < j){
                if(height[i] < height[j])
                    ++i;
                else
                    --j;
                if(min(height[i],height[j]) * (j - i) > maxWater)
                    maxWater = min(height[i],height[j]) * (j - i);
            }
            return maxWater;
        }
};
int main()
{
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    Solution so = Solution();
    cout<<so.maxArea(h)<<endl;
    return 0;
}
