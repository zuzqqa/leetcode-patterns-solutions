/**
 * @brief Problem Statement
 * 
 * You are given the heads of two sorted linked lists, list1 and list2.
 * Merge the two lists into one sorted list by splicing together the nodes 
 * of the first two lists. The merged list should be returned starting from 
 * the head node.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    /**
     * @brief Merges two sorted linked lists into one sorted linked list.
     * 
     * This method takes the head pointers of two sorted linked lists, 
     * compares the values of their nodes, and merges them into a new 
     * sorted linked list by rearranging the original nodes.
     * 
     * @param list1 The head of the first sorted linked list.
     * @param list2 The head of the second sorted linked list.
     * @return ListNode* The head of the merged sorted linked list.
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr)
            return nullptr;
        
        if(list1 == nullptr)
            return list2;
        else if(list2 == nullptr)
            return list1;

        ListNode* head = nullptr;
        
        if(list1->val < list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        
        ListNode* current = head;

        while(true){
            if(list1 == nullptr && list2 == nullptr)
                return head;
            
            if(list1 == nullptr){
                current->next = list2;
                return head;
            }
            else if(list2 == nullptr){
                current->next = list1;
                return head;
            }

            if(list1->val < list2->val){
                current->next = list1;
                list1 = list1->next;
            }
            else{
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }

        return head;
    }
};
