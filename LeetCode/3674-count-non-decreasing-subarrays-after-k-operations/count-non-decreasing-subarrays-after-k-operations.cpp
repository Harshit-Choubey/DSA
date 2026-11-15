
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), j = n - 1;
        long long ans = 0, cost = 0;
        deque<int> dq;

        for (int i = n - 1; i >= 0; i--) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                int x = dq.back();
                dq.pop_back();

                int r = dq.empty() ? j + 1 : dq.back();
                cost += 1LL * (r - x) * (nums[i] - nums[x]);
            }

            dq.push_back(i);

            while (cost > k) {
                cost -= nums[dq.front()] - nums[j];

                if (dq.front() == j)
                    dq.pop_front();

                j--;
            }

            ans += j - i + 1;
        }

        return ans;
    }
};
