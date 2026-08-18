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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy{}; // Creates a dummy node with val = 0 and nullptr
        ListNode* tail{&dummy}; // tail stores the address of dummy, since &dummy gives it

        while (list1 != nullptr && list2 != nullptr) // Continue loop while both have nodes
        // We do this cuz we are comparing both lists, and u cant compare nullptr (error)
        {
            if (list1->val <= list2->val) // list->val = (*list).val (-> is the member access through pointer operator, it dereferences the pointer which gives access to that object that it points to and .val accesses that objects val data member)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1 != nullptr)
        {
            tail->next = list1;
        }
        
        else
        {
            tail->next = list2;
        }

        return dummy.next;
    }
};
