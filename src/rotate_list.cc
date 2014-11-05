#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) 
            return NULL;
        ListNode *tmp = head;
        ListNode *pr = NULL;
        ListNode *n_head = NULL;
        int len = 0;
        
        while (tmp != NULL) {
            len++;
            tmp = tmp->next;
        }

        k = len-(k%len);
        if (k == len)
            return head;
        tmp = head;
        for (int i=0; i<k; i++) {
            pr = tmp;
            tmp = tmp->next;
        }

        pr->next = NULL;
        n_head = tmp;
        while (tmp != NULL) {
            pr = tmp;
            tmp = tmp->next;
        }
        pr->next = head;
        return n_head;
    }
};

int main() {
    int a[5] = {1,2,3,4,5};
    ListNode *head = new ListNode(a[0]);
    ListNode *tmp = head;
    for (int i=1; i<5; i++) {
        tmp->next = new ListNode(a[i]);
        tmp = tmp->next;
    }
    head = Solution().rotateRight(head, 2);
    tmp = head;
    while (tmp != NULL) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
}
