/*
 * @problem		https://leetcode.cn/problems/top-k-frequent-words/
 * @solution	https://leetcode.cn/problems/top-k-frequent-words/solution/qian-kge-gao-pin-dan-ci-by-leetcode-solu-3qk0/
 * @brief		核心是数值比较.
 */
 
 bool detectCapitalUse(char * word){
    int len = strlen(word);

    int i = len - 1;
    int upper_count = 0;

    while(i >= 0)
    {
        if(isupper(word[i]) != 0)  upper_count++;
        i--;
    }

    if(upper_count == 0 || upper_count == len || upper_count == 1 && isupper(word[0]))
        return true;

    return false;
}