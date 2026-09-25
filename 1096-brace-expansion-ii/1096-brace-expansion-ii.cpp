class Solution {
public:
    set<string> st;

    void dfs(string exp) {
        int j = exp.find('}');

        if (j == -1) {
            st.insert(exp);
            return;
        }

        int i = exp.rfind('{', j);

        string left = exp.substr(0, i);
        string middle = exp.substr(i + 1, j - i - 1);
        string right = exp.substr(j + 1);

        string part = "";

        for (char c : middle) {
            if (c == ',') {
                dfs(left + part + right);
                part = "";
            } else {
                part += c;
            }
        }

        dfs(left + part + right);
    }

    vector<string> braceExpansionII(string expression) {
        dfs(expression);

        return vector<string>(st.begin(), st.end());
    }
};