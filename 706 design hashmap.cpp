// https://leetcode.com/problems/design-hashmap
// TS:O(1) SC:O(n)
class MyHashMap {
public:
    MyHashMap() {
        hashMap = vector<int>(1e6+1, -1);
    }
    
    void put(int key, int value) {
        hashMap[key] = value;
    }
    
    int get(int key) {
        return hashMap[key];
    }
    
    void remove(int key) {
        hashMap[key] = -1;
    }
private:
    vector<int> hashMap;
};


