
struct node {
		
	node() = default;
};
class segtree {
	int n;	
	vector<node> st;
	
	segtree(int _n) {
		this->n = _n;
		st.resize(_n << 2);
	}
		
	node combine(node l, node r) {
		node ret;
		return ret;
	}

	void push(int id, int l, int r) {
		st[id];
		if (l != r) {
			st[id << 1], st[id]; // st[id].lz
			st[id << 1 | 1], st[id];
		}
		st[id]; // st[id].lz = 0
	}
	void build(int id, int l, int r) {
		if (l == r) {
			st[id];                            // impt  
		} else {
			int m = (l + r) >> 1;
			build(id << 1, l, m);
			build(id << 1 | 1, m + 1, r);
			st[id] = combine(st[id << 1], st[id << 1 | 1]);
		}
	}

	void upd(int id, int l, int r, int u, int v, int val) { // upd value 
		push(id, l, r);
		if (u > r || v < l) return;
		if (u <= l && r <= v) {
			st[id];    
			push(id, l, r); // impt
		} else {
			int m = (l + r) >> 1;
			upd(id << 1, l, m, u, v, val);
			upd(id << 1 | 1, m + 1, r, u, v, val);
			st[id] = combine(st[id << 1], st[id << 1 | 1]);
		}
	}

	node qry(int id, int l, int r, int u, int v) {
		push(id, l, r);
		node ret;
		if (u > r || v < l) return ret;
		if (u <= l && r <= v) return st[id];
		int m = (l + r) >> 1;
		node lf = qry(id << 1, l, m, u, v);
		node ri = qry(id << 1 | 1, m + 1, r, u, v);
		return combine(lf, ri);
	}

};
