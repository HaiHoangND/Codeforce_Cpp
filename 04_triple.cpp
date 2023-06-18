//#include <bits/stdc++.h>
//
//using namespace std;
//const int MAX = 5005;
//
//int N, K;
//int a[MAX];
//int Q = 0;
//
//void input(){
//	cin >> N >> K;
//	for(int i = 1; i <= N; i++){
//		cin >> a[i];
//	}
//	sort(a+1, a+N+1);
////	for(int i = 1; i <= N; i++){
////		cout << a[i] << " ";
////	}
////	cout << endl;
//}
//
//bool bSearch(int left, int right, int x){
//	int mid = left + (right - left) / 2 ;
//	if(left == right){
//		if(a[mid] == x) return true;
//		else return false;
//	}
//	if(a[mid] < x) return bSearch(mid + 1, right, x);
//	else if(a[mid] > x) return bSearch(left, mid , x);
//	else return true;
//}
//
//void solve(){
//	for(int i = 1; i < N-1; i++){
//		for(int j = i+1; j < N; j++){
//			int k = K - a[i] - a[j];//ba nay sai vi neu co 2 k dang truoc bang nhau thi no chi lay 1 k
//			if(bSearch(j+1, N, k)){
//				Q++;
////				cout << i << j << k << endl;
//			}
//		}
//	}
//	cout << Q;
//}
//
//int main(){
//	input();
//	solve();
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int n, K, cnt;
int a[MAX];

void inputData(){
    cnt = 0;
    cin >> n >> K;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

int bsearch(int first, int last, int key){
    if(first <= last){
        int mid = first + (last - first) / 2;
        if(a[mid] == key) return 1 + bsearch(first,mid-1,key) + bsearch(mid+1,last,key);
        else {
            if(a[mid] > key) return bsearch(first, mid-1, key);
            else return bsearch(mid+1, last, key);
        }
    }
    return 0;
}

int main(){
    inputData();
    sort(a,a+n);

    for(int i=0; i<n-2; i++)
        for(int j=i+1; j<n-1; j++){
            if(K-a[i]-a[j] <= 0) continue;
            int k = bsearch(j+1, n-1, K-a[i]-a[j]);
            cnt += k;
        }
    cout << cnt;
    return 0;
}
