#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 500005;

vector<int> tree(4 * mn);

void build(int n, int a, int b, vector<int>& dist) {
    if(a == b) {
        tree[n] = dist[a];
        
        return;
    }
    
    int mid = (a + b);
    mid /= 2;
    
    build(2*n, a, mid, dist);
    build(2*n + 1, mid + 1, b, dist);
    
    tree[n] = min(tree[2*n], tree[2*n + 1]);
}

void update(int n, int a, int b, int qq) {
    if(b < qq || qq < a)
    return;
    
    if(a == b) {
        tree[n] = LONG_MAX;
        
        return;
    }
    
    int mid = (a + b);
    mid /= 2;
    
    update(2*n, a, mid, qq);
    update(2*n + 1, mid + 1, b, qq);
    
    tree[n] = min(tree[2*n], tree[2*n + 1]);
}

int query(int n, int a, int b, int qa, int qb) {
    if(b < qa || qb < a)
    return LONG_MAX;
    
    if(qa <= a && b <= qb)
    return tree[n];
    
    int mid = (a + b);
    mid /= 2;
    
    return min(query(2*n, a, mid, qa, qb), query(2*n + 1, mid + 1, b, qa, qb));
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
  
  vector<int> vec(n+1);
  
  vector<int> dist(n+1, LONG_MAX);
  vector<int> prev(n+1, LONG_MIN);
  
  for(i=1;i <= n;i++) {
      cin>>a;
      
      vec[i] = a;
  }
  
  map<int, int> mp;
  
  for(i=1;i <= n;i++) {
      if(mp[vec[i]] == 0) {
          mp[vec[i]] = i;
          
          continue;
      }
      
      prev[i] = mp[vec[i]];
      dist[i] = (i - prev[i]);
      
      mp[vec[i]] = i;
  }
  
  vector<vector<int>> appears(n+1);
  
  for(i=1;i <= n;i++) {
      if(prev[i] != LONG_MIN)
      appears[prev[i]].push_back(i);
      
      else
      appears[0].push_back(i);
  }
  
  build(1ll, 1ll, n, dist);
  
  vector<vector<int>> queries(m);
  vector<int> ans(m, -1);
  
  for(i=0;i<m;i++) {
      cin>>a>>b;
      
      queries[i] = {a, b, i};
  }
  
  sort(queries.begin(), queries.end());
  
  i=0;
  
  for(auto x : queries) {
      for(;i < x[0];i++) {
          for(auto xx : appears[i])
          update(1ll, 1ll, n, xx);
      }
      
      a = query(1ll, 1ll, n, 1, x[1]);
      
      if(a != LONG_MAX)
      ans[x[2]] = a;
  }
  
  for(i=0;i<m;i++)
  cout<<ans[i]<<endl;
  
  return 0;
}
