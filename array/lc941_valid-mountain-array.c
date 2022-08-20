/*
 * @problem		https://leetcode.cn/problems/valid-mountain-array/
 * @solution	https://leetcode.cn/problems/valid-mountain-array/solution/shuang-zhi-zhen-ji-bai-liao-100de-yong-hu-by-sdwwl/
 * @brief	    选择大于努力, 视角不同, 流程的清晰度也大不相同.从两边逼近明显要好于模拟走过一个山峰.
 */
 
/* 模拟走过一个山峰思路不清不适合使用 */
bool __validMountainArray(int* arr, int arrSize){
    int i = 0;
    int up_step;
    int down_step;

    if(arrSize <= 2) return false;

    while(i  < arrSize-1  && arr[i] < arr[i+1])
    {
        i++;
    }
    if(i == 0) return false;

    while(i < arrSize -1 && arr[i] > arr[i+1])
    {
        i++;
    }

    if(i == arrSize - 1 ) 
        return true;
    else
        return false;

}

/* 从两边出发看是否会汇合 . 相等的特殊条件需要排除(极左极右不是山峰.)*/
bool validMountainArray(int* arr, int arrSize){
    int left_peak_i = 0, right_peak_i = arrSize-1;
    
    while(left_peak_i  < arrSize-1  && arr[left_peak_i] < arr[left_peak_i+1])
    {
        left_peak_i++;
    }

    while(right_peak_i  > 0  && arr[right_peak_i] < arr[right_peak_i-1])
    {
        right_peak_i--;
    }
    
    if(left_peak_i == arrSize - 1 || right_peak_i == 0)
        return false;
    
    if(left_peak_i == right_peak_i)
    {
        return true;
    }
    return false;
}


