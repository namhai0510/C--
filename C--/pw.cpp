#include <bits/stdc++.h>

using namespace std;
#define nothing ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define newline "\n"
#define all(v) (v).begin(), (v).end()
typedef long long int64;
const long long alphabet_size = 26;
int char_count[alphabet_size];

bool is_palindrome(const string& s) {
    for (int i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - i - 1])
            return false;
    return true;
}

int main() {
    nothing
    
    const char* input_file = "pw.INP";
    const char* output_file = "pw.OUT";
    if (fopen(input_file, "r")) {
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    }

    long long K, m, left, right;
    cin >> K >> m;
    string main_string, substrings[K];
    cin >> main_string;
    for (int i = 0; i < K - 1; ++i) {
        cin >> left >> right;
        for (int j = left - 1; j < right; ++j) {
            substrings[i] += main_string[j];
            ++char_count[main_string[j] - 'a'];
        }
    }

    long long result = 0;
    for (int i = 0; i < main_string.size() - m + 1; ++i) {
        for (int j = i; j < i + m; ++j) {
            substrings[K - 1] += main_string[j];
            ++char_count[main_string[j] - 'a'];
        }
        int odd_char_count = 0;
        for (int j = 0; j < alphabet_size; ++j)
            odd_char_count += char_count[j] & 1;
        for (int j = i; j < i + m; ++j)
            --char_count[main_string[j] - 'a'];
        if (odd_char_count > 1) continue;

        vector<int> perm;
        for (int i = 1; i <= K; ++i)
            perm.push_back(i);
        do {
            string combined_string;
            for (int k : perm)
                combined_string += substrings[k - 1];
            if (is_palindrome(combined_string)) {
                ++result;
                break;
            }
        } while (next_permutation(all(perm)));

        substrings[K - 1].clear();
    }

    cout << result;
    return 0;
}
