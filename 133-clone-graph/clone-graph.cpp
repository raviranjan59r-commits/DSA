/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void helper(Node* clone,Node* org,unordered_map<Node*,Node*>& cloned){
        
        for(auto neigh:org->neighbors){
            if(cloned.find(neigh)!=cloned.end()){//already cloned
                (clone->neighbors).push_back(cloned[neigh]);
                continue;
            }
            Node *new_neigh=new Node(neigh->val);
            clone->neighbors.push_back(new_neigh);
            cloned[neigh]=new_neigh;
            helper(new_neigh,neigh,cloned);

        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return nullptr;
        Node* clone=new Node(node->val);

        unordered_map<Node*,Node*> cloned;

        cloned[node]=clone;

        helper(clone,node,cloned);

        return clone;
    }
};