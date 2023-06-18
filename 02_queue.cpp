//#include <bits/stdc++.h>
//
//using namespace std;
//const int MAX = 1e5 + 5;
//
//int n;
//int a[MAX];
//pair<int,int> p[MAX];
//
//bool cmp(pair<int,int> c, pair<int,int> d){
//	return c.first < d.first;
//}
//
//bool recmp(pair<int,int> c, pair<int,int> d){
//	return c.second < d.second;
//}
//
//void input(){
//	cin >> n;
//	for(int i = 0; i < n; i++){
//		cin >> a[i];
//		p[i].first = a[i];
//		p[i].second = i;
//	}
//	sort(p, p + n, cmp);
//}
//
//void solve(){
//	int maxP = p[0].second;
//	for(int i = 0; i < n; i++){
//		if(maxP < p[i].second) maxP = p[i].second;
//		p[i].first = maxP - p[i].second - 1;
//	}
//	sort(p, p + n, recmp);
//	for(int i = 0; i < n; i++){
//		cout << p[i].first << " ";
//	}
//}
//
//int main(){
//	input();
//	solve();
//	return 0;
//}
#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 5;

int n;
int a[MAX];
int b[MAX];
pair<int,int> p[MAX];
void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		p[i].first = a[i];
		p[i].second = i;
	}
	sort(p, p + n);
}

void solve(){
	int maxP = p[0].second;
	for(int i = 0; i < n; i++){
		if(maxP < p[i].second) maxP = p[i].second;
		b[p[i].second] = maxP - p[i].second - 1;
	}
}

int main(){
	input();
	solve();
    for(int i = 0; i < n; i++) cout<<b[i]<<" ";
	return 0;
}
