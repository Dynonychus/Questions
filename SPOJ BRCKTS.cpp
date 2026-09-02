#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 30000;

vector<int> tree(4 * mn);
vector<int> lazy(4 * mn, 0);

void build(int n, int a, int b, vector<int>& vec) {
	if(a == b) {
		tree[n] = vec[a];
		
		return;
	}
	
	int mid = (a + b);
	mid /= 2;
	
	build(2*n, a, mid, vec);
	build(2*n + 1, mid + 1, b, vec);
	
	tree[n] = min(tree[2*n], tree[2*n + 1]);
}

void push(int n, int a, int b) {
	if(a == b) {
		lazy[n] = 0;
		
		return;
	}
	
	tree[2*n] += lazy[n];
	lazy[2*n] += lazy[n];
	
	tree[2*n + 1] += lazy[n];
	lazy[2*n + 1] += lazy[n];
	
	lazy[n] = 0;
}

void update(int n, int a, int b, int qa, int qb, int val) {
	if(b < qa || qb < a)
	return;
	
	if(qa <= a && b <= qb) {
		tree[n] += val;
		lazy[n] += val;
		
		return;
	}
	
	push(n, a, b);
	
	int mid = (a + b);
	mid /= 2;
	
	update(2*n, a, mid, qa, qb, val);
	update(2*n + 1, mid + 1, b, qa, qb, val);
	
	tree[n] = min(tree[2*n], tree[2*n + 1]);
}

int query(int n, int a, int b, int qa, int qb) {
	if(b < qa || qb < a)
	return LONG_MAX;
	
	if(qa <= a && b <= qb)
	return tree[n];
	
	push(n, a, b);
	
	int mid = (a + b);
	mid /= 2;
	
	return min(query(2*n, a, mid, qa, qb), query(2*n + 1, mid + 1, b, qa, qb));
}

signed main() {
	// your code goes here
	
	int t = 10;
	
	while(t--) {
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
		string u;
		
		cin>>n;
		
		vector<int> vec(n+1);
		
		tree.assign(4*n + 20, 0);
		lazy.assign(4*n + 20, 0);
		
		cin>>u;
		
		for(i=0;i<n;i++) {
			if(u[i] == '(')
			vec[i+1] = 1;
			
			else
			vec[i+1] = -1;
		}
		
		c = vec[1];
		
		for(i=2;i <= n;i++) {
		    c += vec[i];
		    
		    vec[i] += vec[i-1];
		}
		
		build(1ll, 1ll, n, vec);
		
		cout<<"Test ";
		
		cout<<10 - t<<": "<<endl;
		
		cin>>m;
		
		while(m--) {
			cin>>a;
			
			if(a == 0) {
				bool check1 = true;
				
				if(query(1ll, 1ll, n, 1ll, n) < 0 || c != 0)
				check1 = false;
				
				if(check1)
				cout<<"YES"<<endl;
				
				else
				cout<<"NO"<<endl;
			}
			
			else {
				b = 2;
				
				if(u[a-1] == '(')
				b = -2;
				
				if(u[a-1] == '(') {
				    u[a-1] = ')';
				    
				    c -= 2;
				}
				
				else {
				    u[a-1] = '(';
				    
				    c += 2;
				}
				
				update(1ll, 1ll, n, a, n, b);
			}
		}
	}
	
	return 0;
}
