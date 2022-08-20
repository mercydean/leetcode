/*
 * @problem		https://leetcode.cn/problems/sort-array-by-parity/
 * @solution	https://leetcode.cn/problems/sort-array-by-parity/solution/an-qi-ou-pai-xu-shu-zu-by-leetcode-solut-gpmm/
 * @brief		核心思想是维护集合以及边界的判断.
 */
 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int left = 0, right = numsSize -1 ;
    int temp;

    //类似快排的双指针左右区间归并.
    while(left < right)
    {
        /*left维护一个偶数集合, right维护一个奇数集合.
        只要没相遇left/right就必然停在奇与偶,
        一旦相遇, 就排序完成了(这个数可以划分到任意一个区间).
        */
        while(left < right && nums[left]%2 == 0 )left++;
        while(left < right && nums[right]%2 == 1 )right--;
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }

    *returnSize = numsSize;
    return nums;
}

//另一种解法, 利用数据结构辅助: 定义额外数组和两个头尾下标，遍历原数组，将偶数从前往后放，奇数从后往前放。