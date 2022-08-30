/*
 * @problem		https://leetcode.cn/problems/middle-of-the-linked-list/
 * @solution	
 * @brief		经典的快慢指针, 注意画图分析停止条件.
 */

/* 这里是找到两个中间节点的第二个节点, 通过画图可知, 迭代判断的条件是fast && fast->next */
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    if(head == NULL) return NULL;
    while( fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/* 如要找到两个中间节点的第一个节点, 通过画图可知, 迭代判断的条件是fast(因为步长为2所以可以不判断这个) && fast->next && fast->next->next*/