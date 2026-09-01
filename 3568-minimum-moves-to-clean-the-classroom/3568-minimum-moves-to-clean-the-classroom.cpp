class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startR, startC;
        vector<pair<int, int>> litter;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                }
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        if (k == 0) return 0;

        vector<vector<int>> litterIndex(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            litterIndex[litter[i].first][litter[i].second] = i;
        }

        int allCollected = (1 << k) - 1;

        vector<vector<vector<int>>> visited(
            m,
            vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        queue<tuple<int, int, int, int>> q;

        q.push({startR, startC, 0, energy});
        visited[startR][startC][0] = energy;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c, mask, remainingEnergy] = q.front();
                q.pop();

                if (mask == allCollected) {
                    return moves;
                }

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    if (remainingEnergy == 0)
                        continue;

                    int newEnergy = remainingEnergy - 1;
                    int newMask = mask;

                    if (classroom[nr][nc] == 'L') {
                        int index = litterIndex[nr][nc];
                        newMask |= (1 << index);
                    }

                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    if (visited[nr][nc][newMask] < newEnergy) {
                        visited[nr][nc][newMask] = newEnergy;
                        q.push({nr, nc, newMask, newEnergy});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};
