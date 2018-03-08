/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lengthA = 0, lengthB = 0;
    struct ListNode *node = headA;
    struct ListNode *lastA, *lastB;
    
    if(headA == NULL || headB == NULL)
        return NULL;
    
    while(node != NULL){
        lastA = node;
        node = node->next;
        lengthA++;
    }
    
    node = headB;
    while(node != NULL){
        lastB = node;
        node = node->next;
        lengthB++;
    }
    
    if(lastA != lastB)
        return NULL;
    
    int diff;
    if(lengthA > lengthB){
        diff = lengthA - lengthB;
        while(diff > 0){
            headA = headA->next;
            diff--;
        }
    }
    else if(lengthB > lengthA){
        diff = lengthB - lengthA;
        while(diff > 0){
            headB = headB->next;
            diff--;
        }
    }
    
    while(headA != NULL){
        if(headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}
