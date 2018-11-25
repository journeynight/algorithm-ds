#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            vector<int>  ret = {-1,-1};
            map<int,int> hash_table;
            int i = 0;
            for(int &elem : nums)
            {
                int complement = target - nums[i];
                if(hash_table.find(complement) != hash_table.end())
                {
                    ret[0] = hash_table[complement];
                    ret[1] = i;
                    return ret;
                }
                hash_table[elem] = i++;
            }
            return ret;
        }
};
int main()
{
    vector<int> arr = {-100,-73,0,2,80,7};
    Solution obj;
    vector<int> ret = obj.twoSum(arr,9);
    cout<<ret[0] <<" , "<<ret[1] <<endl;
    return 0;
}
