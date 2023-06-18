#include <bits/stdc++.h>

using namespace std;

int N;
int ans = 0;
int pay;
int a[] = {1, 5, 10, 50, 100, 500};

void input(){
	cin >> N;
	pay = 1000 - N;
}

void solve(){
	for(int i = 5; i >= 0; i--){
		int n = pay / a[i];
		ans += n;
		pay = pay - n * a[i];
	}
	cout << ans;
}

int main(){
	input();
	solve();
	return 0;
}

