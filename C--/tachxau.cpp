#include <bits/stdc++.h>
 
using namespace std;
#define nothing ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
const ll oo = 1e13;
const ll modd = 1e9 + 7;
const int maxn = 1e6 + 5;
const int maxa = 2e3 + 5;
const int base = 31;

struct Trie {
    struct Node{
        int child[26];
        int exist, cnt;
    } nodes[maxn + 2];

    int cur; // Hiện trong trie đang có bao nhiêu đỉnh
    Trie() : cur(0) { // Tạo nút gốc cho Trie là đỉnh 0 khi khởi tạo Trie
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };

    int new_node() { // Tạo và trả về giá trị của đỉnh mới được tạo ra
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }

    void add_string(string s) {
        int pos = 0;
        for (auto f : s) {
            int c = f - 'a';
            if (nodes[pos].child[c] == -1) { // Nếu cạnh tương ứng chữ cái c 
                                             // chưa tồn tại thì ta tạo ra đỉnh mới
                nodes[pos].child[c] = new_node();
            }
            pos = nodes[pos].child[c];
            nodes[pos].cnt++; // Có thêm một xâu trong trie có tiền tố
                              // là xâu được thể hiện bằng đỉnh hiện tại
        }
        nodes[pos].exist++; // Đã tìm được đỉnh tương ứng với xâu s,
                            // ta tăng biến exist của đỉnh lên 1
    }

    bool delete_string_recursive(int pos, string& s, int i) { // Trả về liệu đỉnh pos
                                                              // có bị xóa đi hay không
        if (i != (int)s.size()) { // Nếu chưa đến đỉnh tương ứng với xâu s
                                  // thì tiếp tục đệ quy xuống dưới
            int c = s[i] - 'a';
            bool isChildDeleted = delete_string_recursive(nodes[pos].child[c], s, i + 1);
            if (isChildDeleted) nodes[pos].child[c] = -1; // Nếu đỉnh con tương ứng bị xóa thì
                                                          // ta gán lại đỉnh tương ứng bằng -1
        }
        else nodes[pos].exist--; // Nếu đã đến đỉnh tương ứng với xâu s
                                 // thì ta giảm biến exist của đỉnh đi 1

        if (pos != 0) { // Nếu đỉnh đang xét không phải gốc thì ta giảm biến cnt của đỉnh đi 1
                        // và kiểm tra đỉnh có bị xóa đi hay không
                        // Đỉnh bị xóa nếu không còn xâu nào đi qua nó, nói cách khác là
                        // không còn xâu nào có tiền tố là xâu được thể hiện bởi đỉnh pos
            nodes[pos].cnt--;
            if (nodes[pos].cnt == 0) return true;
        }
        return false;
    }

    void delete_string(string s) {
        if (find_string(s) == false) return; // Kiểm tra xâu s có trong
                                             // trie hay không
        delete_string_recursive(0, s, 0); // Gọi hàm đệ quy xóa xâu s khỏi trie
    }

    bool find_string(string s) {
        int pos = 0;
        for (auto f : s) {
            int c = f - 'a';
            if (nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist != 0); // Kiểm tra có xâu nào
                                        // kết thúc tại đỉnh này hay không
    }
};

Trie tries;
ll n, q, length;
string s;

int dp[maxn + 2], trace[maxn + 2], space[maxn + 2];

int Check(string S){
	dp[0] = 1;
	
	for (int i = 0; i < S.size(); ++i){
		int pos = 0;
		for (int j = i + 1; j < S.size(); ++j){
			int c = S[j] - 'a';
			if (tries.nodes[pos].child[c] == -1) break;
			pos = tries.nodes[pos].child[c];
			if (tries.nodes[pos].exist){
				if (dp[i]) {
					if (dp[j] == 0) trace[j] = i;
					dp[j] = 1;
				}
			}
		}
	}
	
	return dp[S.size () - 1];
}

int main() {
    nothing
    if (fopen("ss.inp", "r")) {
        freopen("ss.inp", "r", stdin);
        freopen("ss.out", "w", stdout);
    }
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
    	cin >> s;
    	tries.add_string(s);
    }
    
    cin >> q;
    
    while (q--) {
    	memset(trace, -1, sizeof(trace));
		memset(space, 0, sizeof(space));
		memset(dp, 0, sizeof(dp));
		string s; cin >> s;
		s = "#" + s;
		if (Check(s) == 0){
			cout << -1 << endl;
			continue;
		}
		
		length = s.size() - 1;
		
		trace[0] = -1;
		space[length] = 1;
		
		while (length != -1){
			space[length] = 1;
			length = trace[length];
		}
		for (int i = 1; i < s.size(); ++i) 
			cout << s[i] << (space[i] ? " " : "");
		
		cout << endl;
    }
    return 0;
}

