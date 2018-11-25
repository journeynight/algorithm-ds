#! /usr/bin/python
class Solution(object):
    def twoSum(self,nums,target):
        hash_table = {}
        n = len(nums)
        for i in range(n):
            complement = target - nums[i]
            if complement in hash_table.keys():
                return[hash_table[complement],i]
            hash_table[nums[i]] = i
        return [-1,-1]                  
if __name__ == '__main__':
    obj = Solution()
    print obj.twoSum([1,2,3,4,7,20],9)
