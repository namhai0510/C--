https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
-------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define atami ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define fi first
#define se second
#define pb push_back
#define el "\n"
const int maxn = 1e6 + 5;
const int maxa = 1e3 + 5;
int n,res = 0,cnt = 0;
int a[maxa];
map<int,int> mark;
void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mark[a[i]]++;
        res = max(res, a[i]);
    }
}
void Solve() {
    for (int i = 1; i <= res; i++) {
        cnt = max(mark[i - 1] + mark[i],cnt);
    }
}
void Output() {
    cout << cnt;
}
int main() {
    //freopen("SS.INP","r",stdin);
    atami;
    Input();
    Solve();
    Output();
}