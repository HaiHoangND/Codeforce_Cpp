#include <bits/stdc++.h>

using namespace std;

const int MN = 1e5 + 5;

int n, L1, L2;
int a[MN];
int S[MN];//la luong hang max lay duoc khi dung tai cac tram 1, ..., i voi tong thoi gian lay hang bang t

void input(){
	cin >> n >> L1 >> L2;
	for(int i = 1; i <= n; i++) cin >> a[i];
}

void solve(){
	for(int i = 1; i <= n; i++)
		S[i] = 0;
	
	S[1] = a[1];
	
	for(int i = 2; i <= n; i++){
			
		S[i] = a[i];
			
		for(int j = i-L2; j <= i-L1; j++){
			if(j >= 1){
				if(S[i] < S[j] + a[i])
					S[i] = S[j] + a[i];
			}
		}
	}
	int ans = 0;
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

