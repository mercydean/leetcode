/*
 * @problem		https://leetcode.cn/problems/longest-uncommon-subsequence-i/
 * @solution	
 * @brief		若不相同, 长度就是最长的字符串长度(相等那就是这个2个字符串的长度).
 */
 
 int findLUSlength(char * a, char * b){
    int len_a = strlen(a);
    int len_b = strlen(b);

    if(strcmp(a, b) == 0)
        return -1;

    return len_a > len_b ? len_a : len_b;
}