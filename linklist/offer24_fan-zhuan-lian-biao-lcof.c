/*
 * @problem		https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/
 * @solution	
 * @brief		对每个链表项, 改变其next为前一个节点即可.
 */

struct ListNode* reverseList(struct ListNode* head){
    //初始时前一个节点为NULL,当前节点为头节点.
    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    struct ListNode *temp;

    /* 遍历各个非空的链表项cur, 改变cur->next为前一个节点prev即可.
     * 因为next会被更改所以需要寄存next作为下个待遍历的链表项.然后更新prev, 就完成了一轮迭代.
     */
    while(cur != NULL)
    {
        temp = cur->next;

        cur->next = prev;

        prev = cur;
        cur = temp;
    }
    return prev;
}