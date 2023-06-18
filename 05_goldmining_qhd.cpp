#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;

int n, L1, L2, ans;
int a[N];
int S[N];
deque<int> d;

void input(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> L1 >> L2;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
}

void solve(){
	ans = 0;
	for(int i = 1; i <= n; i++){
		while(!d.empty() && d.front() < i - L2) d.pop_front();
		int j = i - L1;
		if(j >= 1){
			while(!d.empty() && S[d.back()] < S[j]) d.pop_back();
			d.push_back(j);
		}
		S[i] = a[i] + (d.empty() ? 0 : S[d.front()]);
		ans = max(ans, S[i]);
	}
	cout << ans;
}

int main(){
	input();
	solve();
	return 0;
}

