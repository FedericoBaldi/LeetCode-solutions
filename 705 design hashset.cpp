// https://leetcode.com/problems/design-hashset
// TS:O(1) SC:O(n)
class MyHashSet {
public:
    MyHashSet() {
        hashset = vector<bool>(1e6 + 1, false);
    }
    
    void add(int key) {
        hashset[key] = true;
    }
    
    void remove(int key) {
        hashset[key] = false;
    }
    
    bool contains(int key) {
        return hashset[key];
    }
private:
    vector<bool> hashset;
};

