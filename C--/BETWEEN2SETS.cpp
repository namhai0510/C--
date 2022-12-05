#include<bits/stdc++.h>
using namespace std;
int gcd (int a,int b) {
    if (b==0) return a;
    return gcd(b,a%b);
}
int lcm (int a, int b) {
    return (a*b)/gcd(a,b);
}
int main () {
    int n,m; cin >> n >> m;
    int a[n+1],b[m+1];
    int bc=1;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        bc=lcm(bc,a[i]);
        ///cout << bc << endl;
    }
    int bc2=1;
    for (int i=1;i<=m;i++) {
        cin >> b[i];
        bc2=lcm(bc2,b[i]);
    }
    sort(b+1,b+1+n);
    int cnt=0; bool ok=true;
    for (int i=bc;i<=b[1];i++) {
        /*for (int j=1;j<=m;j++) if (b[j]%i!=0) ok=false;
        if (ok==true) cnt++;
        ok=true;*/
        if (bc2%i==0) cnt++;
    }
    cout << cnt;
}

///https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true&h_r=next-challenge&h_v=zen
