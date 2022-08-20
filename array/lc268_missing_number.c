/*
 * @problem		https://leetcode.cn/problems/missing-number/
 * @solution	https://leetcode.cn/problems/missing-number/solution/diu-shi-de-shu-zi-by-leetcode-solution-naow/
 * @brief		核心思想是数学将和求差, 也可以和完整的序列异或消去出现的值.
 */
 int missingNumber(int* nums, int numsSize){
    //等差数列求和
    int ideal_sum = (0+numsSize)*(numsSize+1)/2;
    
    int sum = 0;

    //数字不重复.
    int i = 0;
    while(i < numsSize)
    {
        sum += nums[i];
        i++;
    }
    return ideal_sum - sum;
}

//异或此数组和完整的序列就可以获得对应值.(出现两次的被消去.)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            res ^= nums[i];
        }
        for (int i = 0; i <= n; i++) {
            res ^= i;
        }
        return res;
    }
};