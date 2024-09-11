class Solution {
public:
    int minBitFlips(int start, int goal) {
        // First we will do XOR of start and goal.......
        // After that we will calculate the no. of set bits in the resulted number
        //  which will be equal to the no. of bits to be flipped
        int ans = start ^ goal ;
        int count = 0; 
        // Here we are calculating the no.cof set bits in ans
        for(int i=0; i<32; i++){
            if(ans & (1 << i)){
                count++; 
            }
        }

        return count; 
    }
};