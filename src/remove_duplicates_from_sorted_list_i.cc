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

        while (tmp != NULL) {
            if (newHead == NULL) {
                newHead = tmp;
                pr = newHead;
            } else if (pr->val != tmp->val) {
                pr->next = tmp;
                pr = pr->next;
            }
            tmp = tmp->next;
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
