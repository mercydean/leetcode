/*
 * @problem		https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 * @solution	https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/solution/jian-zhi-offer-56-i-shu-zu-zhong-shu-zi-tykom/
 * @brief		核心思想是异或和掩码.
 */
 
int* singleNumbers(int* nums, int numsSize, int* returnSize){

    /* 根据题意数字必然是有两个出现两次其他只出现一次. */
    /*获取a^b. 一个数异或自身必为0, 0异或一个数结果还是这个数.*/
    int xor_of_2 = 0;//初始值必须为0.
    int i = 0;
    while(i<numsSize)
    {
       xor_of_2 ^= nums[i];
       i++;
    }

    /*获取最低位作为掩码. 结果的2个数的这个位必然不同,否则这个位不会为1. */
    /*因为两个数字不同所以必然会有一位为1.*/
    unsigned int fs_bit_mask = 1;
    while( (xor_of_2 & fs_bit_mask) == 0)
    {
        fs_bit_mask <<= 1;
    }

    /*根据掩码分类数值, 这样两个数字就会分别异或而非一起.*/
    int num1 = 0, num2 = 0;
    i = 0;
    while(i<numsSize)
    {
        if((nums[i] & fs_bit_mask) != 0)
        {
            num1 ^= nums[i];
        }
        else
        {
            num2 ^= nums[i];
        }
        i++;
    }

    *returnSize = 2;
    int *ret = malloc(sizeof(int)*2);
    *(ret) = num1;
    *(ret+1) = num2;

    return ret;
}