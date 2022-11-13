#include<bits/stdc++.h>

using namespace std;

bool sangnt(int a){
    bool ok[a+1];
    ok[0]=false;
    ok[1]=false;
    for (int i=2; i<=a; i++) {
            ok[i]=true;
    }

    for (int i=2; i<=sqrt(a); i++){
        if (ok[i]==true){
            for (int j=i*i; j<=a; j+=i){
                ok[j]=false;
            }
        }
    }
    if (ok[a]==true) return true;
        else return false;
}
int main () {
    //sangnguyento eratosthenes o day nua de ktra so nguyen to

    long long n;
    long long k;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int cnt=0;
    if (n%2==1) {
        cnt=1;
        for (int i=3; i<n;i+=2) {
            if (n%i==0 && sangnt(i)==true ) {
                    cnt++;
                }
            }
        cout << cnt;
        }
    else {
        if (n%4==0) {
            cout << "0";
        }
        else {
            cnt=1;
            k=n/2;
            for (int i=3; i<k;i+=2) {
                if (k%i==0 && sangnt(i)==true){
                    cnt++;
                }
            }
            cout << cnt;
        }
    }
}

