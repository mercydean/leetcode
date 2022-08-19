/*
 * @problem		https://leetcode.cn/problems/find-pivot-index/
 * @solution	https://leetcode.cn/problems/find-pivot-index/solution/xun-zhao-shu-zu-de-zhong-xin-suo-yin-by-gzjle/
 * @brief		核心思想是数值加减判断.
 */
/* basic ver. */
int __pivotIndex(int* nums, int numsSize){
    int sum = 0;
    int i = 0;
    
    for(i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }

    int sum_left_part;
    int sum_right_part;

    for(i = 0; i < numsSize; i++)
    {
        if(i == 0)
        {
            sum_left_part = 0;
        }
        else
        {
            sum_left_part += nums[i-1];
        }

        sum_right_part = sum - (sum_left_part + nums[i]);
        
        if(sum_left_part == sum_right_part)
        {
            break;
        }
    }

    if(i == numsSize)
    {
        return -1;
    }

    return i;
}

/* a optmised ver. */
int pivotIndex(int* nums, int numsSize){
    int sum = 0;
    int i = 0;
    
    for(i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }

    int sum_left_part;
    int sum_right_part;

    for(i = 0, sum_left_part = 0; i < numsSize; i++)
    {
        if(2*sum_left_part + nums[i] == sum)
        {
            goto ok;
        }
        sum_left_part += nums[i];
    }

err:
    return -1;
ok:
    return i;
}