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
const int maxn = 5e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

const int LG = 29;

struct Trie{
    struct Node{
        int child[2];
        int exist, cnt;
    } nodes[maxn + 2];

    int cur;
    Trie() : cur(0) {
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };

    int new_node() {
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }

    void add_number(int x) {
        int pos = 0;
        for (int i = LG; i >= 0; --i) {
            int c = (x >> i) & 1;
            if (nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
    }

    void delete_number(int x) {
        if (find_number(x) == false) return;
        int pos = 0;
        for (int i = LG; i >= 0; i--) {
            int c = (x >> i) & 1;

            int tmp = nodes[pos].child[c];
            nodes[tmp].cnt--;
            if (nodes[tmp].cnt == 0) {
                nodes[pos].child[c] = -1;
                return;
            }

            pos = tmp;
        }
        nodes[pos].exist--;
    }

    bool find_number(int x) {
        int pos = 0;
        for (int i = LG; i >= 0; --i) {
            int c = (x & (1 << i) ? 1 : 0);
            if (nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist != 0);
    }
};

Trie tries;

ll query(int x) {
    int pos = 0;
    ll res = 0;
    for (int i = LG; i >= 0; i--) {
        int c = (x >> i) & 1;

        if (tries.nodes[pos].child[c ^ 1] != -1) {
            res += (1ll << i);
            pos = tries.nodes[pos].child[c ^ 1];
        }
        else {
            pos = tries.nodes[pos].child[c];
        }
    }
    return res;
}

int n, a[maxn + 2];
ll ans = -oo;

int main() {
    nothing
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	tries.add_number(a[i]);
    	ans = max(ans, query(a[i]));
    }
    
    cout << ans << endl;
    
    return 0;
}
