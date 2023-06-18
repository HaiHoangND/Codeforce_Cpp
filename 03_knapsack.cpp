//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, b;
//int a[100], c[100];
//long long value_max = -1e9;
//long long value = 0;
//long long weight = 0;
//int vmax = -1e9;
//int weight_min = 1e9;
//int x[100];//order of items to put in sack
//bool visited[100];
//
//void input(){
//	cin >> n >> b;
//	for(int i = 1; i <= n; i++){
//		cin >> a[i] >> c[i];
//		if(weight_min > a[i]) weight_min = a[i];
//		if(vmax < c[i]) vmax = c[i];
//		visited[i] = false;
//	}
//}
//
//bool check(int v, int k){
//	if(visited[v]) return false;
//	if(weight + a[v] > b) return false;
//	return true;
//}
//
//void updateBest(){
//	if(value > value_max) value_max = value;
//}
//
//void Try(int k){
//	for(int v = k; v <= n; v++){
//		if(check(v, k)){
//			x[k] = v;
//			weight += a[x[k]];
//			value += c[x[k]];
//			visited[v] = true;
//			if(weight + weight_min > b) updateBest();
//			else{
//				if(value_max < (n-k)*vmax) Try(k+1);
//			}
//			weight -= a[x[k]];
//			value -= c[x[k]];
//			visited[v] = false;
//		}
//	}
//}
//
//int main(){
//	input();
//	Try(1);
//	cout << value_max;
//	return 0;
//}

//#include <bits/stdc++.h>//bai nay co so luong do vat han che, co nhieu nhat 1 do vat moi loai
//#define MAX 100
//
//using namespace std;
//
//int weight[MAX], value[MAX], n, W;
//
//int knapsack(int weight[], int value[], int n, int W){//n la so do vat, W la so kg co the dung toi da
//	int K[n+1][W+1],i,w;
//	for(i=0;i<=n;i++){
//		for(w=0;w<=W;w++){
//			if(i==0||w==0)
//				K[i][w] = 0;//khoi tao cho cac gia tri ban dau
//			else{
//				if(w < weight[i])//neu can nang dang xet hien tai nho hon loai can nang cua do vat VD: 1 < 3 
//					K[i][w] = K[i-1][w];//giu yen gia tri cua cai truoc do vi khong cong vao them duoc
//				else
//					K[i][w] = max(K[i-1][w], value[i] + K[i-1][w-weight[i]]);//xet co the them do vat do hay khong de tao ra 
//					//gia tri toi uu cho den hien tai, trong do K[i-1][w] nghia la ta khong chon no, value[i] + K[i-1][w-weight[i]] thi
//					//value[i] nghia la gia tri da chon va K[i-1][w-weight[i]] la gia tri toi uu cua phan da co tu truoc
//			}
//		}
//	}
//	return K[n][W];//gia tri cuoi cung la ket qua toi uu thu duoc
//}
//
//int main(){
//	cin >> n >> W;
//	for(int i = 1;i <= n; i++){
//		cin >> weight[i] >> value[i];
//	}
//	cout << knapsack(weight, value, n, W);
//	return 0;
//}

#include <bits/stdc++.h>

using namespace std;

int n, b;
int a[31], c[31];
int box[31];
int res = -1;
int cmax = -1, amin = 1e9;
int sumA = 0, sumC = 0;

void Try(int u){//gan gia tri cho o trong thu u
	if(u > n){
		if(sumA <= b) res = max(res, sumC);
		return;
	}
	if(sumC + cmax*(n-u+1) <= res) return;
	for(int i = 0; i <= 1; i++){
		if(sumA + a[u]*i > b) continue;
		box[u] = i;
		sumA += a[u]*box[u];
		sumC += c[u]*box[u];
		Try(u + 1);
		sumA -= a[u]*box[u];
		sumC -= c[u]*box[u];
	}
}

int main(){
	cin >> n >> b;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		amin = min(a[i], amin);
		cmax = max(c[i], cmax);
	}
	Try(1);
	cout << res;
	return 0;
}
