/*
 * @problem		https://leetcode.cn/problems/contains-duplicate-ii/
 * @solution	https://leetcode.cn/problems/contains-duplicate-ii/solution/cun-zai-zhong-fu-yuan-su-ii-by-leetcode-kluvk/
 * @brief		核心思想是哈希表存入各元素最大序号的值对.
 */
 
#include "uthash.h"

struct hash{
    int value;//用做键值.
    int index;
    UT_hash_handle hh;
};

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    struct hash *hash_head = NULL;//不知道为什么要定义在函数内部.
    struct hash *hash_temp = NULL;

    for(int i = 0; i < numsSize; i++)
    {
        HASH_FIND_INT(hash_head, &nums[i], hash_temp);
        if(hash_temp && i - hash_temp->index <= k )
        {
            return true;
        }
        else
        {
            hash_temp = malloc(sizeof(struct hash));
            hash_temp->value = nums[i];
            hash_temp->index = i;
			//注意!理论上不可以添加键值重复的哈希项.
            HASH_ADD_INT(hash_head, value, hash_temp);//但重复加入的再次获得就是最后加入的(也就是index更大的)
        }
    }
    return false;
}

