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
const int maxn = 1e7 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

int Child[10000000 + 2][2];
int val[10000000 + 2], num[10000000 + 2];
int n, q, cnt = 0;

void Add(int x){
    int node = 0;
    for (short i = 30; i >= 0; i--) {
        short ch = (((x) >> (i)) & 1);
        if (Child[node][ch] == 0) Child[node][ch] = ++ cnt;
        node = Child[node][ch];
        num[node] ++;
    }
    val[node] = x;
}
 
int Get(int k){
    int node = 0;
	int res = 0;
    for (short i = 30; i >= 0; i--) {
        if (Child[node][0] == 0 || k > num[Child[node][0]]){
            k -= num[Child[node][0]];
            node = Child[node][1];
			res = res * 2 + 1;
        } else node = Child[node][0], res = res * 2;
    }
    return res;
}

int test, type, x;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> test;
    
    while (test--) {
    	cin >> type >> x;
    	
    	if (type == 1) Add(x);
    	else cout << Get(x) << endl;
    }
    return 0;
}
