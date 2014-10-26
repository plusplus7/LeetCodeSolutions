#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL)
            return NULL;

        ListNode *left = NULL, *lt = NULL;
        ListNode *right = NULL, *rt = NULL;
        
        ListNode *ht = head;

        while (ht != NULL) {
            if (ht->val >= x) {
                if (right == NULL) {
                    right = ht;
                    rt = right;
                } else {
                    rt->next = ht;
                    rt = rt->next;
                }
            } else {
                if (left == NULL) {
                    left = ht;
                    lt = left;
                } else {
                    lt->next = ht;
                    lt = lt->next;
                }
            }
            ht = ht->next;
        }
        if (right == NULL)
            return left;
        if (left == NULL) 
            return right;
        
        rt->next = NULL;
        lt->next = right;
        return left;
    }
};
int main(){}
