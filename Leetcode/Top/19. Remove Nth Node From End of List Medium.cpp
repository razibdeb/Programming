/*

19. Remove Nth Node From End of List Medium


Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?

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
    
    /*
    Runtime: 9 ms, faster than 36.75% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 10.6 MB, less than 75.09% of C++ online submissions for Remove Nth Node From End of List.
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        we will use two pointer
        distance between two pointer will be n
        one pointer will go to n steps
        then another pointer will point to start
        then both will proceed same step untill first pointer will reach end
        when first pointer will reach end, 
        second pointer will point to the item whose next will be deleted
        
        what if n is the length of the link list
        that means we have to delete the first item -> tricky
        we can add a dummy head at first
        */
        ListNode *first, *second;
        
        
        
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        
        first = dummy;
        second = dummy;
        /*
        
        0 1 2 3 4 5 6 7 8 9 NULL
                  3-> 0 
        we have to delete 3rd item
        have to point to 4th item for that which is 6
        
        */
        while(n > 0 && first != nullptr) {
            first = first->next;
            n--;
        }
        //now first points to 3 and second point to 0
        
        
        while(first->next != nullptr) {
            first = first->next;
            second = second->next;
        }
        //if it points to the last point which is not null
        if(second->next->next != nullptr) {
            second->next = second->next->next;
        } else {
            second->next = nullptr; //if needs to delete the last pointer
        }
        
        return dummy->next;
    }
};