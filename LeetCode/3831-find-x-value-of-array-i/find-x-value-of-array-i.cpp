class Solution {
    public: 
    vector<long long >resultArray(vector<int> & nums, int k){
        vector<long long > ans(k, 0);
        vector<long long > dp(k,0);
        
        for(int x : nums){
            vector<long long > ndp(k, 0);
            
            ndp[x % k]++;
            for(int r = 0; r<k; r++){
                int nr = (r * (x % k)) % k;
                ndp[nr] += dp[r];
        }
        dp  = ndp;
        for(int r =0; r < k; r++) 
        ans[r] += dp[r];
    }
    return ans;
    }
};
