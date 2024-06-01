#include<bits/stdc++.h>

class Solution {
public: 

    // OPTIMIZED SOLUTION O(N^2)..................................
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp; 
        int n = grid.size() ;
        int m = grid[0].size(); 
        int count = 0 ;

        
        for(int r=0; r<n; r++){
            vector<int> temp ;
            for(int c=0; c<m; c++){
                temp.push_back(grid[r][c]); 
            }

            mp[temp]++ ;
        }

        
        for(int c=0; c<m; c++){
            vector<int> temp2 ;
            for(int r=0; r<n; r++){
                temp2.push_back(grid[r][c]); 
            }

            if(mp.find(temp2) != mp.end()){
                count += mp[temp2] ;
            }
        }

        return count ;
    }

    // // Brute Force O(N^3)......................................
    // int equalPairs(vector<vector<int>>& grid) {
    //     int n = grid.size(); 
    //     int m = grid[0].size(); 
    //     int count = 0 ;
    //     for(int r=0; r<n; r++){
    //         for(int c=0; c<m; c++){
    //             bool isEqual = true ; 

    //             for(int i=0; i<n; i++){
    //                 if(grid[r][i] != grid[i][c]){
    //                     isEqual = false; 
    //                     break ;
    //                 }                                 
    //             }

    //             if(isEqual) count++ ;

    //         }
    //     }

    //     return count ;
    // }
};