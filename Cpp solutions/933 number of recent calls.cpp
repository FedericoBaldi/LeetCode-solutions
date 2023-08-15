// https://leetcode.com/problems/number-of-recent-calls
// TS:O(n) SC:O(1)
class RecentCounter {
private:
    vector<int> calls;
    int callsN;
public:
    RecentCounter() {
        calls = vector<int>(1e4+1, 0);
        callsN= 0;
    }
    
    int ping(int t) {
        calls[callsN] = t;
        int previous = t - 3000;
        int index = max (0, callsN-3000);
        while (calls[index] < previous){
            index++;
        }
        callsN++;
        return callsN - index;
    }
};