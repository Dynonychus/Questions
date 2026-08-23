#include <bits/stdc++.h>

using namespace std;

const int mn = 250005;

vector<int> tree1(4 * mn, 0);
vector<int> lazy1(4 * mn, 0);

vector<array<int, 10>> tree2(4 * mn);

void apply(int n, int a, int b, int val) {
    val %= 10;
    
    if(val == 0)
    return;

    vector<int> vect(10, 0);
    
    for(int i=0;i <= 9;i++)
    vect[(i + val) % 10] += tree2[n][i];
    
    for(int i=0;i <= 9;i++)
    tree2[n][i] = vect[i];
    
    int aa = 0;
    
    for(int i=0;i <= 9;i++)
    aa += (i * tree2[n][i]);
    
    tree1[n] = aa;

    lazy1[n] = ((lazy1[n] + val) % 10);
}

void push(int n, int a, int b) {
    if (a == b) {
        lazy1[n] = 0;
        
        return;
    }
    
    int mid = (a + b);
    mid /= 2;
    
    apply(2*n, a, mid, lazy1[n]);
    apply(2*n + 1, mid + 1, b, lazy1[n]);
    
    lazy1[n] = 0;
}

void build(int n, int a, int b, string& u) {
    if(a == b) {
        int d = (u[a-1] - '0');
        
        tree1[n] = d;
        
        tree2[n][d] = 1;
        
        return;
    }
    
    int mid = (a + b);
    mid /= 2;
    
    build(2*n, a, mid, u);
    build(2*n + 1, mid + 1, b, u);
    
    tree1[n] = (tree1[2*n] + tree1[2*n + 1]);
    
    for(int i=0;i <= 9;i++) {
        tree2[n][i] = (tree2[2*n][i] + tree2[2*n + 1][i]);
    }
}

void update(int n, int a, int b, int qa, int qb) {
    if (b < qa || qb < a)
    return;
    
    if (qa <= a && b <= qb) {
        apply(n, a, b, 1ll);
        
        return;
    }
    
    push(n, a, b);
    
    int mid = (a + b);
    mid /= 2;
    
    update(2*n, a, mid, qa, qb);
    update(2*n + 1, mid + 1, b, qa, qb);
    
    tree1[n] = (tree1[2*n] + tree1[2*n + 1]);
    
    for(int i=0;i <= 9;i++) {
        tree2[n][i] = (tree2[2*n][i] + tree2[2*n + 1][i]);
    }
}

int query(int n, int a, int b, int qa, int qb) {
    if (b < qa || qb < a)
    return 0;
    
    if (qa <= a && b <= qb)
    return tree1[n];
    
    push(n, a, b);
    
    int mid = (a + b);
    mid /= 2;
    
    return (query(2*n, a, mid, qa, qb) + query(2*n + 1, mid + 1, b, qa, qb));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n=0;
    int m=0;
    int a=0;
    int b=0;
    int c=0;
    int i=0;
    int j=0;
    string u;
    
    cin>>n>>m;
    
    cin>>u;
    
    build(1ll, 1ll, n, u);
    
    while(m--) {
        cin>>a>>b;
        
        cout<<query(1ll, 1ll, n, a, b)<<endl;
        
        update(1ll, 1ll, n, a, b);
    }
    
    return 0;
}
