#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = (1e9 + 7);

signed main() {
    int n=0;
    int k=0;
    int a=0;
    int b=0;
    int c=0;
    int i=0;
    int j=0;
    
    cin>>n>>k;
    vector<int> dp(k+1, 0);
    
    dp[0] = 1;
    
    for(i=1;i <= n;i++) {
        a = (-i);
        b = 0;
        
        c=0;
        
        vector<int> vec(k+1, 0);
        
        for(j=0;j <= k;j++) {
            c += dp[j];
            
            if(a >= 0)
            c -= dp[a];
            
            a++;
            
            c += MOD;
            c %= MOD;
            
            vec[j] = c;
        }
        
        dp = vec;
    }
    
    cout<<dp[k]<<endl;
    
    return 0;
}
