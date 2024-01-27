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

ll parent[maxn + 2], sz[maxn + 2];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1; // Ban dau tap chua v co kich thuoc la 1
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
        if (sz[a] < sz[b]) swap(a, b); // Dat a la goc cua cay co kich thuoc lon hon
        parent[b] = a;
        sz[a] += sz[b]; // Cap nhat kich thuoc sau khi gop
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
