class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto x : freq) {
            pq.push({x.second, x.first});
        }

        string ans = "";

        pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            ans += curr.second;
            curr.first--;

            if (prev.first > 0) {
                pq.push(prev);
            }
            prev = curr;
        }

        if (ans.length() != s.length()) {
            return "";
        }

        return ans;
    }
};