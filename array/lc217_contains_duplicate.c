/*
 * @problem		https://leetcode.cn/problems/contains-duplicate/
 * @solution	https://leetcode.cn/problems/contains-duplicate/solution/cun-zai-zhong-fu-yuan-su-by-leetcode-sol-iedd/
 * @brief		核心思想是哈希表存入各元素最大序号的值对.
 */

struct hash{
    int key;//这个是键值, 名字可以不是key.若使用_INT后缀则需要使用int类型.
    UT_hash_handle hh;//这个是核心,有这个的结构体就能加入哈希表.
};


bool containsDuplicate(int* nums, int numsSize){
    struct hash *hash_head = NULL;//定义为全局会出错不知道原因.//被用作左值,存储内部数据结构的地址
    struct hash *temp_hash = NULL;//被用作右值,向哈希表传数值.

    for(int i = 0; i < numsSize; i++)
    {
        HASH_FIND_INT(hash_head, &nums[i], temp_hash);//根据键值获取哈希项. INT表示key是int类型,格式为表头, int 指针, 哈希项指针.
        if(temp_hash == NULL)
        {
            temp_hash = malloc(sizeof(struct hash));
            temp_hash->key = nums[i];
            HASH_ADD_INT(hash_head, key,temp_hash);//确认键值是我唯一的后, 添加哈希项INT表示键值是int类型,格式为表头, 作为键值的成员名, 哈希项指针.
        }
        else
        {
            return true;
        }
    }
    return false;
}