#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;

ll t, n, a[maxn + 2], d[maxn + 2];

void Dfs(ll l, ll r, ll cur) {
	if (r < l) return;
	
	if (l == r) {
		d[l] = cur;
		return;
	}
	
	ll mid = l;
	
	for (int i = l + 1; i <= r; ++i) {
		if (a[mid] < a[i]) mid = i;
	}
	
	d[mid] = cur;
	
	Dfs(l, mid - 1, cur + 1);
	Dfs(mid + 1, r, cur + 1);
}

int main() {
    nothing
    if (fopen("permutation_transformation.inp", "r")) {
        freopen("permutation_transformation.inp", "r", stdin);
        freopen("permutation_transformation.out", "w", stdout);
    }
    cin >> t;
    
    while (t--) {
    	cin >> n;
    	for (int i = 1; i <= n; ++i) {
    		cin >> a[i];
    	}
    	
    	Dfs(1, n, 0);
    	
    	for (int i = 1; i <= n; ++i) {
    		cout << d[i] << " ";
    	}
    	
    	cout << endl;
    }
    return 0;
}

// https://codeforces.com/contest/1490/problem/D

// xay dung mang d voi ham (l, r, cur) nhu sau
// l, r : diem bat dau va ket thuc cua doan, cur : do sau hien tai
// trong doan [l, r], tim vi tri mid ma a[mid] la lon nhat
// => a[mid] = cur;
// neu l < m : chuyen den (l, mid - 1, cur + 1)
// neu m < r : chuyen den (mid + 1, r, cur + 1)

