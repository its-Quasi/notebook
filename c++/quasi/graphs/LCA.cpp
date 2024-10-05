// NOTE: 0-INDEXED, call lca and dist whit u - 1 and v - 1

int n, m;
const int N = 1e6 + 5, MX = 25;
vector<int> depth, parent, g[N];
vector<vector<int>> jump;

void init() {
  depth.assign(n, 0);
  parent.assign(n, 0);
  jump.assign(n + 5, vector<int>(MX, 0));
  for (int i = 0; i < n + 1; i++) g[i].clear();
}

void dfs(int u, int p) {
  parent[u] = p;
  jump[u][0] = p;
  for (int j = 1; j <= MX; j++) {
    jump[u][j] = jump[jump[u][j - 1]][j - 1];
  }
  for (int &v : g[u]) {
    if (v == p) continue;
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  // deep igualation
  for (int i = MX; i >= 0; i--) {
    // depth of my i-th ancester >= depth v
    if (depth[jump[u][i]] >= depth[v]) {
      u = jump[u][i];
    }
  }
  // check if u or v are LCA
  if (u == v) return u;

  // go up both nodes
  for (int i = MX; i >= 0; i--) {
    if (jump[u][i] != jump[v][i]) {
      u = jump[u][i];
      v = jump[v][i];
    }
  }
  return jump[u][0];
}

int dist(int u, int v) {
  int common = lca(u, v);
  if (depth[u] < depth[v]) swap(u, v);
  return depth[u] + depth[v] - 2 * depth[common];
}
