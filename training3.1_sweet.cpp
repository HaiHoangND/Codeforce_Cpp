#include <bits/stdc++.h>

using namespace std;

int k, n, q;
int a[105];
int s = 0;
int ans = 0;

void input(){
	cin >> n >> k;
//	q = n;
}

void solution(){
	ans++;
}

bool check(int v, int h){
	if(h < k) return 1;
	return s + v == n+k;
}

void Try(int h){
	for(int v = 1; v <= n+k-s-(k-h); v++){
		if(check(v, h)){
			a[h] = v;
			s += a[h];
//			q -= a[h];
			if(h == k){
				solution();
			}
			else{
				Try(h+1);
			}
			s -= a[h];
//			q += a[h];
		}
	}
}

int main(){
	input();
	Try(1);
	cout << ans;
	return 0;
}

