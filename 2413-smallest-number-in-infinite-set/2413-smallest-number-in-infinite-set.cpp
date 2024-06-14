class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> mp;

    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++){
            pq.push(i);
            mp[i]++;
        }
    }
    
    int popSmallest() {
        int ans= pq.top();
        pq.pop();

        mp.erase(ans);
        return ans;     
    }
    
    void addBack(int num) {
        if(!mp.count(num)){
            pq.push(num);
            mp[num]++;
        }
    }
};