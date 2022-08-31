/*
 * @problem		https://leetcode.cn/problems/linked-list-cycle/submissions/
 * @solution	
 * @brief		从头开始, 若有环, 则相交后一个从头开始一个从交点开始以同样速度行走会相遇在入口点. 注意处理无环的递归终止条件!
 */

bool hasCycle(struct ListNode *head) {
    /* 起始点要相同, 才能利用推导的结果求交点 */
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        /*先自增后判断, 否则第一步就会判断成功.*/
        if(fast == slow)
        {
            fast = head;
            while(fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return NULL;
}