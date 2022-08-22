/*
 * @problem		https://leetcode.cn/problems/valid-palindrome-ii/
 * @solution	
 * @brief		贪心算法（英语：greedy algorithm），又称贪婪算法，
 *				是一种在每一步选择中都采取在当前状态下最好或最优（即最有利）的选择，
 *				从而希望导致结果是最好或最优的算法。
 */
 
bool is_palindrome(char *s, int left, int right)
{
    while(left < right)
    {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(char * s){
    int left = 0, right = strlen(s)-1;
    
    while(left < right)
    {
        if(s[left] != s[right])
        {
            if(is_palindrome(s, left+1, right) || is_palindrome(s, left, right-1))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else//s[left] == s[right] 
        {
            left++;
            right--;
        }
    }
    return true;
}