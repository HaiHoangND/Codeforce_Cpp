//#include <bits/stdc++.h>
//
//using namespace std;
//
//int N, Q;
//int t[10005];
//int p[10005], c[10005];
//int r[10005];//result
//
//void input(){
//	r[0] = 1;
//	cin >> N;
//	for(int i = 1; i <= N; i++){
//		cin >> t[i];
//		if(i >= 2 && t[i] != t[i-1]){
//			r[0]++;
//		}
//	}
//	cin >> Q;
//	for(int i = 1; i <= Q; i++){
//		cin >> p[i] >> c[i];
//	}
//}
//
//int condition(int m, int n, int k){
//	if(m == 1){
//		if(t[1] != t[2]){
//			if(n == t[2]){
//				r[k] = r[k-1] - 1;
//				t[1] = n;
//			}else{
//				t[1] = n;
//				r[k] = r[k-1];
//			}
//		}else{
//			if(n != t[2]){
//				r[k] = r[k-1] + 1;
//				t[1] = n;
//			}else{
//				t[1] = n;
//				r[k] = r[k-1];
//			}
//		}	
//	}else{
//		if(m == N){
//			if(t[N] != t[N-1]){
//				if(n == t[N-1]){
//					r[k] = r[k-1] - 1;
//					t[N] = n;
//				}else{
//					t[N] = n;
//					r[k] = r[k-1];
//				}
//			}else{
//				if(n != t[N-1]){
//					r[k] = r[k-1] + 1;
//					t[N] = n;
//				}else{
//					r[k] = r[k-1];
//					t[N] = n;
//				}
//			}
//		}else{
//			if(t[m] == t[m-1] && t[m] == t[m+1]){
//				if(n != t[m]){
//					t[m] = n;
//					r[k] = r[k-1] + 2;
//				}else r[k] = r[k-1];
//			}
//			else{
//				if((t[m] == t[m-1] && t[m] != t[m+1]) || (t[m] != t[m-1] && t[m] == t[m+1])){
//					if(n == t[m-1] || n == t[m+1]){
//						t[m] = n;
//						r[k] = r[k-1];
//					}else{
//					t[m] = n;
//					r[k] = r[k-1] + 1;
//					}
//				}	
//				else{
//					if(t[m-1] != t[m+1]){
//						if(n == t[m-1] || n == t[m+1]){
//							t[m] = n;
//							r[k] = r[k-1] - 1;
//						}else{
//							t[m] = n;
//							r[k] = r[k-1];
//						}
//					}else{
//						if(n != t[m-1]){
//							t[m] = n;
//							r[k] = r[k-1];
//						}else{
//							t[m] = n;
//							r[k] = r[k-1] - 2;
//						}
//					}
//				}
//			}	
//		}
//	}
//}
//
//void print(){
//	for(int i = 1; i <= Q; i++){
//		cout << r[i] << endl;
//	}
//}
//
//void solve(){
//	for(int i = 1; i <= Q; i++){
//		condition(p[i], c[i], i);
//	}
//	print();
//}
//
//int main(){
//	input();
//	solve();
//	return 0;
//}
#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> vt;
int dgg;

// Tim do gap ghenh cua duong di trong lan dau tien
void findDGG(){
    dgg = 1;
    for(int i=1; i<n; i++){
        if(vt[i] != vt[i-1]) dgg++;
    }
}

// Doc vao do gap ghenh cua duong ban dau
void inputData1(){
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        vt.push_back(temp);
    }
    findDGG(); // dua vao do gap ghenh tai thoi diem hien tai (dgg)
}

// Ham xu ly do gap ghenh cua duong di sau moi lan thay doi
void handling(int temp1, int temp2){
    temp1--;

    int TFirst = 1; // Do gap ghenh tai doan [temp1-1,temp1+1] luc chua thay doi
    if(vt[temp1] != vt[temp1-1] && temp1-1 >= 0) TFirst++;
    if(vt[temp1+1] != vt[temp1] && temp1+1 < n) TFirst++;

    int TSecond = 1; // DO gan ghenh tai doan [temp1-1,temp1+1] luc da sua doi
    vt[temp1] = temp2; // sua lai duong temp1 bang loai nhua temp2
    if(vt[temp1] != vt[temp1-1] && temp1-1 >= 0) TSecond++;
    if(vt[temp1+1] != vt[temp1] && temp1+1 < n) TSecond++;

    int T = TSecond - TFirst;
    dgg = dgg + T;

    cout << dgg << endl;

}

// Doc nhung thay doi va xu ly tung thay doi
void inputData2(){
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int temp1;
        int temp2;

        cin >> temp1 >> temp2;

        // Xu ly tung test va dua ra ket qua
        handling(temp1,temp2);
    }
}
int main(){

    inputData1();
    inputData2();
    return 0;
}
