class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;

        for (auto e : employees) {
            mp[e->id] = e;
        }

        queue<int> q;
        q.push(id);

        int total = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            total += mp[curr]->importance;

            for (int sub : mp[curr]->subordinates) {
                q.push(sub);
            }
        }

        return total;
    }
};