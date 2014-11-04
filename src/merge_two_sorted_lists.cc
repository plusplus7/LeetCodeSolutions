#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 || !l2)
            return l1?l1:l2;
        ListNode *t_start = l1;
        ListNode *t_end = l2;
        ListNode *tmp = NULL;
        ListNode *pr_start = NULL;
        while (t_start != NULL && t_end != NULL) {
            if (t_end->val <= t_start->val) {
                tmp = t_end->next;
                if (pr_start == NULL) {
                    l1 = t_end;
                    t_end->next = t_start;
                    pr_start = l1;
                } else {
                    pr_start->next = t_end;
                    t_end->next = t_start;
                    pr_start = pr_start->next;
                }
                t_end = tmp;
            } else {
                pr_start = t_start;
                t_start = t_start->next;
            }
        }

        if (t_start == NULL) {
            pr_start->next=t_end;
        }
        return l1;
    }
};
int main(){}
