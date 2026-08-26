#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 200005;

vector<int> tree1(4 * mn);
vector<int> tree2(4 * mn);

void build(int n, int a, int b, vector<int>& pos) {
    if(a == b) {
        tree1[n] = pos[a];
        tree2[n] = pos[a];
        
        return;
    }
    
    int mid = (a + b);
    mid /= 2;
    
    build(2*n, a, mid, pos);
    build(2*n + 1, mid + 1, b, pos);
    
    tree1[n] = min(tree1[2*n], tree1[2*n + 1]);
    tree2[n] = max(tree2[2*n], tree2[2*n + 1]);
}

int qmin(int n, int a, int b, int qa, int qb) {
    if(b < qa || qb < a)
    return LONG_MAX;
    
    else if(qa <= a && b <= qb)
    return tree1[n];
    
    int mid = (a + b);
    mid /= 2;
    
    return min(qmin(2*n, a, mid, qa, qb), qmin(2*n + 1, mid + 1, b, qa, qb));
}

int qmax(int n, int a, int b, int qa, int qb) {
    if(b < qa || qb < a)
    return LONG_MIN;
    
    else if(qa <= a && b <= qb)
    return tree2[n];
    
    int mid = (a + b);
    mid /= 2;
    
    return max(qmax(2*n, a, mid, qa, qb), qmax(2*n + 1, mid + 1, b, qa, qb));
}

signed main() {
    int n=0;
    int s=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int x=0;
    int y=0;
    int i=0;
    int j=0;
    
    cin>>n>>s;
    vector<int> vec(n + 1);
    
    for(i=1;i <= n;i++) {
        cin>>a;
        
        vec[i] = a;
    }
    
    vector<int> pos(n+1, -1);
    
    map<int, int> mp;
    
    for(i=1;i <= n;i++) {
        mp[vec[i]] = i;
    }
    
    for(i=1;i <= n;i++) {
        if(mp[s - vec[i]] != 0)
        pos[i] = mp[s - vec[i]];
    }
    
    build(1ll, 1ll, n, pos);
    
    c = 0;
    
    int xx=0;
    int yy=0;
    
    for(i=1;i <= n;i++) {
        a = i;
        b = pos[i];
        
        if(b < a)
        continue;
        
        if(b == -1)
        continue;
        
        x = qmin(1ll, 1ll, n, a, b);
        y = qmax(1ll, 1ll, n, a, b);
        
        if(x == -1)
        continue;
        
        if(x < a)
        continue;
        
        if(y > b)
        continue;
        
        if((b - a + 1) > c) {
            c = (b - a + 1);
            
            xx = a;
            yy = b;
        }
    }
    
    cout<<c<<" "<<xx<<" "<<yy<<endl;
    
    return 0;
}
