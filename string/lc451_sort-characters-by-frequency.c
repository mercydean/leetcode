/*
 * @problem		https://leetcode.cn/problems/sort-characters-by-frequency/
 * @solution	
 * @brief		借助辅助的数据结构就可以完成任务.
 */
 
 char * frequencySort(char * s){
    int len = strlen(s);
    int chr_map[128] = {0};
    char *ret = malloc(sizeof(char)*len+1);
    memset(ret, 0x00, sizeof(char)*len+1);
   
    int i = 0;
    while(s[i] != '\0')
    {
        chr_map[s[i]]++;
        i++;
    }

    int ret_i = 0;
    int max = 0;
    int max_chr = 0;
    int current_num = 0;

    while( current_num < len)
    {
        max = 0;
        for(unsigned char chr = 0; chr < 128; chr++)//需要是unsigned.
        {
            if(max < chr_map[chr])
            {
               max = chr_map[chr];
               max_chr = chr;
            }
        }

        chr_map[max_chr] = 0;
        current_num += max;
        int temp = max;

        while(temp--)
        {
            ret[ret_i++] = (char)max_chr;
        }
    }
    return ret;
}