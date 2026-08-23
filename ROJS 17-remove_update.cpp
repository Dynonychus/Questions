#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 100005;

vector<int> tree(4 * mn, 0);
vector<int> lazy(4 * mn);

void push(int n, int a, int b) {
    if(a == b) {
        lazy[n] = 0;
        
        return;
    }
    
    tree[2*n] += lazy[n];
    lazy[2*n] += lazy[n];
    
    tree[2*n + 1] += lazy[n];
    lazy[2*n + 1] += lazy[n];
    
    lazy[n] = 0;
}

void update(int n, int a, int b, int qa, int qb, int val) {
    if(b < qa || qb < a)
    return;
    
    if(qa <= a && b <= qb) {
        tree[n] += val;
        lazy[n] += val;
        
        return;
    }
    
    push(n, a, b);
    
    int mid = (a + b);
    mid /= 2;
    
    update(2*n, a, mid, qa, qb, val);
    update(2*n + 1, mid + 1, b, qa, qb, val);
    
    tree[n] = max(tree[2*n], tree[2*n + 1]);
}

int query(int n, int a, int b, int qa, int qb) {
    if(b < qa || qb < a)
    return LONG_MIN;
    
    if(qa <= a && b <= qb)
    return tree[n];
    
    push(n, a, b);
    
    int mid = (a + b);
    mid /= 2;
    
    return max(query(2*n, a, mid, qa, qb), query(2*n + 1, mid + 1, b, qa, qb));
}

signed main() {
    int n=0;
    int q=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int x=0;
    int y=0;
    int z=0;
    int i=0;
    int j=0;
    
    cin>>n>>q;
    
    vector<vector<int>> vect;
    
    for(i=0;i < q;i++) {
        cin>>a>>b>>c;
        
        vect.push_back({a, b, c});
        
        update(1ll, 1ll, n, a, b, c);
    }
    
    y = LONG_MAX;
    
    for(auto x : vect) {
        update(1ll, 1ll, n, x[0], x[1], -x[2]);
        
        y = min(y, query(1ll, 1ll, n, 1ll, n));
        
        update(1ll, 1ll, n, x[0], x[1], x[2]);
    }
    
    cout<<y<<endl;
    
    return 0;
}
