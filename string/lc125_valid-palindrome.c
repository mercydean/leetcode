/*
 * @problem		https://leetcode.cn/problems/valid-palindrome/
 * @solution	https://leetcode.cn/problems/valid-palindrome/solution/yan-zheng-hui-wen-chuan-by-leetcode-solution/
 * @brief		利用库函数判断是否为字符、数字.
 */
 
#include <ctype.h>
bool isPalindrome(char * s){
    int left = 0, right = strlen(s) - 1;
    char tmp;
    while(left < right)
    {
        while(left < right && !isalpha(s[left]) && !isdigit(s[left])) left++;//defined in ctype.h header file
        while(left < right && !isalpha(s[right]) && !isdigit(s[right])) right--;

        if(tolower(s[left]) != tolower(s[right])) return false; //defined in ctype.h header file

        left++;
        right--;
    }
    return true;
}