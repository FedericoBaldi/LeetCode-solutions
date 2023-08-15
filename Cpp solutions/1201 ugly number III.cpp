// https://leetcode.com/problems/ugly-number-iii
// TLE
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int uglyNumbers = 0;
        int currentUgly = min(a,min(b,c))-1;
        while (uglyNumbers != n){
            currentUgly++;
            if (currentUgly % a == 0 || currentUgly % b == 0 || currentUgly % c == 0){
                uglyNumbers++;
                cout << currentUgly << " ";
            }
        }
        return currentUgly;
    }
};

// TC: O(log(2e9)) SC: O(1)
typedef long long ll;
class Solution {
public:
    int countUgly(ll number, ll a, ll b, ll c){
        int count = 0;
        count += number / a;
        count += number / b;
        count += number / c;
        count -= number / lcm(a, b);
        count -= number / lcm(b, c);
        count -= number / lcm(a, c);
        count += number / lcm(a, lcm(b, c));
        return count;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        int left = 1, right = 2e9;
        int mid;
        while (left < right){
            mid = left + (right - left) / 2;
            if (countUgly(mid, a, b, c) >= n){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
