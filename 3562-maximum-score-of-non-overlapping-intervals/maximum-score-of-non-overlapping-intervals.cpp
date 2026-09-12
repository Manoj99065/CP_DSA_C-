// class Solution {
// public:
//     vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
//     }
// };


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct Node {
        long long score = 0;
        vector<int> indices;
    };

    // Returns true if a is better than b
    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices; // lexicographically smaller
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {left, right, weight, originalIndex}
        vector<array<long long, 4>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting position
        sort(arr.begin(), arr.end(),
             [](auto &a, auto &b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];
                 return a[1] < b[1];
             });

        // Store all starting positions
        vector<long long> starts(n);

        for (int i = 0; i < n; i++)
            starts[i] = arr[i][0];

        /*
            dp[i][k] = best answer using intervals from i onwards
                       and choosing at most k intervals
        */

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for (int i = n - 1; i >= 0; i--) {

            // Find the first interval whose start > current end
            int nextIndex = upper_bound(
                starts.begin(),
                starts.end(),
                arr[i][1]
            ) - starts.begin();

            for (int k = 1; k <= 4; k++) {

                // Option 1: Don't take current interval
                Node skip = dp[i + 1][k];

                // Option 2: Take current interval
                Node take = dp[nextIndex][k - 1];

                take.score += arr[i][2];
                take.indices.push_back((int)arr[i][3]);

                // Sort indices because answer must be lexicographical
                sort(take.indices.begin(), take.indices.end());

                // Choose better option
                if (better(take, skip))
                    dp[i][k] = take;
                else
                    dp[i][k] = skip;
            }
        }

        return dp[0][4].indices;
    }
};