#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e4 + 5;

int n;
int a[MAXN];
int S[MAXN];
int ans = 0;

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
}

void solve(){
	for(int i = 1; i <= n; i++){
		S[i] = 0;
	}
	S[1] = 1;
	for(int i = 2; i <= n; i++){
		S[i] = 1;
		for(int j = 1; j <= i-1; j++){
			if(a[i] > a[j] && S[i] < S[j] + 1){
				S[i] = S[j] + 1;
			}
		}
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

