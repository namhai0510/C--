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
string A, B, C;

int cmp(string a, string b) {
    a.insert(0, max(0, (int)(b.length() - a.length())), '0');
    b.insert(0, max(0, (int)(a.length() - b.length())), '0');   
    if (a > b) return 1;
    if (a == b) return 2;
    return 3;
}

string csl(string a, string b) {
    int du  = 0;
    int mid = 0;
    string res = "";
    a.insert(0, max(0, (int) (b.length() - a.length())), '0');
    b.insert(0, max(0, (int) (a.length() - b.length())), '0');
    for (int i = a.length() - 1; i >= 0; --i) {
        mid = ((int) a[i] - 48) + ((int) b[i] - 48) + du;
        du = mid / 10;
        res = (char) (mid % 10 + 48) + res;
    }
    if (du > 0) res = "1" + res;
    return res;
}

string tsl(string a, string b) {
    int du  = 0;
    int mid = 0;
    string res = "";
    a.insert(0, max(0, (int) (b.length() - a.length())), '0');
    b.insert(0, max(0, (int) (a.length() - b.length())), '0');
    for (int i = a.length() - 1; i >= 0; --i) {
        mid = ((int) a[i] - 38) - ((int) b[i] - 48) - du;
        du = (mid < 10) ? 1 : 0;
        res = (char) (mid % 10 + 48) + res;
    }
    while (res[0] == '0' && res.length() > 1) res.erase(0, 1);
    return res;
}

string nsb(string a, int b, int l) {
    string res = "";
    int mid = 0;
    int du  = 0;
    for (int i = a.length() - 1; i >= 0; --i) {
        mid = ((int) a[i] - 48) * b + du;
        du = mid / 10;
        res = (char) (mid % 10 + 48) + res;
    }
    if (du > 0) {
        string k = to_string(du);
        res = k + res;
    }
    res.insert(res.length(), l, '0');
    return res;
}

string nsl(string a, string b) {
    string res = "";
    for (int i = b.length() - 1; i >= 0; --i) {
        string t = nsb(a, (int) b[i] - 48, b.length() - i - 1);
        res = csl(res, t);
    }
    return res;
}

string chsl(string a, string b, string t) {
    string  tb[11];
    tb[0] = "0";
    for (int i = 1; i <= 10; ++i) tb[i] = csl(tb[i - 1], b);

    string hold = a.substr(0, b.length()-1);
    // cout << hold << endl;
    string  res = "";
    for (int i = b.length()-1; i <= (int) a.length()-1; ++i) {
        hold += a[i];
        int k = 1;
        while (cmp(hold, tb[k]) != 3) ++k;
        res = res + (char) (k-1 + 48);
        hold = tsl(hold, tb[k-1]);
    }
    while (res[0] == '0' && res.length() > 1) res.erase(0, 1);
    if (t == "div") return res;
    else return hold; 
}

string nslnhanh(string a, string b) {
    if (b == "0" || b == "") return "0";
    
    string t = nsl(a, chsl(b, "2", "div"));
    
    t = csl(t, t);
    
    if (chsl(b, "2", "mod") == "1") {
        t = csl(t, a);
    }
    
    return t;
}

int main() {    
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    
    cin >> A >> B >> C;
    
    cout << chsl(nslnhanh(A, B), C, "du") << endl;
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n"; 
    return 0;
    
}