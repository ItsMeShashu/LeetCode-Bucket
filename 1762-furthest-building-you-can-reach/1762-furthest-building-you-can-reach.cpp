class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size(); 
        for (int i = 0; i < n - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            
            if (diff > 0) {
                pq.push(diff);
                
                if (pq.size() > ladders) {
                    int smallestDiff = pq.top();
                    pq.pop();
                    bricks -= smallestDiff;
                    
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }
        
        return n - 1;
    }
};