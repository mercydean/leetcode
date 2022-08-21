/*
 * @problem		https://leetcode.cn/problems/reverse-words-in-a-string-iii/
 * @solution	https://leetcode.cn/problems/reverse-words-in-a-string-iii/solution/fan-zhuan-zi-fu-chuan-zhong-de-dan-ci-iii-by-lee-2/
 * @brief		反转每个单词即可， 关键在于循环的设计.
 */
 int reverse(char * s, int start, int end)
{
    char temp;
    while(start < end)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
    return 0;
}
char * reverseWords(char * s){
    int start = 0, end = 0;
    int i = 0;
    int length = strlen(s);

    while(i < length)//注意不要s[i] != \0', 否则最后一轮会越界。
    {
        start = i;
        while(s[i] != '\0' && s[i] != ' ') i++;
        end = i - 1;
        reverse(s, start, end);
        i++;//skip the blank char.
    }
    return s;
}