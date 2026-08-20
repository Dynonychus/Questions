#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 300005;

vector<int> tree(4 * mn, 0);
vector<int> ans(mn + 1, 0);

void build(int n, int a, int b, int qa, int qb, int val) {
    if(b < qa || qb < a)
    return;
    
    if(qa <= a && b <= qb) {
        tree[n] = max(tree[n], a - qa + val);
    }
    
    else {
        int mid = (a + b);
        mid /= 2;
        
        build(2*n, a, mid, qa, qb, val);
        build(2*n + 1, mid + 1, b, qa, qb, val);
    }
}

void propo(int n, int a, int b, int val) {
    tree[n] = max(tree[n], val);
    
    if(a == b) {
        ans[a] = max(ans[a], tree[n]);
        
        return;
    }
    
    int mid = (a + b);
    mid /= 2;
    
    if(tree[n] == 0) {
        propo(2*n, a, mid, 0);
        propo(2*n + 1, mid + 1, b, 0);
        
        return;
    }
    
    propo(2*n, a, mid, tree[n]);
    propo(2*n + 1, mid + 1, b, tree[n] + mid - a + 1);
}

void anss(int n) {
    int i=0;
    
    for(i=1;i <= n;i++)
    cout<<max(0ll, ans[i])<<" ";
    
    cout<<endl;
}

signed main() {
    int n=0;
    int m=0;
    int a=0;
    int b=0;
    int c=0;
    int i=0;
    int j=0;
    
    cin>>n>>m;
    
    while(m--) {
        cin>>a>>b>>c;
        
        build(1ll, 1, n, a, b, c);
    }
    
    propo(1ll, 1, n, 0);
    
    anss(n);
    
    return 0;
}
