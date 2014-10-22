#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m >= n || head == NULL)
            return head;
        ListNode *pr = NULL;
        ListNode *tmp = head;
        m--;
        n--;
        while (m--) {
            pr = tmp;
            tmp = tmp->next;
            n--;
        }
        ListNode *n_head = tmp;
        tmp = tmp->next;
        n_head->next = NULL;
        while (n--) {
            ListNode *ori = tmp->next;
            tmp->next = n_head;
            n_head = tmp;
            tmp = ori;
        }
        if (pr == NULL)
            head = n_head;
        else
            pr->next = n_head;
        pr = n_head;
        while (pr->next != NULL) {
            pr = pr->next;
        }
        pr->next = tmp;

        return head;
    }
};
int main() {
    ListNode *head = NULL;

    int a[5] = {1,2,3,4,5};
    ListNode *tmp = head;
    for (auto i : a) {
        if (tmp == NULL) {
            head = new ListNode(i);
            tmp = head;
        } else {
            tmp->next = new ListNode(i);
            tmp = tmp->next;
        }
    }
    head = Solution().reverseBetween(head, 4,5);
    tmp = head;
    while (tmp != NULL) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
}
