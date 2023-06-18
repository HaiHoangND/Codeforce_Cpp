#include <bits/stdc++.h>

using namespace std;

int A[1000005];
int n;
int TA[1000005];

void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
}

void merge(int A[], int L, int M, int R) {
	// tron 2 day da sap A[L..M] va A[M+1..R]
	int i = L; int j = M+1;//khai bao index dau cua 2 mang
	for(int k = L; k <= R; k++){
		if(i > M){ TA[k] = A[j]; j++;}//neu vuot ra ngoai 1 mang trong 2 thi cho tat ca cac phan tu con lai cua mang con lai vao TA[k]
		else if(j > R){TA[k] = A[i]; i++;}
		else{
			if(A[i] < A[j]){
				TA[k] = A[i]; i++;
			}
			else {
				TA[k] = A[j]; j++;
			}
		}
	}
	for(int k = L; k <= R; k++) A[k] = TA[k];//gan lai bien A[k] bang TA[k] da duoc sap xep
}

void mergeSort(int A[], int L, int R) {
	if(L < R){
		int M = (L+R)/2;
		mergeSort(A,L,M);
		mergeSort(A,M+1,R);
		merge(A,L,M,R);
	}
}

int main(){
	input();
	mergeSort(A,0,n-1);
	for(int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	return 0;
}

