#include <bits/stdc++.h>

using namespace std;

struct triple{
	int x;
	int y;
 	int t;
	triple(int _x, int _y, int _t){
		x = _x;
		y = _y;
		t = _t;
	}
};

int n, m, r, c;
int a[1000][1000];
bool b[1000][1000];
//int ans;
queue<triple> q;

void input(){
	cin >> n >> m >> r >> c;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
}

int solve(){
	q.push(triple(r,c,0));
	b[r][c] = true;
	while(!q.empty()){
		triple u = q.front();q.pop();
		int d = u.x;
		int e = u.y;
		int f = u.t;
		if(d == n || d == 1 || e == m || e == 1){
			return f+1;
		}
		if(d + 1 <= n && b[d+1][e] == false && a[d+1][e] == 0){
			q.push(triple(d+1,e,f+1));
			b[d+1][e] = true;
		}
		if(d - 1 >= 1 && b[d-1][e] == false && a[d-1][e] == 0){
			q.push(triple(d-1,e,f+1));
			b[d-1][e] = true;
		};
		if(e + 1 <= m && b[d][e+1] == false && a[d][e+1] == 0){
			q.push(triple(d,e+1,f+1));
			b[d][e+1] = true;
		};
		if(e - 1 >= 1 && b[d][e-1] == false && a[d][e-1] == 0){
			q.push(triple(d,e-1,f+1));
			b[d][e-1] = true;
		};
	}
	return -1;
}

int main(){
	input();
	cout << solve();
	return 0;
}

