#include<bits/stdc++.h>
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL);
using ll = long long;
using ull = unsigned long long;
#define in insert
#define fi first
#define se second
#define pb push_back
#define el "\n"
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 3e4 + 5;

string s;

bool CheckPalindrome (string s) {
    for (int i = 0, j = s.length() - 1; i <= j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

bool CheckNines (string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '9') {
            return false;
        }
    }
    return true;
}

string FindForNines (string s) {
    string res = "1";
    for (int i = 0; i < s.length() - 1; i++) res = res + '0';
    res = res + '1';
    return res;
}

string AddCenter (string s) {
    int n, i, cs, cr;
    cs = s.length() / 2;
    i = cs;
    do {
        n = s[i] - 48;
        n++;
        cr = n / 10;
        s[i] = (n % 10) + 48;
        i++;
    }
    while (i < s.length() && cr == 1);

    for (int i = 0, j = s.length() - 1; i <= j; i++, j--) s[i] = s[j];
    return s;
}

string Prepare (string s) {
    for (int i = 0, j = s.length() - 1; i <=j ; i++, j--){
        if (s[j] < s[i]) {
            s[j] = s[i];
            continue;
        }

        if (s[j] > s[i]) {
            s[j] = s[i];
            int n, cr = 1, k = j - 1;
            while (cr && k >= 0){
                n = s[k] - 48;
                n++;
                cr = n / 10;
                s[k] = (n % 10) + 48;
                k--;
            }
        }
    }

    return s;
}

string Next(string s){
    return Prepare(Prepare(s));
}

string NextPalindrome (string s){
    string res;
    if(CheckPalindrome(s)) {
        if(CheckNines(s)) {
            return FindForNines(s);
        }
        return AddCenter(s);
    }
    return Next(s);
}

int main() {
    nothing
    if (fopen("palind.inp","r")) {
        freopen("palind.inp","r",stdin);
        freopen("palind.out","w",stdout);
    }
    cin >> s;
    cout << NextPalindrome(s);
}
