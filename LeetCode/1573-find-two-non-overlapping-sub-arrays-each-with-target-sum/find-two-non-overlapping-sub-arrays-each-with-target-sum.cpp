class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = n + 1;
        int left = 0, sum = 0;
        
        vector<int> best(n, n + 1);

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target)
                sum -= arr[left++];

            if (right > 0)
                best[right] = best[right - 1];

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && best[left - 1] != n + 1)
                    ans = min(ans, len + best[left - 1]);

                best[right] = min(best[right], len);
            }
        }

        return ans == n + 1 ? -1 : ans;
    }
};