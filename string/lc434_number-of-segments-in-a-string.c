/*
 * @problem		https://leetcode.cn/problems/contains-duplicate/
 * @solution	
 * @brief		注意边界即可没啥难度.
 */

 int countSegments(char * s){
    int i = 0, count = 0;

    while(s[i] != '\0' && s[i] == ' ') i++;

    while(s[i] != '\0')
    {
        while(s[i] != '\0' && s[i] != ' ')
        {
            i++;
        }
        count++;

        while(s[i] != '\0' && s[i] == ' ') i++;
    }
    return count;
}