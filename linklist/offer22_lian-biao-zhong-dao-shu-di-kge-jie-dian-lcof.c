/*
 * @problem		https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
 * @solution	
 * @brief		快慢指针, 快指针先走, 慢指针后走.
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    int count = k;

    if(head == NULL) return NULL;

    while(k && slow != NULL)
    {
        slow = slow->next;
        k--;
    }

    /*
     * 如果链表长度不够k, 就返回NULL.
     * k     3    2    1     0
     * node  . -> . -> . -> NULL
     */
    if(k > 0) return NULL;

    while(slow != NULL)
    {
        slow = slow->next;
        fast = fast ->next;
    }
    return fast;
}