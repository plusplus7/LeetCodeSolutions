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
    void build_new(unordered_set<int> *hash, UndirectedGraphNode *node) {
        if (hash->count(node->label) != 0)
            return ;
        hash->insert(node->label);

        UndirectedGraphNode *clone_node = new UndirectedGraphNode(node->label);
        clone_node->neighbors.clear();
        node->neighbors.push_back(clone_node);
        for (int i=0; !node->neighbors.empty() && i<node->neighbors.size()-1; i++)
            build_new(hash, node->neighbors[i]);
    }

    void build_new_neighbors(unordered_set<int> *hash, UndirectedGraphNode *node) {
        if (hash->count(node->label) != 0)
            return ;
        hash->insert(node->label);

        UndirectedGraphNode *n_node = node->neighbors.back();
        for (int i=0; !node->neighbors.empty() && i<node->neighbors.size()-1; i++)
            n_node->neighbors.push_back(node->neighbors.at(i)->neighbors.back()); 
    }

    void rebuild_old(unordered_set<int> *hash, UndirectedGraphNode *node) {
        if (hash->count(node->label) != 0)
            return ;
        hash->insert(node->label);
        node->neighbors.pop_back();
        
        for (int i=0; !node->neighbors.empty() && i<node->neighbors.size()-1; i++) {
            rebuild_old(hash, node->neighbors[i]);
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        unordered_set<int> *hash = new unordered_set<int>;
        
        hash->clear();
        build_new(hash, node);

        hash->clear();
        build_new_neighbors(hash, node);
        
        UndirectedGraphNode *result = node->neighbors.back();
        
        hash->clear();
        rebuild_old(hash, node);

        delete hash;
        return result;
    }
    void visit(unordered_set<int> *hash, UndirectedGraphNode *node) {
        if (hash->count(node->label) != 0)
            return ;
        hash->insert(node->label);
        
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
