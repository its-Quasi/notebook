struct dsu{
	vector<int> par, sz;
	int size;
	dsu(int n) : par(n), sz(n, 1) {
		size = n;
		//Cada nodo al inicio es su propio "representante"
		iota(par.begin(), par.end(), 0);
	}
	
	int find(int u){
		if(par[u] == u) return u;
		//Impedimos que el arbol se degenere
		return par[u] = find(par[u]);
	}
	
	void unite(int u, int v){
	//Busco mis representantes
		u = find(u), v = find(v);
		if(u == v) return;
		if(sz[u] > sz[v]) swap(u , v);
		par[u] = v;
		sz[v] += sz[u];
		size--;
	}
	
	bool sameSet(int u, int v){
		return find(u) == find(v);
	}
	
	int count(int u) {
		return sz[find(u)];
	}
};
