/*
 * @problem		https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
 * @solution	
 * @brief		以"跳"为单位(node1 -> node2, 这里的箭头就是一跳), 走完一遍再从另一个链表头走, 两个指针不是相遇在交点就是相遇在NULL.
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p1 = headA;
    struct ListNode *p2 = headB;

    /* 最终都会相遇, 不是交点就是NULL. */
    while(p1 != p2 ) 
    {
        /* 若一个链表走完了(走到了NULL)就从另一个链表头继续 */
        if(p1 == NULL)
        {
            p1 = headB;
        }
        else
        {
            p1 = p1->next;
        }

        if(p2 == NULL)
        {
            p2 = headA; //交换的下一次必然会重合. 画图按计数单位为跳来分析.
        }
        else
        {
             p2 = p2->next;
        }
        
    }
    return p1;
}