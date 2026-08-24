#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  int n=0;
  int q=0;
  int a=0;
  int b=0;
  int c=0;
  int d=0;
  int x=0;
  int y=0;
  int i=0;
  int j=0;
  
  cin>>n>>q>>x>>y;
  
  vector<int> diff(n+1);
  
  b = 0;
  
  for(i=1;i <= (n+1);i++) {
    cin>>a;
    
    if(i == 1)
    diff[0] = a;
    
    else {
      diff[i-1] = (a - b);
    }
    
    b = a;
  }
  
  c = 0;
  
  for(i=0;i <= n;i++) {
    if(diff[i] > 0)
    c -= (diff[i] * x);
    
    else
    c += (abs(diff[i]) * y);
  }
  
  while(q--) {
    cin>>a>>b>>d;
    
    if(diff[a] > 0)
    c += (diff[a] * x);
    
    else
    c -= (abs(diff[a]) * y);
    
    diff[a] += d;
    
    if(diff[a] > 0)
    c -= (diff[a] * x);
    
    else
    c += (abs(diff[a]) * y);
    
    if(b <= (n-1)) {
        if(diff[b+1] > 0)
        c += (diff[b+1] * x);
        
        else
        c -= (abs(diff[b+1]) * y);
        
        diff[b+1] -= d;
        
        if(diff[b+1] > 0)
        c -= (diff[b+1] * x);
        
        else
        c += (abs(diff[b+1]) * y);
    }
    
    cout<<c<<endl;
  }
  
  return 0;
}
