#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
    UndirectedGraphNode *cloneNode(unordered_map<int, UndirectedGraphNode *> *hash, UndirectedGraphNode *node) {
        if (hash->count(node->label) != 0)
            return hash->at(node->label);

        UndirectedGraphNode *clone_node = new UndirectedGraphNode(node->label);
        clone_node->neighbors.clear();
        (*hash)[node->label] = clone_node;
        for (int i=0; i<node->neighbors.size(); i++) {
            clone_node->neighbors.push_back(cloneNode(hash, node->neighbors[i]));
        }
        return clone_node;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;

        unordered_map<int, UndirectedGraphNode *> *hash = new unordered_map<int, UndirectedGraphNode *>;
        
        hash->clear();
        UndirectedGraphNode *result = cloneNode(hash, node);
        
        delete hash;
        return result;
    }
    void visit(unordered_map<int, UndirectedGraphNode *> *hash, UndirectedGraphNode *node) {
        if (hash->count(node->label) != 0)
            return ;
        (*hash)[node->label]= NULL;
        
        cout<<node<<" "<<node->label<<endl;

        for (int i=0; !node->neighbors.empty() && i<node->neighbors.size(); i++) {
            visit(hash, node->neighbors[i]);
        }
    }
};
int main() {
    UndirectedGraphNode * node =new UndirectedGraphNode(-1);
    UndirectedGraphNode * b_node =new UndirectedGraphNode(1);
    node->neighbors.clear();
    b_node->neighbors.clear();
    node->neighbors.push_back(b_node);

    UndirectedGraphNode * asdf = Solution().cloneGraph(node);    
    cout<<asdf->label<<endl;
}
