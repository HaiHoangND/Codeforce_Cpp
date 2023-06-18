#include <bits/stdc++.h>

using namespace std;

long long n;
int b;
long long a[200005];
long long L[200005];//record the max value's index on left of element has index i
long long R[200005];//record the max value's index on right of element has index i

void input(){
	cin >> n >> b;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
}

void solve(){
	bool test = false;
	int m;
	L[1] = 1;
	for(int i = 2; i <= n-1; i++){
		if(a[i] < a[L[i-1]]) L[i] = L[i-1];
		else L[i] = i;
	}
	R[n] = n;
	for(int i = n-1; i >= 2; i--){
		if(a[i] < a[R[i+1]]) R[i] = R[i+1];
		else R[i] = i;
	}
	long long max = -1;
	for(int i = 2; i <= n-1; i++){
		if(a[L[i]] - a[i] >= b && a[R[i]] - a[i] >= b){
			if(max < a[L[i]] + a[R[i]] - 2*a[i]) max = a[L[i]] + a[R[i]] - 2*a[i];
			test = true;
		}
	}
	if(test) cout << max;
	else cout << -1;
}

int main(){
	input();
	solve();
	return 0;
}
