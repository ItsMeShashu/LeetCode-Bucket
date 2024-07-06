class Solution {
public:
    int passThePillow(int n, int time) {
        int totalTime = 2 * n - 2;
        
        int rem = time % totalTime;

        if (rem < n) {
            return rem + 1;
        } 
        else {
            return 2 * n - rem - 1;
        }
    }
};