class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {0};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        int pos = -1;
        char bigger = 0;

        for (int i = 0; i < target.size(); i++) {
            for (int j = target[i] - 'a' + 1; j < 26; j++) {
                if (cnt[j] > 0) {
                    pos = i;
                    bigger = 'a' + j;
                    break;
                }
            }
            if (cnt[target[i] - 'a'] == 0)
                break;

            cnt[target[i] - 'a']--;
        }
        if (pos == -1)
            return "";

        int rem[26] = {0};

        for (char c : s)
            rem[c - 'a']++;

        for (int i = 0; i < pos; i++)
            rem[target[i] - 'a']--;

        string ans = target.substr(0, pos);
        for (int j = target[pos] - 'a' + 1; j < 26; j++) {
            if (rem[j] > 0) {
                ans += char('a' + j);
                rem[j]--;
                break;
            }
        }
        for (int j = 0; j < 26; j++) {
            while (rem[j] > 0) {
                ans += char('a' + j);
                rem[j]--;
            }
        }
        return ans;
    }
};