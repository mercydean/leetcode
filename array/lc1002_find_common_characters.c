/*
 * @problem		https://leetcode.cn/problems/find-common-characters/
 * @solution	https://leetcode.cn/problems/find-common-characters/solution/cha-zhao-chang-yong-zi-fu-by-leetcode-solution/
 * @brief		核心思想在于数据结构的设计.数据结构的好坏决定了程序的复杂度.
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    /* 存储每行字符串每个字符的出现频率.最多100行,每行26个字符. */
    char res_arr[100][26] = {0};
    char *p;
    int i ;
    /* 对每行i, 遍历字符, 将对应的res_arr[i][chr]++ */
    for(i = 0; i < wordsSize; i++)
    {
        p = *(words + i);
        while(*p != '\0')
        {
            res_arr[i][*p - 'a']++;
            p++;
        }
    }

    int min_num;
    int row = 0;
    char chr = 0;
    int res_i = 0;

    /*分配结果数组,最多100行字符.注意每行是只有一个字符的字符串*/
    char **res = malloc(sizeof(char *) * 100);
    int res_init_i= 0;
    while(res_init_i < 100)
    {
        res[res_init_i] = malloc(sizeof(char)*2);
        res[res_init_i][1] = '\0';
         res_init_i++;
    }

    *returnSize = 0;

    /* 遍历各个字符的出现次数,记录最小值min_num将min_num个chr写入结果数组 */
    while(chr < 26)
    {
        row = 0;
        min_num = res_arr[row][chr];

        while(row < wordsSize)
        {
            min_num = min_num < res_arr[row][chr] ? min_num : res_arr[row][chr];
            row++;
        }
        
        //printf("%c : %d\n", chr + 'a', min_num);
        
        if(min_num > 0)
        {
            *returnSize += min_num;
            while(min_num--)
            {
                res[res_i][0] = chr + 'a';
                res_i++;
            }
        }

        chr++;
    }
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    
    /* 存储当前行字符串每个字符的出现频率. */
    char chr_freq[26] = {0};
    /* 存储每个字符的历史最小出现频率.在计算第一行后初始化 */
    char chr_min[26];
    

    /* 对每行i, 遍历字符,清空chr_freq[chr], 然后将对应的chr_freq[chr]++, 最后更新chr_min */
    char *p;
    int i;
    for(i = 0; i < wordsSize; i++)
    {
        p = *(words + i);
        memset(chr_freq, 0, sizeof(chr_freq));
        while(*p != '\0')
        {
            chr_freq[*p - 'a']++;
            p++;
        }

        /*初始化chr_min*/
        if( i == 0 )
        {
            memcpy(chr_min, chr_freq, sizeof(chr_min));
        }

        /* 遍历更新chr_min[chr_i]. */
        int chr_i = 0;
        while(chr_i < 26)
        {
            chr_min[chr_i] = chr_min[chr_i] < chr_freq[chr_i] ? chr_min[chr_i] : chr_freq[chr_i];
            chr_i++;
        }
    }

    /*分配结果数组. 注意每行是只有一个字符的字符串.*/
    /*先计算分配多大*/
    int total_chr_num = 0;
    int chr_i = 0;
    while(chr_i < 26)
    {
        total_chr_num += chr_min[chr_i];
        chr_i++;
    }
    *returnSize = total_chr_num;

    /*然后分配+初始化*/
    char **ret = malloc(sizeof(char *) * total_chr_num);
    int ret_init_i= 0;
    while(ret_init_i < *returnSize)
    {
        ret[ret_init_i] = malloc(sizeof(char)*2);
        ret[ret_init_i][1] = '\0';
        ret_init_i++;
    }

    /* 将chr_min[chr]的结果写入ret[ret_i] */
    int ret_i = 0;
    char chr = 0;
    int chr_num;
    while(chr < 26)
    {
        chr_num = chr_min[chr];
        while(chr_num--)
        {
            ret[ret_i][0] = chr + 'a';
            ret_i++;
        }
        chr++;
    }

    return ret;
}