#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL)
            return head;
       
        ListNode *sorted = head;
        ListNode *cur = head->next;
        sorted->next = NULL;
        
        while (cur != NULL) {
            ListNode *ins = sorted;
            ListNode *prt = NULL;
            ListNode *tmp = NULL;
            ListNode *t_cur = cur->next;

            while (true) {
                if (ins == NULL) {
                    prt->next = cur;
                    cur->next = NULL;
                    break;
                }
                tmp = ins->next;
                if (ins->val >= cur->val) {
                    if (prt == NULL) {
                        cur->next = sorted;
                        sorted = cur;
                        prt = sorted;
                    } else {
                        cur->next = prt->next;
                        prt->next = cur;
                        prt = prt->next;
                    }
                    break;
                }
                prt = ins;
                ins = tmp;
            }
            cur = t_cur;
        }
        return sorted;
    }
};
int main() {
    const int a_len = 5;
    int a[a_len] = {
            5,3,2,1,4
    //1,1,1,1,1
    //1
    //100,10,1,1003,1002
    };

    ListNode * hd = new ListNode(a[0]);
    ListNode * tp = hd;
    for (int i=1; i<a_len; i++) {
        tp->next = new ListNode(a[i]);
        tp=tp->next;
    }
    hd = Solution().insertionSortList(hd);
    ListNode * tmp = hd;
    while (tmp != NULL) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
}
