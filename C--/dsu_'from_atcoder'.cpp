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

ll lab[maxn + 2];

void make_set(int v) {
    lab[u] = -1;
}

int find_set(int v) {
    return lab[v] < 0 ? v : lab[v] = find_set(lab[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    
    if (a != b) {
        if (lab[a] > lab[b]) swap(a, b);
        lab[a] += lab[b];
        lab[b] = a;
    }
}
// lab[v] am thi u la goc mot cay va -lab[v] la so dinh cua cay do
// lab[v] duong thi lab[v] la cha cua u

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    return 0;
}
