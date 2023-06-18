#include <bits/stdc++.h>

using namespace std;
const int MAX = 2*1e6 + 5;

int n;
int s[MAX];
int t[MAX];
int c[MAX][3];//3 la xem co may quang thoi gian roi
pair<int,int> p[MAX];

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}

void input(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i] >> t[i];
		p[i].first = s[i];
		p[i].second = t[i];
	}
	sort(p+1, p+n+1, cmp);
	for(int i = 1; i <= n; i++){
		s[i] = p[i].first;
		t[i] = p[i].second;
	}
}

void solve(){
	c[t[1]][1] = t[1] - s[1];
	if(s[2] > t[1]) c[t[2]][2] = t[2] + t[1] - s[2] - s[1];
	for(int i = 2; i <= n; i++){
		c[t[i]][1] = t[i] - s[i];
		if(s[i] > t[i-1]) c[t[i]][2] = t[i] + t[i-1] - s[i] - s[i-1];
		for(int j = i-1; j >= 1; j--){
			if(s[i] > t[j] && c[t[i]][2] < c[t[i]][1] + c[t[j]][1]){
				c[t[i]][2] = c[t[i]][1] + c[t[j]][1];
				c[t[i]][2] = max(c[t[i]][2], c[t[i-1]][2]);
//				break;
//				cout << t[i] << " " << t[j] << endl;
			}
		}
	}
	cout << c[t[n]][2];
}

int main(){
	input();
	solve();
	return 0;
}

