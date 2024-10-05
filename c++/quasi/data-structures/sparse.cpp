//Sparse definida para maximos OJO

struct spt{
	vector<vector<int>> table;
	spt(vector<int> &v) : table(25, vector<int>(sz(v))){	
		int n = sz(v);
		for(int i = 0; i<n; i++) table[0][i] = v[i];
		for(int i = 1; (1<<i) <= n; i++){
			for(int j = 0; j+(1<<(i-1)) < n; j++){
				table[i][j] = max(table[i-1][j] , table[i-1][j + (1<<(i-1))]);
			}
		}
	}
	int query(int L, int R){
		int i = 31 - __builtin_clz((R-L)+1);
		return max(table[i][L] , table[i][R - (1<<i) + 1]);
	}
};