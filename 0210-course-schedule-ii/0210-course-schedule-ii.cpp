class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        vector<int> ans, indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            auto front = q.front();
            ans.push_back(front);
            q.pop();

            for (auto neighbour : adj[front]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) q.push(neighbour);
            }
        }
        // reverse(ans.begin(), ans.end()); 
        if(ans.size() == numCourses) return ans ;
        else return vector<int>(); 
    }
};