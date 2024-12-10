#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LIS(const vector<int>& arr) {
    vector<int> dp;
    for (int x : arr) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}

int main() {
	if (fopen("CS.inp", "r")) {
        freopen("CS.inp", "r", stdin);
        freopen("CS.out", "w", stdout);
    }
    
    int n;
    cin >> n;
    vector<pair<int, int>> books(n);

    for (int i = 0; i < n; ++i) {
        cin >> books[i].first >> books[i].second;
    }
    sort(books.begin(), books.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    vector<int> widths(n);
    for (int i = 0; i < n; ++i) {
        widths[i] = books[i].second;
    }

    cout << LIS(widths) << endl;
    return 0;
}