/*
 * @problem		https://leetcode.cn/problems/reverse-vowels-of-a-string/
 * @solution	https://leetcode.cn/problems/reverse-vowels-of-a-string/solution/fan-zhuan-zi-fu-chuan-zhong-de-yuan-yin-2bmos/
 * @brief		从左右分别开始找到元音字符即可.
 */
 
 static char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', '\0'};

int is_vowels(char chr)
{
    int i = 0;
    //printf("judge: %d\n", chr);
    while(vowels[i] != '\0')
    {
        if(chr == vowels[i])
            return 1;
        i++;
    }
    return 0;
}

char * reverseVowels(char * s){
    int left = 0, right = strlen(s) - 1;
    char temp;
    while(left < right)
    {
        while(left < right && is_vowels(s[left]) == 0)left++;
        while(right > left && is_vowels(s[right]) == 0)right--;
        //printf("%d, %d\n", left, right);

        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
		
		/* 上一轮停在元音字符， 不要忘记加一、减一。 */
        left++;
        right--;
    }
    return s;

}