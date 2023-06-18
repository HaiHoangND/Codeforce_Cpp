#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 5;

int N;
int t[MAX];
int ans = -1;

bool cmp(int a, int b){
	return a > b;
}

void input(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> t[i];
	}
	sort(t, t + N, cmp);
}

void solve(){
	for(int i = 1; i <= N; i++){
		ans = max(ans, t[i-1] + i);
	}
	cout << ans + 1;
}

int main(){
	input();
	solve();
	return 0;
}

