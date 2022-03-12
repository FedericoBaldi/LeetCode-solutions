// https://leetcode.com/problems/copy-list-with-random-pointer
// single map TS: O(n) SC: O(n) 
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> nodesMap;
        Node* node = head;
        while (node != NULL){
            if (nodesMap[node] == NULL){
                nodesMap[node] = new Node(node->val);
            }
            if (node->next != NULL && nodesMap[node->next] == NULL){
                nodesMap[node->next] = new Node(node->next->val);
            }
            if (node->random != NULL && nodesMap[node->random] == NULL){
                nodesMap[node->random] = new Node(node->random->val);
            }
            nodesMap[node]->next = nodesMap[node->next];
            nodesMap[node]->random = nodesMap[node->random];
            node = node->next;
        }
        return nodesMap[head];
    }
};
// double map TLE TS: O(2*n) ~ O(n) SC: O(2*n) ~ O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, int> nodesMapOld;
        unordered_map<int, Node *> nodesMapNew;
        if (head == NULL){
            return head;
        }
        Node* node = head;
        int mapIndex = 0;
        while (node != NULL){
            nodesMapOld[node] = mapIndex;
            nodesMapNew[mapIndex] = new Node(node->val);
            node = node->next;
            mapIndex++;
        }
        node = head;
        mapIndex = 0;
        while (node != NULL){
            nodesMapNew[mapIndex]->next = nodesMapNew[nodesMapOld[node->next]];
            nodesMapNew[mapIndex]->random = nodesMapNew[nodesMapOld[node->random]];
            node = node->next;
            mapIndex++;
        }
        return nodesMapNew[0];
    }
};