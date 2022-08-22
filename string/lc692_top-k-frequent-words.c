/*
 * @problem		https://leetcode.cn/problems/top-k-frequent-words/
 * @solution	https://leetcode.cn/problems/top-k-frequent-words/solution/qian-kge-gao-pin-dan-ci-by-leetcode-solu-3qk0/
 * @brief		核心是排序.
 */
 
 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <stdlib.h>

 struct topk_table
 {
    int num;
    char words[20];
 };

 int cmp( const void * a,  const void *b)
 {
    // qsort()(from small to large) expects the comparison function to return:
   // 
   //    a negative result if val1 < val2
   //    0 if val1 == val2
   //    a positive result if val1 > val2
   const struct topk_table * f = (const struct topk_table *)a;
   const struct topk_table * l = (const struct topk_table *)b;

   if(f->num != l->num)
   {
       return -(f->num - l->num);//这里是希望从大到小排所以要反过来.
这里是希望从大到小排所以要反过来.
   }
   else
   {
       return strcmp(f->words, l->words);
   }
 }

 int cmp_num( const void * a,  const void *b)
 {
    // qsort()(from small to large) expects the comparison function to return:
   // 
   //    a negative result if val1 < val2
   //    0 if val1 == val2
   //    a positive result if val1 > val2
   const struct topk_table * f = (const struct topk_table *)a;
   const struct topk_table * l = (const struct topk_table *)b;

    return -(((const struct topk_table *)a)->num - ((const struct topk_table *)b)->num);//这里是希望从大到小排所以要反过来.
 }

 int cmp_str(const void * a,  const void *b)
 {
    return strcmp(((const struct topk_table *)a)->words, ((const struct topk_table *)b)->words); //切勿只判断第一个字符.
 }

char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    struct topk_table * topk_table = calloc(wordsSize, sizeof(struct topk_table));//参数和malloc不一样.当然可以malloc后memset清0.
    char **ret = malloc(sizeof(char *) * k);
    *returnSize = k;
    
    int i = 0;
    int table_index = 0;
    int f_add = 1;
    for(i = 0; i < wordsSize; i++)
    {
        f_add = 1;
        for(int t_i = 0; t_i < table_index; t_i++)
        {
            if(strcmp(words[i], topk_table[t_i].words) == 0)
            {
                f_add = 0;
                topk_table[t_i].num++;
                break;
            }
        }
        if(f_add == 1)
        {
            topk_table[table_index].num = 1;
            strcpy(topk_table[table_index].words, words[i]);
            table_index++;
        }
    }
	
	//推荐使用
    qsort(topk_table, table_index, sizeof(struct topk_table), cmp);

    //qsort不稳定但是第二次排序是依据num, 测试用例没有相同的num所以没影响.
    //qsort(topk_table, table_index, sizeof(struct topk_table), cmp_str);//长度不可以是table_index
    //qsort(topk_table, table_index, sizeof(struct topk_table), cmp_num); //#include <stdlib.h>

    int ret_i = 0;
    int table_i = 0;

    while(k--)
    {
        ret[ret_i] = calloc(sizeof(topk_table[table_i].words)+1, sizeof(char));
        strcpy(ret[ret_i], topk_table[table_i].words);
        ret_i++;
        table_i++;
    }
    return ret;
}