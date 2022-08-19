/*
 * @problem		https://leetcode.cn/problems/binary-search/
 * @solution	https://leetcode.cn/problems/binary-search/solution/by-jyd-i7xr/
 * @brief		核心思想是区间的含义和逼近方法.
 */
int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize-1;//左开右闭.
    int mid;
    while(left <= right)
    {
        mid = left + (right - left)/2;//防止溢出.
        if(nums[mid] < target)
        {
            left = mid + 1;
        }
        else if(nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

/*
 * @problem		https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
 * @solution	https://www.zhihu.com/question/36132386
 * @brief		核心思想是区间的含义和逼近方法.
 */

/*普遍理解是左闭右开的区间.循环到最后, [left, right)会移到对应的位置.
   left趋向于指向第一个目标值, right则趋向第一个出现的目标值. 
*/
int left_bound(int *nums, int numsSize, int target) {
    if (numsSize == 0) return -1;
    int left = 0;
    int right = numsSize; 
	
	/* 每次迭代实际上都是试图减半[left, right), 这可以扩充左右两类值域, 直到左右两个值域相遇, 说明解析完毕.
	[-infinity, left) [left, right) [right, +infinity].
	left== right时[left, right)为空.
	核心是[right, +infinity]的right逼近小于target的值但不超过它. 
	[-infinity, left)的left试图逼近但不超过target.
	left== right时可能会溢出边界也可能对应的值不是target所以要做检查.
	*/
	
    while (left < right) {	// 区间左右相等时, 此区间就为空没有必要继续了.
        int mid = left + (right - left) / 2;//向下取整否则不符合闭区间定义.
        if (nums[mid] == target) {
            right = mid;	// right向左逼近
        } else if (nums[mid] < target) {
            left = mid + 1;	//left向右逼近
        } else if (nums[mid] > target) {
            right = mid;	// right向左逼近
        }
    }
	
	// 序号有效性检查
	if (left == numsSize) return -1;
	// 值可能不是想要的.
	return nums[left] == target? left : -1;
}

//左闭右开的区间.
//左边界趋向于指向第一个大于目标值的值, 右边界则趋向第一个出现的目标值. 
int right_bound(int *nums, int numsSize, int target) {
    if (numsSize == 0) return -1;
    int left = 0;
    int right = numsSize; // 左闭右开.

    while (left < right) {	// 区间左右相等时, 区间就为空没有必要继续了.
        int mid = left + (right - left) / 2;//向下取整否则不符合闭区间定义.
        if (nums[mid] == target) {
            left = mid + 1;	// left向右逼近
        } else if (nums[mid] < target) {
            left = mid + 1;	//left向右逼近
        } else if (nums[mid] > target) {
            right = mid;	// right向左逼近,但不会越过target.
        }
    }
	
	// 序号有效性检查
	if (left == 0) return -1;
	// 值可能不是想要的.
	return nums[left-1] == target? left-1 : -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret = malloc(sizeof(int)*2);
    *returnSize = 2;
    ret[0] = left_bound(nums, numsSize, target);
    ret[1] = right_bound(nums, numsSize, target);
    return ret;
}
