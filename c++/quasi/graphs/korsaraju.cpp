const int N = 5005;
bool vis[N], degree[N];
int comp[N];
vector<int> g[N], rg[N], topo;
int SCC, n, m;

void dfs(int u) {
  vis[u] = true;
  for(int v : g[u]) {
    if(!vis[v]) dfs(v);
  }
  topo.push_back(u);
}

void rdfs(int u) {
  //save comps
  comp[u] = SCC;
  vis[u] = true;
  for(int v : rg[u]) { 
    if(!vis[v]) rdfs(v); 
  }
}

void scc(){
  for(int i = 0; i < n; i++) {
    if(!vis[i]) dfs(i);
  }
  reverse(all(topo));
  memset(vis, false, sizeof vis);
  for(auto u : topo) {
    if(!vis[u]) {
      rdfs(u);
      SCC++;
    }
  }
}


void condense() {
  for(int u = 0; u < n; u++) {
    for(int v : g[u]) { 
      int root_u = comp[u];
      int root_v = comp[v];
      if(root_u != root_v) degree[root_v] = 1;
    }
  }
}
