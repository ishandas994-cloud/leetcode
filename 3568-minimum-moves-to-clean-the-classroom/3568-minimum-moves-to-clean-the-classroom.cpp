class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        vector<vector<int>> id(m, vector<int>(n, -1));

        int sr = 0, sc = 0;
        int litterCount = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    id[r][c] = litterCount++;
                }
            }
        }

        if (litterCount == 0)
            return 0;

        int target = (1 << litterCount) - 1;
        struct State {
            int r, c;
            int energy;
            int mask;
        };

        queue<State> q;

        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(
                          energy + 1, vector<bool>(1 << litterCount, false))));

        q.push({sr, sc, energy, 0});
        visited[sr][sc][energy][0] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                State cur = q.front();
                q.pop();

                int r = cur.r;
                int c = cur.c;
                int e = cur.energy;
                int mask = cur.mask;

                if (mask == target)
                    return moves;

                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = e - 1;
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }
                    int newMask = mask;

                    if (classroom[nr][nc] == 'L') {
                        int bit = id[nr][nc];
                        newMask |= (1 << bit);
                    }
                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({nr, nc, newEnergy, newMask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};