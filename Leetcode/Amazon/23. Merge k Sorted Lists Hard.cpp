/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
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
    Runtime: 30 ms, faster than 71.81% of C++ online submissions for Merge k Sorted Lists.
    Memory Usage: 13 MB, less than 94.88% of C++ online submissions for Merge k Sorted Lists.
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
        sort the vector based on first item
        start merging them from last two
        */
        if(lists.size() == 0) return nullptr;
        auto cmp =  [](const ListNode* lhs,  const ListNode* rhs) -> bool {
            if(lhs == nullptr || rhs == nullptr) return false;
            return lhs->val < rhs->val;
        };
        sort(lists.begin(), lists.end(), cmp);
        
        
        
        while(lists.size() > 1) {
            ListNode * one = lists.back();
            lists.pop_back();
            ListNode * two = lists.back();
            lists.pop_back();
            
            ListNode * head = mergeTwo(one, two);
            
            lists.push_back(head);
        }
        return lists[0];
    }
    
    ListNode * mergeTwo(ListNode * one, ListNode * two) {
        ListNode * head = nullptr, * cur = nullptr;
        
        if(one == nullptr && two != nullptr) return two;
        if(two == nullptr && one != nullptr) return one;
        
        if(one == nullptr && two == nullptr) return nullptr;
        
        while(one != nullptr && two != nullptr) {
            if(one->val < two->val) {
                if(head == nullptr) {
                    head = one;
                    cur = head;
                    one = one->next;
                } else {
                    cur->next = one;
                    cur = cur->next;
                    
                    one = one->next;
                }
            } else {
                if(head == nullptr) {
                    head = two;
                    cur = head;
                    two = two->next;
                } else {
                    cur->next = two;
                    cur = cur->next;
                    
                    two = two->next;
                }
            }
        }
        
        if(one != nullptr) {
            cur->next = one;
        } 
        if(two != nullptr) {
            cur->next = two;
        } 
        
        return head;
    }
};