class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        map<pair<int, int>, int> mp;
        
        vector<pair<int, int>> a, b;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    a.push_back({i, j});
                
                if (img2[i][j] == 1)
                    b.push_back({i, j});
            }
        }
        
        int ans = 0;
        
        for (auto p : a) {
            for (auto q : b) {
                int x = p.first - q.first;
                int y = p.second - q.second;
                
                mp[{x, y}]++;
                ans = max(ans, mp[{x, y}]);
            }
        }
        
        return ans;
    }
};