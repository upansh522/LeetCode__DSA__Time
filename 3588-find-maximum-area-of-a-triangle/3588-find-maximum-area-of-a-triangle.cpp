class Solution {
public:
    long long yf(vector<vector<int>>& coords, int left, int right) {
        int n = coords.size();
        long long ans = -1;

        for (int i = 0; i < n - 1; i++) {
            if (coords[i][0] != coords[i + 1][0]) continue;

            int temp = coords[i][1];
            while (i < n - 1 && coords[i][0] == coords[i + 1][0]) {
                i++;
            }

            int size = abs(coords[i][1] - temp);
            int curr= coords[i][0];
            ans = max(ans, max(1LL * size * abs(curr-left), 1LL * size * abs(curr-right)));
        }

        return ans;
    }

    long long xf(vector<vector<int>>& coords, int left, int right) {
        int n = coords.size();
        long long ans = -1;

        for (int i = 0; i < n - 1; i++) {
            if (coords[i][1] != coords[i + 1][1]) continue;

            int temp = coords[i][0];
            while (i < n - 1 && coords[i][1] == coords[i + 1][1]) {
                i++;
            }

            int size = abs(coords[i][0] - temp);
            int curr= coords[i][1];
            // cout<<size<<"pair"<<curr<<endl;
            ans = max(ans, max(1LL * size * abs(curr-left), 1LL * size * abs(curr-right)));
        }

        return ans;
    }

    long long maxArea(vector<vector<int>>& coords) {
        sort(coords.begin(), coords.end(), [](const vector<int>& a, const vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0];  // if y's are equal, sort by x
    return a[1] < b[1];                   // otherwise, sort by y
});

        for (auto it: coords){
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        int left = coords[0][1], right = coords.back()[1];
        long long x = (left!=right)?xf(coords, left, right):-1;

        sort(coords.begin(), coords.end());
        left = coords.back()[0], right = coords[0][0];
        long long y = (left!=right)?yf(coords, left, right):-1;

        cout<<x<<" "<<y;
        return max(x, y);
    }
};
