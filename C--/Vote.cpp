#include<bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    int n,k;
    int a[105];
    bool ok=true;
    long long S;
    for (int i=1;i<=T;i++) {
        cin >> n >> k;
        ok=true;
        S=k;
        for (int j=0;j<n;j++) {
            cin >> a[j];
            S+=a[j];
        }
        if (S%n!=0) ok=false;
        if (ok==true)
        {
            for (int j=0;j<n;j++) {
                if (a[j]>(S/n)) ok=false;
            }
        }
        if (ok==true) cout << "YES" << "\n";
            else cout << "NO" << "\n";
    }
}

