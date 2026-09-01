#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 200005;

vector<int> tree(4 * mn, LONG_MAX);

void update(int n, int a, int b, int qa, int val) {
  if(b < qa || qa < a)
  return;
  
  if(a == b && a == qa) {
    tree[n] = min(tree[n], val);
    
    return;
  }
  
  int mid = (a + b);
  mid /= 2;
  
  update(2*n, a, mid, qa, val);
  update(2*n + 1, mid + 1, b, qa, val);
  
  tree[n] = min(tree[2*n], tree[2*n + 1]);
}

int query(int n, int a, int b, int qa, int qb, int val) {
  if(b < qa || qb < a)
  return LONG_MAX;
  
  if(tree[n] > val)
  return LONG_MAX;
  
  if(a == b)
  return a;
  
  int mid = (a + b);
  mid /= 2;
  
  int c = query(2*n, a, mid, qa, qb, val);
  
  if(c != LONG_MAX)
  return c;
  
  return query(2*n + 1, mid + 1, b, qa, qb, val);
}

signed main() {
  int n=0;
  int q=0;
  int a=0;
  int b=0;
  char c=0;
  int i=0;
  int j=0;
  
  cin>>n>>q;
  
  while(q--) {
    cin>>c>>a>>b;
    
    if(c == 'M') {
      update(1ll, 1ll, n, b, a);
    }
    
    else {
      a = query(1ll, 1ll, n, b, n, a);
      
      if(a == LONG_MAX)
      cout<<-1<<endl;
      
      else
      cout<<a<<endl;
    }
  }
  
  return 0;
}
