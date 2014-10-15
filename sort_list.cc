#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *merge_sort(ListNode *start) {
        if (start->next == NULL)
            return start;
        
        ListNode *mid = start;
        ListNode *end = start;
        while (end->next != NULL && end->next->next != NULL) {
            end=end->next->next;
            mid=mid->next;
        }
        
        end = mid->next;
        mid->next = NULL;
        start = merge_sort(start);
        end = merge_sort(end);
        
        ListNode *t_start = start;
        ListNode *t_end = end;
        ListNode *tmp = NULL;
        ListNode *pr_start = NULL;
        while (t_start != NULL && t_end != NULL) {
            if (t_end->val <= t_start->val) {
                tmp = t_end->next;
                if (pr_start == NULL) {
                    start = t_end;
                    t_end->next = t_start;
                    pr_start = start;
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
        return start;
    }
    ListNode *sortList(ListNode *head) {
        int l_len = 0;
        ListNode *t_ptr = head;
        ListNode *tail = head;

        while (t_ptr != NULL) {
            l_len++;
            if (t_ptr->next == NULL)
                tail = t_ptr;
            t_ptr = t_ptr->next;
        }
        
        if (l_len < 2)
            return head;

        head = merge_sort(head);
        return head;
    }
};

int main() {
    const int a_len = 1;
    int a[a_len] = {
    //        5,3,2,1,4
    //1,1,1,1,1
    1
    };

    ListNode * hd = new ListNode(a[0]);
    ListNode * tp = hd;
    for (int i=1; i<a_len; i++) {
        tp->next = new ListNode(a[i]);
        tp=tp->next;
    }
    hd = Solution().sortList(hd);
}
