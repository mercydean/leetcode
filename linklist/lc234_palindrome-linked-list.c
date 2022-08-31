/*
 * @problem		https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
 * @solution	
 * @brief		复制到数组判断回文或者反转一半链表进行判断.
 */

/* 复制方法 */
bool isPalindrome(struct ListNode* head){
    int arr[100000] = {0};
    struct ListNode *cur = head;
    int arr_i = 0;

    if(head == NULL) return NULL;

    cur = head;
    arr_i =0;

    while(cur != NULL)
    {
        arr[arr_i] = cur->val;
        arr_i++;
        cur = cur->next;
    }

    //arr_i就是链表长度。
    int left = 0;
    int right = arr_i - 1;

    while(left < right)
    {
        if(arr[left] != arr[right])
            return false;
        
        left++;
        right--;
    }
    return true;
    
}

/* 反转方法，会修改原有链表所以不太好 */
bool isPalindrome(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /*slow指向第二个中间节点*/

    struct ListNode* prev = NULL;
    struct ListNode* cur = slow;
    struct ListNode* temp = NULL;

    while(cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;
        prev =  cur;
        cur = temp;
    }
    
    while(prev != NULL)
    {
        if(prev->val != head->val)
        {
            return false;
        }   
        prev = prev->next;
        head = head->next;
    }
    return true;
}