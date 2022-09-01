/*
 * @problem		https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
 * @solution	
 * @brief	    类似滑动窗口.核心是扩充递增集合. 注意迭代每个状态时对应的标志的物理含义.
 */
 
 /*以每个元素为起始扩充递增集合*/
 int findLengthOfLCIS(int* nums, int numsSize){
    int cur = 0;
    int i = 0;

    int left = 0;
    int right = 0;
    int length = 0;
    int max_length = 0;

    /* 对每个位置开始的数组进行判断. */
    for( i = 0; i < numsSize; i++)
    {
        left = i;
        right = i;
        
        /* 对每个元素,判断此元素下一个元素是否大于此元素 */
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

/*贪心算法: 记录当前连续递增序列的开始下标，遍历数组的过程中每次比较相邻元素，
 *根据相邻元素的大小关系决定是否需要重设连续递增序列的开始下标
 *然后每次遍历都记录当前最大长度.
 */

int findLengthOfLCIS(int* nums, int numsSize){
    int cur = 1;
    int left = 0;
    int max_len = 1;

    while(cur < numsSize)
    {
        /* 对于每个元素， 与其前面的进行判断， 更新left. */
        if(nums[cur] <= nums[cur-1])
        {
            left = cur;
        }
        max_len = max_len > cur - left + 1 ? max_len : cur - left + 1;
        cur++;
    }
    return max_len;
}