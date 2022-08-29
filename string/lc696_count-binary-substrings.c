/*
 * @problem		https://leetcode.cn/problems/longest-common-prefix/
 * @solution	
 * @brief		生成一个辅助数组来写.
 */
 
 int countBinarySubstrings(char * s){
    int len = strlen(s);
    int *res = calloc(len, sizeof(int)); 
    int count_1, count_0;
    int i = 0;
    int res_i = 0;

    while(s[i] != '\0')
    {
        count_0 = 0;
        while(s[i] != '\0' && s[i] == '0') 
        {
            count_0++;
            i++;
        }
        if(count_0 != 0)
        {
           res[res_i++] =  count_0;
        }
        
        count_1 = 0;
        while(s[i] != '\0' && s[i] == '1') 
        {
            count_1++;
            i++;
        }
        if(count_1 != 0)
        {
           res[res_i++] =  count_1;
        }
    }

    int num = 0;
    for(int cur = 0; cur < res_i - 1; cur ++)
    {
        // 0011: 0011, 01, 2个
        // 011: 01, 1个
        //001: 01, 1个
        num = num + (res[cur] < res[cur+1] ? res[cur] : res[cur+1]);
        
    }

    return num;

}