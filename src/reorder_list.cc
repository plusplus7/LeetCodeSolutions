#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL){
            return ;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *right = slow->next;
        ListNode *tmp = NULL;
        ListNode *m_tmp = NULL;

        slow->next = NULL;
         
        ListNode *t_right = NULL;
        
        tmp = right;
        m_tmp = NULL;
        while (tmp != NULL) {
            m_tmp = tmp->next;
            tmp->next = t_right;
            t_right = tmp;
            tmp = m_tmp;
        }
        right = t_right;
        
        tmp = head;
        t_right = right;
        while (tmp != NULL && t_right != NULL) {
            m_tmp = t_right->next;
            t_right->next=tmp->next;
            tmp->next = t_right;
            t_right = m_tmp;
            tmp = tmp->next->next;
        }

    }
};

int main() {
    const int a_len = 1;
    int a[a_len] = {
    //    5,3,2,1,4
    //1,1,1,1,1
    1
    //100,10,1,1003,1002
    };
    ListNode * hd = new ListNode(a[0]);
    ListNode * tp = hd;
    for (int i=1; i<a_len; i++) {
        tp->next = new ListNode(a[i]);
        tp=tp->next;
    }
    Solution().reorderList(hd);
    ListNode * tmp = hd;
    while (tmp != NULL) {
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
}
