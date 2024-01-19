class Solution {
public:
  vector<vector<int>> allCellsDistOrder(int rows, int cols, int rc, int cc) {
    vector<vector<char>> vis(rows, vector<char>(cols, false));
    vector<vector<int>> dists;
    queue<pair<int, int>> q;
    q.push({rc, cc});
    vis[rc][cc] = true;
    dists.push_back({rc, cc});

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = x + dX[i];
        int ny = y + dY[i];
        if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || vis[nx][ny]) continue;
        q.push({nx, ny});
        vis[nx][ny] = true;
        dists.push_back({nx, ny});
      }
    }

    return dists;
  }
private:
  const int dX[4] = {-1, 0, 1, 0};
  const int dY[4] = {0, 1, 0, -1};
};
