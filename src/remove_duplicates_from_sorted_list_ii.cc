#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *newHead = NULL;
        ListNode *tmp = head;
        ListNode *pr = NULL;
        ListNode *prt = NULL;

        while (tmp != NULL) {
            if (newHead == NULL) {
                if (prt != NULL && prt->val == tmp->val)
                    goto Fail;
                if (tmp->next != NULL && tmp->val == tmp->next->val)
                    goto Fail;
                newHead = tmp;
                pr = newHead;
            } else if (pr->val != tmp->val) {
                if (prt != NULL && prt->val == tmp->val)
                    goto Fail;
                if (tmp->next != NULL && tmp->val == tmp->next->val)
                    goto Fail;
                pr->next = tmp;
                pr = pr->next;
            }
Fail:
            prt = tmp;
            tmp = tmp->next;
            if (pr != NULL)
                pr->next = NULL;
        }
        return newHead;
    }
};

int main() {
    ListNode *t = new ListNode(1);
    t->next = new ListNode(1);
    t = Solution().deleteDuplicates(t);
    cout<<t->val<<" "<<endl;
}
