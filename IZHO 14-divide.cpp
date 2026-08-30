#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 100005;

vector<int> tree(4 * mn, 0);

void update(int n, int a, int b, int qa, int qb, int val) {
    if(b < qa || qb < a)
    return;
    
    if(qa <= a && b <= qb) {
        tree[n] = max(tree[n], val);
        
        return;
    }
    
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
    
    int mid = (a + b);
    mid /= 2;
    
    return max(query(2*n, a, mid, qa, qb), query(2*n + 1, mid + 1, b, qa, qb));
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
    
    cin>>n;
    
    vector<int> pos(n+1, 0);
    vector<int> prefg(n+1, 0);
    vector<int> prefd(n+1, 0);
    
    for(i=1;i <= n;i++) {
        cin>>a>>b>>c;
        
        pos[i] = a;
        prefg[i] = (prefg[i-1] + b) ;
        prefd[i] = (prefd[i-1] + c);
    }
    
    vector<int> vec1(n+1, 0);
    vector<int> vec2(n+1, 0);
    
    for(i=0;i<n;i++)
    vec1[i] = (prefd[i] - pos[i+1]);
    
    for(i=1;i <= n;i++)
    vec2[i] = (prefd[i] - pos[i]);
    
    vector<pair<int, int>> vect;
    
    for(i=1;i <= n;i++)
    vect.push_back({vec2[i], i});
    
    sort(vect.begin(), vect.end());
    
    vector<int> poss(n+1, -1);
    
    for(i=0;i<n;i++)
    poss[vect[i].second] = (i + 1);
    
    // B[R] >= A[L] | max(G[R] - G[L])
    
    b = 0;
    
    vector<int> vecot;
    
    for(i=0;i<n;i++)
    vecot.push_back(vect[i].first);
    
    for(i = n;i >= 1;i--) {
        a = poss[i];
        
        update(1ll, 1ll, n, a, a, prefg[i]);
        
        auto it = lower_bound(vecot.begin(), vecot.end(), vec1[i-1]);
        
        if(it != vecot.end()) {
            a = (it - vecot.begin());
            a++;
            
            a = query(1ll, 1ll, n, a, n);
            
            b = max(b, a - prefg[i-1]);
        }
    }
    
    cout<<b<<endl;
    
    
    return 0;
}
