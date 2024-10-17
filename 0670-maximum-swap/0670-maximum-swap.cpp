class Solution {
public:

    int isMax(int maxi, vector<int>v){
        int num = 0;
        for(int i=0; i<v.size(); i++){
            num=num*10 + v[i];
        }
        if(num>maxi) return num;
        return maxi;
    }

    int maximumSwap(int num) {
        vector<int> vec;
        int num1 = num;
        while(num1){
            vec.push_back(num1%10);
            num1 = num1/10;
        }
        reverse(vec.begin(),vec.end());

        int n = vec.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                swap(vec[i],vec[j]);
                if(isMax(maxi,vec)>maxi){
                    maxi = isMax(maxi,vec);
                }
                swap(vec[i],vec[j]);
            }
        }
        return maxi;
    }
};