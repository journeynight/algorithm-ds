
#include <stdio.h>
const int INT_MAX = (1 << 31) - 1;
double findMedianSortedArrays(int *nums1,int nums1Size,int *nums2,int nums2Size){
    double leftMedian = findKth(nums1,0,nums1Size,nums2,0,nums2Size,(nums1Size + nums2Size + 1)/2);
    double rightMedian = findKth(nums1,0,nums1Size,nums2,0,nums2Size,(nums1Size + nums2Size + 2)/2);
    return (leftMedian + rightMedian)/2.0;
}
int findKth(int *nums1,int start1,int size1,int *nums2,int start2 ,int size2,int k){
    if(start1 >= size1)
        return nums2[k + start2 - 1];
    if(start2 >= size2)
        return nums1[k + start1 - 1];
    if(k == 1)
        return (nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2]);
    int midVal1 = (start1 + k/2 - 1 < size1) ? nums1[start1 + k/2 - 1] : INT_MAX;
    int midVal2 = (start2 + k/2 - 1 < size2) ? nums2[start2 + k/2 - 1] : INT_MAX;
    if (midVal1 < midVal2)
        return findKth(nums1,start1 + k/2,size1,nums2,start2,size2,k - k/2);
    return findKth(nums1,start1,size1,nums2,start2 + k/2 ,size2,k - k/2);
}
int main()
{
    int nums1[10] = {1,2,3,4,5,6,7,8,9,10};
    int nums2[10] = {11,12,13,14,15,16,17,18,19,20};
    double median = findMedianSortedArrays(nums1,10,nums2,10);
    printf("%f",median);
    return 0;
}
