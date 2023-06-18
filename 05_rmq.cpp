#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6 + 5;

int n;
int a[MAXN];
int m;
//vector<int> v;
long long sumQ = 0;
pair<int,int> p[MAXN];

bool cmp(pair<int,int> c, pair<int,int> d){
	return c.first < d.first;
}

void solve(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		p[i].first = a[i];
		p[i].second = i;
	}
	sort(p, p+n, cmp);
	cin >> m;
	for(int i = 0; i < m; i++){
		int j, k;
		cin >> j >> k;
//		v.push_back(j);
//		v.push_back(k);
		for(int l = 0; l < n; l++){
			if(p[l].second >= j && p[l].second <= k){
				sumQ += p[l].first;
				break;
			}	
		}
	}
	cout << sumQ;
}

//void solve(){
//	s[0][1] = min(a[0], a[1]);
//	for(int i = 0; i < n-1; i++){
//		for(int j = i+1; j < n; j++){
//			if(s[i][j] == 0) s[i][j] = min(a[i], a[j]);
////			cout << "s[" << i << "][" << j << "] = " << s[i][j] << endl;
//			for(int k = i+1; k < j; k++){
//				if(s[i][k] == 0) s[i][k] = min(a[i], a[k]);
//				if(s[k][j] == 0) s[k][j] = min(a[k], a[j]);
//				int h = min(s[i][k], s[k][j]);
////				cout << "h = " << h << endl;
//				s[i][j] = min(s[i][j], h);
////				cout << "s[" << i << "][" << j << "] = " << s[i][j] << endl;
//			}
//		}
//	}
//	for(int i = 0; i < v.size(); i+=2){
//		sumQ += s[v[i]][v[i+1]]; 
//	}
//	cout << sumQ;
//}

int main(){
//	input();
	solve();
	return 0;
}

