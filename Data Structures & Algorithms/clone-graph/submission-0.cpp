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
    Node* cloneGraph(Node *orgStart) {
        if (orgStart == nullptr)
            return nullptr;
        std::unordered_map<Node*,Node*> orgToClone;
        std::queue<Node*> travQueue;
        orgToClone[orgStart] = new Node(orgStart->val);
        travQueue.push(orgStart);
        while(!travQueue.empty()) {
            Node *orgCurr = travQueue.front();
            travQueue.pop();

            //Already not copied 
            for (Node* orgNext :  orgCurr->neighbors){
                if (orgToClone.find(orgNext) ==  orgToClone.end()){	
                        orgToClone[orgNext] = new Node(orgNext->val);
                        travQueue.push(orgNext);
                    }
                    orgToClone[orgCurr]->neighbors.push_back(orgToClone[orgNext]);
                }
            }
        return orgToClone[orgStart];
    }

};
