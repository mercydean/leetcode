/*
 * @problem		https://leetcode.cn/problems/remove-duplicate-node-lcci/
 * @solution	
 * @brief		快慢指针遍历链表.
 */
 
 struct ListNode* removeDuplicateNodes(struct ListNode* head){
    struct ListNode* cur = head;
    struct ListNode* prev = head;
    struct ListNode* next = head;
    if(head == NULL) return NULL;

    while( cur != NULL)//不可用cur->next,因为可能上一轮删除的节点导致导致cur == NULL.
    {
        //定义prev用于删除节点.
        prev = cur;
        next = cur->next;
        while(next)
        {
            if(next->val == cur->val)//删除next, next往下遍历, prev保持不动
            {
                next = next->next;
                prev->next = next;
            }
            else//prev, next往下遍历
            {
                prev = next;
                next = next->next;
            }
        }
        cur = cur->next;//进行下一轮遍历
    }
    return head;
}