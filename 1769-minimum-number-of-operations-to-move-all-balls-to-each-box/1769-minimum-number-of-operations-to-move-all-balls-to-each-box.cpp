class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> prefixSum(n, 0), suffixSum(n, 0), ans(n);

        int leftOne = 0, rightOne = 0;

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (boxes[i] == '1') leftOne++;
                if (boxes[n - i - 1] == '1') rightOne++;
                continue;
            }

            prefixSum[i] = prefixSum[i - 1] + leftOne;
            suffixSum[n - i - 1] = suffixSum[n - i] + rightOne;

            if (boxes[i] == '1') leftOne++;
            if (boxes[n - i - 1] == '1') rightOne++;
        }

        for (int i = 0; i < n; i++) {
            ans[i] = prefixSum[i] + suffixSum[i];
        }

        return ans;
    }
};