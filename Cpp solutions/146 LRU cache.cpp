// https://leetcode.com/problems/lru-cache
// TC:O(1) SC:O(n)
class LRUCache {
public:
    LRUCache(int capacity) {
        if (capacity > 0){
            size = capacity;
        }
    }
    
    int get(int key) {
        int value = -1;
        if (mapList.find(key) != mapList.end()){
            value = cache[key];
            keyList.erase(mapList[key]);
            keyList.push_front(key);
            mapList[key] = keyList.begin();
        }
        return value;
    }
    
    void put(int key, int value) {
        if (mapList.find(key) != mapList.end()){
            keyList.erase(mapList[key]);
        }
        else if (keyList.size() == size){
            mapList.erase(keyList.back());
            keyList.pop_back();
        }
        keyList.push_front(key);
        mapList[key] = keyList.begin();
        
        cache[key] = value;
    }
private:
    int size;
    unordered_map <int, int> cache;
    list<int> keyList;
    unordered_map <int, list<int>::iterator> mapList;
};