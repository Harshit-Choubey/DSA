#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int> two_xor;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                two_xor.insert(nums[i] ^ nums[j]);
            }
        }
        
        unordered_set<int> ans;
        
        for (int x : two_xor) {
            for (int i = 0; i < n; i++) {
                ans.insert(x ^ nums[i]);
            }
        }
        
        return ans.size();
    }
};