#include <bits/stdc++.h>

using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll mod = 1e9 + 7;
const int maxn = 1e6;
const int maxa = 2e3;
const int base = 31;

string S;
int n, k, x;
unordered_map<char, int> freq;
int l = 0, maxLength = 0, changes = 0;

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> n >> k >> x >> S;
    
    for (int r = 0; r < n; r++) {
        freq[S[r]]++;

        while ((int)freq.size() > k) {
            freq[S[l]]--;
            if (freq[S[l]] == 0) freq.erase(S[l]);
            l++;
        }

        changes = (r - l + 1) - (*max_element(freq.begin(), freq.end(), 
                    [](auto &a, auto &b) { return a.second < b.second; })).second;

        while (changes > x) {
            freq[S[l]]--;
            if (freq[S[l]] == 0) freq.erase(S[l]);
            l++;
            changes = (r - l + 1) - (*max_element(freq.begin(), freq.end(), 
                        [](auto &a, auto &b) { return a.second < b.second; })).second;
        }

        maxLength = max(maxLength, r - l + 1);
    }
    
    cout << maxLength << endl;

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
}
