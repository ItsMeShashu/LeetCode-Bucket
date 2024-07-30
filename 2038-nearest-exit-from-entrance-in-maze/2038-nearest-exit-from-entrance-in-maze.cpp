class Solution {
public:
    bool isValid(int n,int m,int row,int col){
        if(row>=0 and row<n and col>=0 and col<m){
            return true;
        }
        return false;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, int>> q; 
        q.push({entrance[0], entrance[1]}); 
        maze[entrance[0]][entrance[1]] = '+'; 

        int steps = 0; 
        vector<vector<int>> d = {{1, 0}, {-1, 0}, {0,1}, {0, -1}}; 
        while(!q.empty()){
            int sz = q.size() ;
            for(int i=0; i<sz; i++){
                auto top = q.front(); 
                q.pop(); 

                int x = top.first;
                int y = top.second;

                if(x==0 || x==n-1 || y==0 || y==m-1){
                    if(x != entrance[0] || y != entrance[1]){
                        return steps; 
                    }
                }

                for(int k=0; k<4; k++){
                    int nx = x + d[k][0] ;
                    int ny = y + d[k][1] ;

                    if(isValid(n, m, nx, ny) && maze[nx][ny] == '.'){
                        q.push({nx, ny}); 
                        maze[nx][ny] = '+' ;
                    }
                }
            }
            steps++ ;
        }

        return -1 ;
    }
};