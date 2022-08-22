/*
 * @problem		https://leetcode.cn/problems/longest-common-prefix/
 * @solution	
 * @brief		纵向扫描.
 */
 
 char * longestCommonPrefix(char ** strs, int strsSize){
    int count = 0;
    int col = 0;
    int prefix_len = 0;
    int quit = 0;

    while(1)
    {
        quit = 0;
        for(int i = 0; i < strsSize; i++)
        {
           if(strs[i][col] == '\0') quit = 1;
        }

        if(quit == 1)
            break;

        char cur = strs[0][col];

        quit = 0;
        for(int i = 0; i < strsSize; i++)
        {
            if(strs[i][col] != cur) quit = 1;
        }
        if(quit == 1)
            break;

        col++;
    }

    strs[0][col] = '\0';
    return strs[0];
}