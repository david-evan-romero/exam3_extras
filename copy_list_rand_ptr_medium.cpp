#include <unordered_map>
using namespace std;


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> map;
        Node* curr = head;
        
        // 1. Copy nodes and store mapping (Old Node -> New Node)
        while (curr) {
            map[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // 2. Link next and random pointers using the map
        curr = head;
        while (curr) {
            // New node's next points to the new version of the old node's next
            map[curr]->next = map[curr->next];
            
            // New node's random points to the new version of the old node's random
            map[curr]->random = map[curr->random];
            
            curr = curr->next;
        }
        
        return map[head];
    }
};
