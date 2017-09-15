/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first_Node = new ListNode(0);
        int Jinwei = 0;
        bool L1 = true;
        bool L2 = true;
        ListNode* last_Node = first_Node;
        for (int i = 0; L1||L2||Jinwei == 1 ; ++i) {
            if (L1 == false && L2 == false) {
                ListNode* next_Node = new ListNode(Jinwei);
                last_Node->next = next_Node;
                last_Node = next_Node;
                Jinwei = 0;
            } else if (L1 == false) {
                ListNode* next_Node = new ListNode(0);
                if (l2->val + Jinwei >= 10) {
                    next_Node->val = l2->val + Jinwei - 10;
                    Jinwei = 1;
                } else {
                    next_Node->val = l2->val + Jinwei;
                    Jinwei = 0;
                }
                last_Node->next = next_Node;
                last_Node = next_Node;
                if (l2->next == NULL) {
                    L2 = false;
                } else {
                    l2 = l2->next;
                }
            } else if (L2 == false) {
                ListNode* next_Node = new ListNode(0);
                if (l1->val + Jinwei >= 10) {
                    next_Node->val = l1->val + Jinwei - 10;
                    Jinwei = 1;
                } else {
                    next_Node->val = l1->val + Jinwei;
                    Jinwei = 0;
                }
                last_Node->next = next_Node;
                last_Node = next_Node;
                if (l1->next == NULL) {
                    L1 = false;
                } else {
                    l1 = l1->next;
                }
            } else {
                ListNode* next_Node = new ListNode(0);
                if (l1->val + l2->val + Jinwei >= 10) {
                    next_Node->val = l1->val + l2->val + Jinwei - 10;
                    Jinwei = 1;
                } else {
                    next_Node->val = l1->val + l2->val + Jinwei;
                    Jinwei = 0;
                }
                last_Node->next = next_Node;
                last_Node = next_Node;
                if (l2->next == NULL) {
                    L2 = false;
                } else {
                    l2 = l2->next;
                }
                if (l1->next == NULL) {
                    L1 = false;
                } else {
                    l1 = l1->next;
                }
            }
        }
        return first_Node->next;
    }
};