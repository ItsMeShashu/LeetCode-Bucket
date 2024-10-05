
class Solution {
public:

    bool isEqual(int arr1[26], int arr2[26]){
        for(int i=0; i<26; i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return true ;
    }
    bool checkInclusion(string s1, string s2) {
        int arr1[26] = {0};
        for(int i=0; i<s1.length(); i++){
            int index = s1[i] - 'a' ;
            arr1[index]++ ;
        }
        int i = 0;
        int windowSize = s1.length();
        int arr2[26] = {0}; 

        while(i<windowSize && i<s2.length()){
            int index = s2[i] - 'a';
            arr2[index]++;
            i++ ;
        }
        if(isEqual(arr1, arr2)) return 1 ;
        while(i<s2.length()){
            int index = s2[i] - 'a';
            arr2[index]++;
            
            index = s2[i-windowSize] - 'a';
            arr2[index]-- ;
            i++ ;
            if(isEqual(arr1, arr2))return 1 ;
        }
        return 0; 
    }
};