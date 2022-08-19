/*
 * @problem		https://leetcode.cn/problems/merge-sorted-array/
 * @solution	https://leetcode.cn/problems/merge-sorted-array/solution/he-bing-liang-ge-you-xu-shu-zu-by-leetco-rrb0/
 * @brief		一个有序数组合并的经典示例.
 */
 
//利用临时变量进行合并,操作类似合并有序链表
void __merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int res_arr[nums1Size + nums2Size];
    int i1 = 0, i2 = 0;
    int i_res = 0;
    while(i1 < m && i2 < n)
    {
        if(nums1[i1] < nums2[i2])
        {
            res_arr[i_res++] = nums1[i1++];
        }
        else
        {
            res_arr[i_res++] = nums2[i2++];
        }
    }

    if(i1 < m )
    {
        while(i1 < m)
        {
            res_arr[i_res++] = nums1[i1++];
        }
    }
    else
    {
        while(i2 < n)
        {
            res_arr[i_res++] = nums2[i2++];
        } 
    }

    int i =0;
    while(i < i_res)
    {
        nums1[i] = res_arr[i];
        i++;
    }
}

//从后往前写nms1.
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

    int i_w = nums1Size-1;
    int i1 = m-1;
    int i2 = n-1;

    while(i1 >= 0 && i2 >= 0) //注意等于0也可以.
    {
        if(nums1[i1] > nums2[i2])
        {
            nums1[i_w--] = nums1[i1--];
        }
        else
        {
            nums1[i_w--] = nums2[i2--];
        }
    }

    if(i1 >= 0 )
    {
        while(i1 >= 0)
        {
            nums1[i_w--] = nums1[i1--];
        }
    }
    else
    {
        while(i2 >= 0)
        {
            nums1[i_w--] = nums2[i2--];
        } 
    }
}