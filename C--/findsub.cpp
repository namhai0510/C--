#include<bits/stdc++.h>
using namespace std;
int main () {
    map<long long, long long> m;
    map<long long, long long> mp;
    map<long long, long long> mp2;
    vector<long long> S2;
    long long n;
    cin >> n;
    int a[n];
    long long S=0;
    long long maxa=0;
    for (int i=1;i<=n;i++) {         ///Tinh tong o vi tri thu i
        cin >> a[i];
        S+=a[i];
        m[i]=S;
        if (mp[a[i]]==0) {
            mp[a[i]]=i;
            mp2[a[i]]=0;
        }
        else {
            mp2[a[i]]=i;
        }
        if (mp2[a[i]]!=0) {
            if (mp[a[i]]==1 && a[1]==a[0]) maxa=m[mp2[a[i]]];
            else {
            maxa=m[mp2[a[i]]]-m[mp[a[i]]]+a[i];
            S2.push_back(maxa);
            }
        }
    }
    sort(S2.begin(),S2.end());
    /*for (int i=0;i<n;i++) {         ///Xu li tong cua doan i j
        if (mp2[a[i]]!=0) {
            if (mp[a[i]]==1 && a[1]==a[0]) mp[a[i]]=0;
            maxa=m[mp2[a[i]]]-m[mp[a[i]]]+a[i];
        }
        ///cout << m[mp2[a[i]]] << " " << m[mp[a[i]]] << endl;
        ///cout << maxa << endl;
        if (S!=0) S=max(S,maxa);
        else S=maxa;
    }
    cout << S;                      ///Cout ra ket qua*/
    ///cout << S2.size();
    cout << S2[S2.size()-1];
}
