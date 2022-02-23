# https://leetcode.com/problems/clone-graph
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node != NULL){
            Node * startingNode = node;
            Node * headCopyNode = new Node(node->val);
            map<int, Node *> nodesMap;
            nodesMap[headCopyNode->val] = headCopyNode;
            queue<Node *> nodesQueue;
            nodesQueue.push(node);

            while (!nodesQueue.empty()){
                node = nodesQueue.front();
                nodesQueue.pop();
                Node * copyNode = nodesMap[node->val];

                for (int index = 0; index < node->neighbors.size(); index++){
                    int neighborVal = node->neighbors[index]->val;
                    if (nodesMap[neighborVal] == 0){
                        nodesMap[neighborVal] = new Node(neighborVal);
                        nodesQueue.push(node->neighbors[index]);
                    }
                    copyNode->neighbors.push_back(nodesMap[neighborVal]);
                }
            }
            return headCopyNode;
        }
        else{
            return NULL;
        }
    }
};