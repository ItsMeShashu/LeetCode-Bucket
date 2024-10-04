class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size() ; 
        sort(skill.begin(), skill.end()) ; 

        int reqSkill = skill[0] + skill[n-1] ;

        long long ans = 0 ; 

        for(int i=0; i<n/2; i++){
            if(skill[i] + skill[n-1-i] != reqSkill) return -1 ;

            ans += (long long)(skill[i] * skill[n-1-i])  ;
        } 

        return ans ;
    }
};