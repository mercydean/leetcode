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
        //初始值为1!!不是0.
        length = 1;

        while(i<arrSize && arr[i] == num)
        {
            if(length*4 > arrSize) return num;
            length++;
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

