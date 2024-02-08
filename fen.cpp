template<typename T>
struct Fenwick{
    int n;
    vector<T> tr;
 
    Fenwick(int n) : n(n), tr(n + 1, 0){}
 
    int lowbit(int x){
        return x & -x;
    }
 
    void modify(int x, T c){
        for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
    }
 
    void modify(int l, int r, T c){
        modify(l, c);
        if (r + 1 <= n) modify(r + 1, -c);
    }
 
    T query(int x) {
        T res = T();
        for(int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }
 
    T query(int l, int r){
        return query(r) - query(l - 1);
    }
 
    int find_first(T sum) {
        int ans = 0; T val = 0;
        for(int i = __lg(n); i >= 0; i--){
            if ((ans | (1 << i)) <= n && val + tr[ans | (1 << i)] < sum){
                ans |= 1 << i;
                val += tr[ans];
            }
        }
        return ans + 1;
    }
 
    int find_last(T sum) {
        int ans = 0; T val = 0;
        for(int i = __lg(n); i >= 0; i--){
            if ((ans | (1 << i)) <= n && val + tr[ans | (1 << i)] <= sum){
                ans |= 1 << i;
                val += tr[ans];
            }
        }
        return ans;
    }
 
};
using BIT = Fenwick<int>;