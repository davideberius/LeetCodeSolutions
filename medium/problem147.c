/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* A simple function for printing a linked list for testing purposes
 */
void print_list(struct ListNode* head)
{
    while(head != NULL){
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("X\n");
}

/* A function for inserting a ListNode 'node' into a linked list
 * with a head 'list_head'.  Note: list_head is a double pointer
 * so it maintains any changes after leaving this function.
 *
 * This function inserts the node into the list assuming a
 * least to greatest value sorting.
 */
void insert(struct ListNode* node, struct ListNode** list_head)
{
    /* This is just for ease of use */
    struct ListNode* head = *list_head;
    /* The node belongs at the beginning, so make it the new head */
    if(node->val < head->val){
        node->next = head;
        *list_head = node;
        /* We're done here */
        return;
    }
 
    struct ListNode* temp = head;
    /* Iterate through the list until one of the nodes is greater than 'node'
     * or we are at the end of the list.
     */
    while(temp->next != NULL){
        if(temp->next->val > node->val)
            break;
        temp = temp->next;
    }
    /* Insert the node */
    node->next = temp->next;
    temp->next = node;
}

/* Performs an insertion sort on a singly linked list.
 * 
 * Complexity: O(N)
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    /* No point in continuing if the list is empty */
    if(head == NULL)
        return head;
    /* The list is already sorted if there's only one element */
    if(head->next == NULL)
        return head;
    
    /* Heads for two 'new' lists one for the sorted part and one
     * for the unsorted part.
     */
    struct ListNode* sorted_head = head;
    struct ListNode* unsorted_head = head->next;
    /* Set the initial sorted part's next to NULL so it is
     * separate from the unsorted part.
     */
    sorted_head->next = NULL;
    
    struct ListNode* node;
    /* Keep going until there's nothing left in the unsorted part */
    while(unsorted_head != NULL){
        node = unsorted_head;
        unsorted_head = unsorted_head->next;
        insert(node, &sorted_head);
    }
    return sorted_head;
}
