#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 500005;

struct Node {
	int sum;
	int pref;
	int suff;
	int best;
};

vector<Node> tree(4*mn);

Node merge(Node xx, Node yy) {
    if(xx.best == LONG_MIN)
    return yy;
    
    if(yy.best == LONG_MIN)
    return xx;
    
	Node zz;
	
	zz.sum = (xx.sum + yy.sum);
	zz.pref = max(xx.pref, xx.sum + yy.pref);
	zz.suff = max(yy.suff, yy.sum + xx.suff);
	zz.best = max({xx.best, yy.best, xx.suff + yy.pref});
	
	return zz;
}

void build(int n, int a, int b, vector<int>& vec) {
	if(a == b) {
		tree[n].sum = vec[a];
		tree[n].pref = vec[a];
		tree[n].suff = vec[a];
		tree[n].best = vec[a];
		
		return;
	}
	
	int mid = (a + b);
	mid /= 2;
	
	build(2*n, a, mid, vec);
	build(2*n + 1, mid + 1, b, vec);
	
	Node zz = merge(tree[2*n], tree[2*n + 1]);
	
	tree[n] = zz;
}

Node query(int n, int a, int b, int qa, int qb) {
	if(b < qa || qb < a) {
		Node zz;
		
		zz.sum = 0;
		zz.pref = LONG_MIN;
		zz.suff = LONG_MIN;
		zz.best = LONG_MIN;
		
		return zz;
	}
	
	if(qa <= a && b <= qb) {
		return tree[n];
	}
	
	int mid = (a + b);
	mid /= 2;
	
	Node xx = query(2*n, a, mid, qa, qb);
	Node yy = query(2*n + 1, mid + 1, b, qa, qb);
	
	return merge(xx, yy);
}

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
	vector<int> vec(n+1);
	
	for(i=1;i <= n;i++) {
		cin>>a;
		
		vec[i] = a;
	}
	
	build(1ll, 1ll, n, vec);
	
	cin>>m;
	
	while(m--) {
		cin>>a>>b;
		
		Node zz = query(1ll, 1ll, n, a, b);
		
		cout<<zz.best<<endl;
	}
	
	return 0;
}
