class Solution {
public:

    vector<vector<int>> buildGraph(vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> graph(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < 26; i++) {
            graph[i][i] = 0;
        }
        for (int i = 0; i < cost.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            graph[from][to] = min(graph[from][to], cost[i]);
        }
        return graph;
    }

    //floyd warshall
    void pathCost(vector<vector<int>>& graph) {
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if ( graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }
    }

    long long costFunc(string& source, string& target, vector<vector<int>>& graph) {
        long long totalCost = 0;
        for (int i = 0; i < source.length(); i++) {
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';
            if (sourceChar != targetChar) {
                if (graph[sourceChar][targetChar] == INT_MAX) return -1;
                totalCost += graph[sourceChar][targetChar];
            }
        }
        return totalCost;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        auto graph = buildGraph(original, changed, cost);
        pathCost(graph);
        return costFunc(source, target, graph);
    }
};