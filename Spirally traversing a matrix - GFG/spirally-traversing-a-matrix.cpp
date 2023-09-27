//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> result; 
        int elems = 0; 
        int totalElems = r*c; 

        int startRow = 0;
        int startCol = 0;
        int endRow = r - 1;
        int endCol = c - 1 ;

        while(elems < totalElems){
            
            for(int i = startCol; elems < totalElems && i<=endCol; i++){
                result.push_back(matrix[startRow][i]);
                elems++;
            }
            startRow++ ;

            for(int i = startRow; elems < totalElems && i<=endRow; i++){
                result.push_back(matrix[i][endCol]);
                elems++;
            }
            endCol--;

            for(int i = endCol; elems < totalElems && i>=startCol; i--){
                result.push_back(matrix[endRow][i]);
                elems++;
            }
            endRow-- ;


            for(int i = endRow; elems < totalElems && i>=startRow; i--){
                result.push_back(matrix[i][startCol]);
                elems++;
            }
            startCol++;      
        }

        return result ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends