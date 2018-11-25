#include<stdint.h>
#include<stdlib.h>
#include <string.h>
static uint64_t MAX_NUM = (uint64_t)1 << 32;
static uint64_t BITS_PER_WORD = 32;
static uint64_t SHIFT = ((uint64_t)1 << 31) - 1;
int *bitmap =  NULL;//bitmap数组,可表示int范围内所有数
//把元素x对应的bitmap位设为1
void SetBit(int x)
{
  int elemth = (x + SHIFT) / BITS_PER_WORD;
  int bitth = (x + SHIFT) % BITS_PER_WORD;
  bitmap[elemth] |=  1 << (BITS_PER_WORD - 1 -bitth);
}
//把元素x对应的bitmap位设为0
void ClearBit(int x)
{
  int elemth = (x + SHIFT) / BITS_PER_WORD;
  int bitth = (x + SHIFT) % BITS_PER_WORD;
  bitmap[elemth] &=  ~(1 << (BITS_PER_WORD - 1 - bitth));
}
//判断元素x是否在集合中
int JudgeBit(int x)
{
  int elemth = (uint64_t)(x + SHIFT) / BITS_PER_WORD;
  int bitth = (uint64_t)(x + SHIFT) % BITS_PER_WORD;
  return (bitmap[elemth]  >> (BITS_PER_WORD - 1 - bitth)) & 0x01;
}
int *twoSum(int *nums,int numsSize,int target)
{
  bitmap =  (int *)malloc(sizeof(int) * (MAX_NUM / BITS_PER_WORD + 1));
  memset(bitmap,0,sizeof(int) * (MAX_NUM / BITS_PER_WORD + 1));
  int *ret = (int *)malloc(sizeof(int) * 2);
  ret[0] = -1;
  ret[1] = -1;
  int i;
  for(i = 0;i < numsSize; ++i)
  {
      int complement = target - nums[i];
      if(JudgeBit(complement) == 1)
      {
          int j = 0;
          while(nums[j++] != complement)
              ;//do nothing
          ret[0] = j - 1;
          ret[1] = i;
          return ret;
      }
      SetBit(nums[i]);
  }
  return ret;
}
int main()
{
  int arr[6] = {-2147483648,-123456,0,97,1000,2147483647};
  int i;
  bitmap =  (int *)malloc(sizeof(int) * (MAX_NUM / BITS_PER_WORD + 1));
  memset(bitmap,0,sizeof(int) * (MAX_NUM / BITS_PER_WORD + 1));
  for(i = 0;i < 6;++i)
    SetBit(arr[i]);
  //判断int范围内所有在集合中的数
  for(i = -2147483648;i <= 2147483647;++i)
  {
       if(1 == JudgeBit(i))
           printf("%d in set\n",i);
       //防止死死循环
       if(i == 2147483647)
            break;
  }
  //测试bimap的清除功能
  for(i = 0;i < 4;++i)
    ClearBit(arr[i]);
  for(i = -2147483648;i <= 2147483647;++i)
  {
       if(1 == JudgeBit(i))
           printf("after delete ,%d in set\n",i);
       //防止死死循环
       if(i == 2147483647)
            break;
  }
  free(bitmap);
  return 0;
}
