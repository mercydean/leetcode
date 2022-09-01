/*
 * @problem		https://leetcode.cn/problems/number-of-segments-in-a-string/
 * @solution	
 * @brief		注意边界即可没啥难度.
 */

 int countSegments(char * s){
    int i = 0, count = 0;
    //去除前导空格
    while(s[i] != '\0' && s[i] == ' ') i++;

    while(s[i] != '\0')
    {
        //遍历非空格
        while(s[i] != '\0' && s[i] != ' ')
        {
            i++;
        }
        count++;

        //去除下一轮的前导空格
        while(s[i] != '\0' && s[i] == ' ') i++;
    }
    return count;
}