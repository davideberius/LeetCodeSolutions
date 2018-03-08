/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void printList(struct ListNode* head) {
    struct ListNode* node = head;
    
    printf("[");
    while(node != NULL){
        printf("%d,", node->val);
        node = node->next;
    }
    printf("]\n");
}

void reverseList(struct ListNode** head) {
    struct ListNode* A = *head;
    struct ListNode* B = (*head)->next;
    struct ListNode* C = (*head)->next->next;
    
    A->next = NULL;
    while(1){
        B->next = A;
        A = B;
        B = C;
        if(C != NULL)
            C = C->next;
        else
            break;
    }
    *head = A;
}

void reorderList(struct ListNode* head) {
    if(head == NULL){
        return;
    }
    
    int count = 1, flip = 0;
    struct ListNode* node = head;
    struct ListNode* half = head;
    while(node->next != NULL){
        if(flip){
            half = half->next;
            flip = 0;
        }
        else {
            flip = 1;
        }
        node = node->next;
        count++;
    }
    //printf("Count: %d\n", count);
    
    if(count < 3)
        return;
    if(count == 3){
        node = head->next;
        head->next = node->next;
        node->next = NULL;
        head->next->next = node;
        return;
    }
    if(count == 4){
        node = head->next;
        head->next = node->next->next;
        node->next->next = NULL;
        head->next->next = node;
        return;
    }
    
    struct ListNode* temp;
    
    /* Planned new solution: reverse the second half of the list and then merge the two lists */
    /* If there are an odd number of nodes, the point at which the nodes need to move
     * is one node to the right of the center
     */
    if(count % 2 == 1){
        temp = half;
        half = half->next;
        temp->next = NULL;
    }
    /* If there are an even number of nodes, the point at which the nodes need to move
     * is two nodes to the right of the center
     */
    else {
        temp = half->next;
        half = half->next->next;
        temp->next = NULL;
    }
    
    // Reverse the list starting at the point where nodes need to move
    reverseList(&half);
    
    node = head;
    /* Merge the first half of the list with the reversed second half
     */
    while(half != NULL){
        // Point the lower half node to the beginning of the latter half and increment the node
        temp = node->next;
        node->next = half;
        node = temp;
        //Point the beginning of the later half to the next node in the first half and increment the half
        temp = half->next;
        half->next = node;
        half = temp;
    }
    return;
}
