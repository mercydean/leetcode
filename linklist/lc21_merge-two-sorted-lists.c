/*
 * @problem		https://leetcode.cn/problems/merge-two-sorted-lists/
 * @solution	
 * @brief		加入两个链表里更小的节点到新链表之后.
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode head;//头节点,代码的核心,简化了程序操作!
    struct ListNode* cur = &head;

    /* 加入更小的节点到新链表之后, 如果每次只加入一个节点,  那么必然有一个链表先结束, 然后将剩余的非空链表加入新链表即可 */
    while(list1 && list2)
    {
        if(list1->val <= list2->val)
        {
            cur->next = list1;
            
            cur = cur->next;
            list1 = list1->next;
        }
        else
        {
            cur->next = list2;
            
            cur = cur->next;
            list2 = list2->next;
        }
    }

    cur->next = list1 == NULL ? list2 : list1;

    return head.next;
}