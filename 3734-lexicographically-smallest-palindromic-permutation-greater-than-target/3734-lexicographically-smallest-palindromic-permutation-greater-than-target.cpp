class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        // Count characters
        vector<int> left(26, 0);

        for (char c : s) {
            left[c - 'a']++;
        }

        // Middle character
        string mid = "";

        for (int i = 0; i < 26; i++) {
            if (left[i] % 2) {
                if (!mid.empty())
                    return "";

                mid = string(1, char('a' + i));
                left[i]--;
            }
        }

        /*
            Assume first half of answer is same as
            first half of target.

            Remove 2 copies because palindrome uses
            one character on left and one on right.
        */
        for (int i = 0; i < n / 2; i++) {
            left[target[i] - 'a'] -= 2;
        }

        /*
            Count how many characters are unavailable
            (negative count).
        */
        int neg = 0;

        for (int i = 0; i < 26; i++) {
            if (left[i] < 0)
                neg++;
        }

        /*
            Find largest character still available.
        */
        int leftMax = -1;

        for (int i = 25; i >= 0; i--) {
            if (left[i] > 0) {
                leftMax = i;
                break;
            }
        }

        /*
            CASE 1:
            We can make the left half exactly equal
            to target's left half.

            Then only the right half decides
            whether palindrome > target.
        */
        if (neg == 0) {

            string leftPart = target.substr(0, n / 2);

            string rightPart = leftPart;
            reverse(rightPart.begin(), rightPart.end());

            string candidate = leftPart + mid + rightPart;

            if (candidate > target)
                return candidate;
        }

        /*
            CASE 2:
            Make the first half greater than target.

            Start from right to left.
        */
        for (int i = n / 2 - 1; i >= 0; i--) {

            int b = target[i] - 'a';

            /*
                Restore the character at position i
                because we are now changing this position.
            */
            left[b] += 2;

            /*
                Update number of negative counts.
            */
            if (left[b] == 0) {
                neg--;
            }
            else if (left[b] == 2) {
                leftMax = max(leftMax, b);
            }

            /*
                If some required character is still missing,
                we cannot keep target[0...i-1] unchanged.

                Or there is no character greater than target[i].
            */
            if (neg > 0 || leftMax <= b)
                continue;

            /*
                Find the smallest available character
                greater than target[i].
            */
            int j = b + 1;

            while (j < 26 && left[j] == 0)
                j++;

            /*
                Use two copies of j:
                one for left side and one for right side.
            */
            left[j] -= 2;

            /*
                Build left half.

                Prefix stays same as target.
            */
            string ans = target.substr(0, i + 1);

            // Increase position i
            ans[i] = char('a' + j);

            /*
                Fill remaining positions with the
                smallest possible characters.
            */
            for (int k = 0; k < 26; k++) {
                ans += string(left[k] / 2, char('a' + k));
            }

            /*
                Mirror the left half.
            */
            string right = ans;
            reverse(right.begin(), right.end());

            return ans + mid + right;
        }

        return "";
    }
};