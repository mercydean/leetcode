/*
 * @problem		https://leetcode.cn/problems/add-strings/
 * @solution	https://leetcode.cn/problems/add-strings/solution/zi-fu-chuan-xiang-jia-by-leetcode-solution/
 * @brief		去定好数据结构+补齐思想.
 */
 
 //先设计好数据结构，再写。 一定要自己开辟空间， 不可以原地写。
static char res[10001];

//核心是从后往前加， 不足的补0.
char * addStrings(char * num1, char * num2){
    int len_1 = strlen(num1);
    int len_2 = strlen(num2);
    int res_i = 10000 - 1;

    int i_1, i_2;
    int carrier = 0;
    int sum = 0;

    int chr1, chr2;
    for(i_1 = len_1 - 1, i_2 = len_2 - 1; i_1 >= 0 || i_2 >= 0 || carrier != 0; i_1--, i_2--)
    {   

        chr1 = i_1 < 0 ? '0': num1[i_1];    
        chr2 = i_2 < 0 ? '0': num2[i_2]; 

        sum = carrier + (chr1 - '0') + (chr2 - '0');
        res[res_i--] =  sum % 10 + '0';
        carrier = sum /10;
    }
    return &res[res_i + 1];
}