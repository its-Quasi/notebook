// Implementacion de segment tree con punteros

struct st {
  st* left;
  st* right;
  int l, r;
  ll value, lazy;
  st(int l, int r, vector<int>& v) : l(l), r(r), lazy(-1) {
    int m = (l + r) / 2;
    if (l != r) {
      left = new st(l, m, v);
      right = new st(m + 1, r, v);
      value = left->value + right->value;
    } else
      value = v[l];
  }
  ll get(int i, int j) {
    propagate();
    if (i > r || j < l) return 0;
    if (i <= l && j >= r) return value;
    return left->get(i, j) + right->get(i, j);
  }
  void propagate() {
    if (lazy != -1) {
      value = lazy;
      if (l != r) {
        left->lazy = lazy, right->lazy = lazy;
      }
      lazy = -1;
    }
  }

  void update(int i, int j, int x) {
    propagate();
    if (i > r || j < l) return;
    if (i <= l && j >= r) {
      lazy = x;
      propagate();
      return;
    }
    left->update(i, j, x);
    right->update(i, j, x);
    value = left->value + right->value;
  }
};