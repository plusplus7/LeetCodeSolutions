#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {                                
        if (head == NULL)
            return head;

        RandomListNode *top = head;
        RandomListNode *left = NULL;
        RandomListNode *right = NULL;

        while (top != NULL) {
            RandomListNode *tmp = top->next;
            top->next = new RandomListNode(top->label);
            top->next->next = tmp;
            top = top->next->next;
        }

        top = head;
        while (top != NULL) {
            if (top->random == NULL)
                top->next->random = NULL;
            else
                top->next->random = top->random->next;
            top = top->next->next;
        }
        left = head;
        right = head->next;
        RandomListNode *copy = right;

        while (right != NULL) {
            left->next = right->next;
            if (right->next != NULL)
                right->next = right->next->next;
            left = left->next;
            right = right->next;
        }

        return copy;
    }
};
int main() {
    RandomListNode *top =new RandomListNode(-1);
    RandomListNode *a = Solution().copyRandomList(top);
    cout<<a->label<<endl;
    delete a;
    delete top;
}
