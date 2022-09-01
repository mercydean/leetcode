/*
 * @problem		https://leetcode.cn/problems/remove-element/
 * @solution	https://leetcode.cn/problems/remove-element/solution/yi-chu-yuan-su-by-leetcode-solution-svxi/
 * @brief		一个双指针与集合维护的经典示例.
 */
 
 //主动扩充左边界, 这里是左边主动的获取.其实用类似快排的左右指针也可以就是最终边界不好确定
int __removeElement(int* nums, int numsSize, int val){
    int slow = 0, fast = 0;

    /* slow 试图拓展直到numsSize-1. */
    while(slow < numsSize )
    {
        /* 每一轮, slow都是已分类完成的区间的右边界. 
         * 如果nums[slow]为符合要求的值就可以扩展(slow++),不符合则要从右区间交换, 
         * 若右区间为空或者没有符合要求的值就退出,当前slow就是最终区间的右边界
         */
        if(nums[slow] == val)
        {
            fast = slow + 1;
            while(fast < numsSize)
            {
                if(nums[fast]!=val)
                {
                    //swap
                    int temp = nums[fast];
                    nums[fast] = nums[slow];
                    nums[slow] = temp;
                    break;
                } 
                fast++;
            }
            /* 如果右边没有满足条件的val就证明当前slow是分类的边界. */
            if(fast == numsSize)
            {
                break;
            } 
        }
        slow++;
    }
    return slow;
}

 
//这个方法有点蠢.会造成重复写. 将所有符合条件的值写到数组前.left是符合条件的集合的右边界, right是遍历数组的当前位置
int removeElement(int* nums, int numsSize, int val){
    int left = 0, right = 0;
    while(right < numsSize)
    {
		//找到合适的fast.注意先做有效性检查否则会访问越界.
        while(right < numsSize && nums[right] == val)
        {
            right++;
        }
        if(right == numsSize) 
        {
            break;
        }

        nums[left] = nums[right];
        left++;
        right++;

    }
    return left;
}


//把内层的找到合适的fast这个步骤合并到外层.
int removeElement(int* nums, int numsSize, int val){
    int left = 0, right = 0;
    while(right < numsSize)
    {
        //不在循环内找到合适的fast,而是通过外层循环处理.
        if(nums[right] != val)
        {
            nums[left] = nums[right];
            left++;
        }
        right++;
    }
    return left;
}



