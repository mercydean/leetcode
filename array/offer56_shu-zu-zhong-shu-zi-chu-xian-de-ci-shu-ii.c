/*
 * @problem		https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
 * @solution	https://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/mian-shi-ti-56-ii-shu-zu-zhong-shu-zi-chu-xian-d-4/
 * @brief		核心思想是统计各位的次数.
 */
 
int singleNumber(int* nums, int numsSize){
    int bits[32] = {0};//记得初始化!!!!

    int bit_i, nums_i;
	
	//记录各 bits数量
    for(bit_i = 0; bit_i<32; bit_i++)
    {
        for(nums_i = 0; nums_i < numsSize; nums_i++)
        {
            if(nums[nums_i] & 1U<<bit_i)
            {
                bits[bit_i]++;
            }
        }
    }
	
	//各 bits数量模3, 剩下的就是对应的只出现一次的数.
    for(bit_i = 0; bit_i<32; bit_i++)
    {
        //printf("bit : %d has %d\n", bit_i, bits[bit_i]);
        bits[bit_i] %= 3;
    }

    int res = 0;
    
    for(bit_i = 0; bit_i<32; bit_i++)
    {
        if(bits[bit_i])
        {
            //printf("bit : %d\n", bit_i);
            res |= 1U<<bit_i;
        }
    }

    return res;
}