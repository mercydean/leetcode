/*
 * @problem		https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/
 * @solution	https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/solution/you-xu-shu-zu-zhong-chu-xian-ci-shu-chao-guo-25d-3/
 * @brief		核心思想是解法1.遍历 (注意初始值的选择) 解法2. 双指针.
 */
 
int __findSpecialInteger(int* arr, int arrSize){
    int length;
    int num;
    for(int i = 0; i < arrSize; )
    {
        num = arr[i];
        length = 0;

        while(i<arrSize && arr[i] == num)
        {
            length++;
            /*注意是*4判断, 浮点除法有误差: length > arrSize/4不好 */
            if(length*4 > arrSize) return num;
            i++;
        }
        
    }
    return -1;
}

int findSpecialInteger(int* arr, int arrSize){
    for (int *p = arr, *q = arr + arrSize / 4; ; p++, q++)
    if (*p == *q) return *p;
    return -1;
}

