#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int x=0;
    int y=0;
    int i=0;
    int j=0;
    
    cin>>a>>b>>c>>d;
    
    if(a == 0 && b == 0 && c == 0 && d == 0) {
        cout<<1<<endl;
        
        return 0;
    }
    
    else if(a == 0 && b == 0 && c == 0) {
        d *= 8;
        d++;
        
        if(static_cast<int>(sqrt(d)) * static_cast<int>(sqrt(d)) != d) {
            cout<<"Impossible"<<endl;
        
            return 0;
        }
        
        d = static_cast<int>(sqrt(d));
        
        d++;
        
        if(d%2 != 0) {
            cout<<"Impossible"<<endl;
            
            return 0;
        }
        
        d /= 2;
        
        while(d--)
        cout<<1;
        
        cout<<endl;
        
        return 0;
    }
    
    else if(d == 0 && b == 0 && c == 0) {
        a *= 8;
        a++;
        
        if(static_cast<int>(sqrt(a)) * static_cast<int>(sqrt(a)) != a) {
            cout<<"Impossible"<<endl;
        
            return 0;
        }
        
        a = static_cast<int>(sqrt(a));
        
        a++;
        
        if(a%2 != 0) {
            cout<<"Impossible"<<endl;
            
            return 0;
        }
        
        a /= 2;
        
        while(a--)
        cout<<0;
        
        cout<<endl;
        
        return 0;
    }
    
    x = (8 * a);
    y = (8 * d);
    
    x++;
    y++;
    
    if(static_cast<int>(sqrt(x)) * static_cast<int>(sqrt(x)) != x) {
        cout<<"Impossible"<<endl;
        
        return 0;
    }
    
    if(static_cast<int>(sqrt(y)) * static_cast<int>(sqrt(y)) != y) {
        cout<<"Impossible"<<endl;
        
        return 0;
    }
    
    x = static_cast<int>(sqrt(x));
    y = static_cast<int>(sqrt(y));
    
    x++;
    y++;
    
    if(x%2 != 0 || y%2 != 0) {
        cout<<"Impossible"<<endl;
        
        return 0;
    }
    
    x /= 2;
    y /= 2;
    
    a = (x * y);
    
    if(b + c != a) {
        cout<<"Impossible"<<endl;
        
        return 0;
    }
    
    vector<int> vec;
    
    while(y--) {
        if(b == 0)
        vec.push_back(0);
        
        else {
            if(b < x) {
                vec.push_back(b);
                
                b = 0;
            }
            
            else {
                vec.push_back(x);
                
                b -= x;
            }
        }
    }
    
    sort(vec.begin(), vec.end());
    
    a = 1;
    i = 0;
    
    while(i < vec.size()) {
        while(i < vec.size() && vec[i] < a) {
            cout<<1;
            
            i++;
        }
        
        if(i >= vec.size())
        break;
        
        while(i < vec.size() && a <= vec[i]) {
            cout<<0;
            
            a++;
            
            x--;
        }
    }
    
    while(x--)
    cout<<0;
    
    cout<<endl;
    
    return 0;
}
