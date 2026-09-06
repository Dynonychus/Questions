#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n=0;
    int m=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int x=0;
    int y=0;
    int z=0;
    int i=0;
    int j=0;
    
    cin>>n;
    vector<int> vec(n);
    
    for(auto &x : vec)
    cin>>x;
    
    map<int, int> mp;
    map<int, int> mp1;
    
    for(i=0;i<n;i++) {
        vector<pair<int, int>> vec1;
        
        for(auto x : mp1) {
            a = x.first;
            
            a = __gcd(a, vec[i]);
            
            vec1.push_back({a, x.second});
        }
        
        vec1.push_back({vec[i], 1});
        
        mp1.clear();
        
        for(auto x : vec1)
        mp1[x.first] += x.second;
        
        for(auto x : mp1)
        mp[x.first] += x.second;
    }
    
    cin>>m;
    
    while(m--) {
        cin>>a;
        
        cout<<mp[a]<<endl;
    }
    
    return 0;
}
