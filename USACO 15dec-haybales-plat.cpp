#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 300005;

vector<int> tree1(4 * mn, 0);
vector<int> lazy1(4 * mn, 0);

vector<int> tree2(4 * mn, 0);
vector<int> lazy2(4 * mn, 0);

void build(int n, int a, int b, vector<int>& vec) {
    if(a == b) {
        tree1[n] = vec[a];
        tree2[n] = vec[a];
    }

    else {
        int mid = (a + b);
        mid /= 2;

        build(2*n, a, mid, vec);
        build(2*n + 1, mid + 1, b, vec);

        tree1[n] = (tree1[2*n] + tree1[2*n + 1]);
        tree2[n] = min(tree2[2*n], tree2[2*n + 1]);
    }
}

void push(int n, int a, int b) {
    if(a == b) {
        lazy1[n] = 0;
        lazy2[n] = 0;

        return;
    }

    int mid = (a + b);
    mid /= 2;

    tree1[2*n] += ((mid - a + 1) * lazy1[n]);
    tree1[2*n + 1] += ((b - mid) * lazy1[n]);

    lazy1[2*n] += lazy1[n];
    lazy1[2*n + 1] += lazy1[n];

    tree2[2*n] += lazy2[n];
    tree2[2*n + 1] += lazy2[n];

    lazy2[2*n] += lazy2[n];
    lazy2[2*n + 1] += lazy2[n];

    lazy1[n] = 0;
    lazy2[n] = 0;
}

void update(int n, int a, int b, int qa, int qb, int val) {
    if(qb < a || b < qa)
    return;

    if(qa <= a && b <= qb) {
        tree1[n] += (b - a + 1) * val;
        tree2[n] += val;

        lazy1[n] += val;
        lazy2[n] += val;

        return;
    }

    push(n, a, b);

    int mid = (a + b);
    mid /= 2;

    update(2*n, a, mid, qa, qb, val);
    update(2*n + 1, mid + 1, b, qa, qb, val);

    tree1[n] = (tree1[2*n] + tree1[2*n + 1]);
    tree2[n] = min(tree2[2*n], tree2[2*n + 1]);
}

int query1(int n, int a, int b, int qa, int qb) {
    if(qb < a || b < qa)
    return 0;

    if(qa <= a && b <= qb) {
        return tree1[n];
    }

    push(n, a, b);

    int mid = (a + b);
    mid /= 2;

    return (query1(2*n, a, mid, qa, qb) + query1(2*n + 1, mid + 1, b, qa, qb));
}

int query2(int n, int a, int b, int qa, int qb) {
    if(qb < a || b < qa)
    return LONG_MAX;

    if(qa <= a && b <= qb) {
        return tree2[n];
    }

    push(n, a, b);

    int mid = (a + b);
    mid /= 2;

    return min(query2(2*n, a, mid, qa, qb), query2(2*n + 1, mid + 1, b, qa, qb));
}

signed main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n=0;
    int m=0;
    int k=0;
    int q=0;
    int a=0;
    int b=0;
    int c=0;
    int i=0;
    int j=0;

    char cc;

    cin>>n>>q;
    vector<int> vec(n+1);

    for(i=1;i <= n;i++) {
        cin>>a;

        vec[i] = a;
    }

    build(1ll, 1ll, n, vec);

    while(q--) {
        cin>>cc;

        if(cc == 'P') {
            cin>>a>>b>>c;

            update(1ll, 1ll, n, a, b, c);
        }

        else if(cc == 'M') {
            cin>>a>>b;

            cout<<query2(1ll, 1ll, n, a, b)<<endl;
        }

        else {
            cin>>a>>b;

            cout<<query1(1ll, 1ll, n, a, b)<<endl;
        }
    }

    return 0;
}
