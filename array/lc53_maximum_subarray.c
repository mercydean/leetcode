/*
 * https://leetcode.cn/problems/maximum-subarray/
*/

#define max(a, b) ((a)>(b)?(a):(b))
//动态规划解法. todo:与滑动窗口口对比区别.
int maxSubArray(int* nums, int numsSize){
    int sums[numsSize];//表示以各项为结尾的最大数组和.
    int max_sum = nums[0];//必须是数组元素的值.
    int pre = 0;//初始值主要影响sums[0]若为0则第一项必然为nums[0].

    for(int i = 0; i < numsSize; i++)
    {
        sums[i] = max(nums[i], pre + nums[i]);//优化,可以不使用sums,只用一个pre.

        pre = sums[i];
        max_sum = max(sums[i], max_sum);
    }
    return max_sum;
}

