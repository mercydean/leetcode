/*
 * @problem		https://leetcode.cn/problems/valid-mountain-array/
 * @solution	https://leetcode.cn/problems/valid-mountain-array/solution/shuang-zhi-zhen-ji-bai-liao-100de-yong-hu-by-sdwwl/
 * @brief	    类似滑动窗口.核心是扩充递增集合. 注意迭代每个状态时对应的标志的物理含义.
 */
 
 int findLengthOfLCIS(int* nums, int numsSize){
    int cur = 0;
    int i = 0;

    int left = 0;
    int right = 0;
    int length = 0;
    int max_length = 0;

    for( i = 0; i < numsSize; i++)
    {
        left = i;
        right = i;
        
        while( i < numsSize - 1 && nums[i] < nums[i+1])
        {
            i++;
            right = i;
        }

        length = right - left + 1;
        max_length = max_length > length ? max_length : length;
    }
    return max_length;
}