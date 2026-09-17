class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        // best[i] = minimum length of a valid subarray
        // completely inside indices [0 ... i]
        vector<int> best(n, INF);

        int left = 0;
        int sum = 0;
        int answer = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }

            // [left ... right] has sum == target
            if (sum == target) {
                int len = right - left + 1;

                // Check if there is a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != INF) {
                    answer = min(answer, len + best[left - 1]);
                }

                // Best valid subarray ending at or before right
                if (right == 0)
                    best[right] = len;
                else
                    best[right] = min(best[right - 1], len);
            } 
            else {
                // No new valid subarray ending at right
                if (right > 0)
                    best[right] = best[right - 1];
            }
        }

        return answer == INF ? -1 : answer;
    }
};