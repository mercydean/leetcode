/*
 * @problem		https://leetcode.cn/problems/add-binary/
 * @solution	https://leetcode.cn/problems/add-binary/solution/er-jin-zhi-qiu-he-by-leetcode-solution/
 * @brief		定好数据结构+补齐思想.
 */
 //先设计好数据结构，再写。 一定要自己开辟空间， 不可以原地写。
static char res[10001];

//核心是从后往前加， 不足的补0.
char * addBinary(char * a, char * b){
    int len_1 = strlen(a);
    int len_2 = strlen(b);
    int res_i = 10000 - 1;

    int i_1, i_2;
    int carrier = 0;
    int sum = 0;

    int chr1, chr2;
    for(i_1 = len_1 - 1, i_2 = len_2 - 1; i_1 >= 0 || i_2 >= 0 || carrier != 0; i_1--, i_2--)
    {   
		//越界了就设为0, 不足的补0.
        chr1 = i_1 < 0 ? '0': a[i_1];    
        chr2 = i_2 < 0 ? '0': b[i_2]; 

        sum = carrier + (chr1 - '0') + (chr2 - '0');
        res[res_i--] =  sum % 2 + '0';//2进制需要模2.
        carrier = sum /2;//计算进位除2即可.
    }
    return &res[res_i + 1];
}
 