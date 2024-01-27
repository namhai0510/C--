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

ll parent[maxn + 2], altitude[maxn + 2];

void make_set(int v) {
    parent[v] = v;
    altitude[v] = 0; // Goc cua cay co do cao 0
}

int find_set(int v) {
    if (v == parent[v]) return v; // Neu v la goc tra ve v
    int p = find_set(parent[v]); // De quy len cha cua v
    parent[v] = p; // Nen doan tu v len goc
    return p;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (altitude[a] < altitude[b]) swap(a, b); // Dat a la goc cua cay lon hon
        parent[b] = a;
        if (altitude[a] == altitude[b]) altitude[a]++; // Neu 2 cay cung do cao => sau gop do cao tang 1
    } 
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    return 0;
}
