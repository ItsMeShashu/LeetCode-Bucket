class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int total = 0;
        total = total + numBottles;
        while(numBottles >= numExchange) {      
            int rem = numBottles % numExchange;
            int div = numBottles / numExchange;
            numBottles = div + rem;
            total = total + div;
        }
        return total;
    }
};