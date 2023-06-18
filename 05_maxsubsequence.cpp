#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6 + 5;

int n;
int a[MAXN];
int S[MAXN];
int ans = -1e9;

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
}

void solve(){
	S[1] = a[1];
	for(int i = 2; i <= n; i++){
		if(S[i-1] < 0) S[i] = a[i];
		else S[i] = a[i] + S[i-1];
	}
	for(int i = 1; i <= n; i++){
		ans = max(ans, S[i]);
	}
	cout << ans;
}

int main(){
	input();
	solve();
	return 0;
}

