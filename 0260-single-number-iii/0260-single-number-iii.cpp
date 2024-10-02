class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for (int num : nums) {
            xor_all ^= num; 
        }

        // Step 2: Find a bit that is set (1) in xor_all
        // This bit is different between the two unique numbers
        unsigned int diff_bit = xor_all & -(unsigned int)(xor_all);  // Get the rightmost set bit

        // Step 3: Partition the numbers into two groups and XOR within each group
        int x = 0, y = 0;
        for (int num : nums) {
            if (num & diff_bit) {
                x ^= num;  // Group 1: where the bit is set
            } else {
                y ^= num;  // Group 2: where the bit is not set
            }
        }

        // x and y are the two unique numbers
        return {x, y};
    }
};