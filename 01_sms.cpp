#include <iostream>
#include <string>
 
using namespace std;

string str1 = "abc def ghi jkl mno pqrs tuv wxyz";
int a[1000];

void assign(){
	int j = 1;
	for(int i = 0; i < str1.length(); i++){
		if(str1[i] != ' '){
			a[str1[i]] = j;
			j++;
		}
		else j = 1;
	}
	a[' '] = 1;
}

void solve(string s, int i){
	int sum = 0;
	for(int k = 0; k < s.length(); k++){
		sum += a[s[k]];
	}
	cout << "Case #" << i << ": " << sum << endl;
}
 
int main(){
	assign();
	int n = 0, i = 0;
	string str;
	getline(cin,str);
	while(str[i] == ' ') i++;
	while(str[i] >= '0' && str[i] <= '9'){
		n = n*10 + (str[i] - '0');
		i++;
	}
	if(i == str.length()){
		for(int k = 1; k <= n; k++){
			string s;
			getline(cin, s);
			solve(s,k);
		}
	}
	else{
		int sum = 0;
		for(int k = i+1; k < str.length(); k++){
			sum += a[str[k]];
		}
		cout << "Case #1: " << sum << endl;
		for(int k = 2; k<= n; k++){
			string s;
			getline(cin, s);
			solve(s,k);
		}
	}
	return 0;
}
//#include<iostream>
//#include<string>
//using namespace std;
// 
// 
//string s1="abc def ghi jkl mno pqrs tuv wxyz";
//int a[1000];
//void xuli()
//{
//    int j=0,i;
//    for (i=0;i<s1.length();i++)
//    if (s1[i]==' ') j=0;
//    else { j++;
//            a[s1[i]]=j;
//    }
//}
//void try1(string s,int i)
//{
//	int j=0;
//	int point=0;
//	if (s[0]==' ') point=-1;
//    for (j=0;j<s.length();j++)
//    point+=a[s[j]];
//    cout<<"Case #"<<i<<": "<<point<<"\n";
//}
//int main()
//{
//	xuli();
//    int n=0;
//    a[' ']=1;
//    string q;
//    int j=0;
//    getline(cin,q);
//    while (q[j]==' ') j++;
//    while ((q[j]>='0')&&(q[j]<='9')) 
//	{	n=n*10+(q[j]-'0');
//	    j++;    }
//	if (j==q.length()) {
//		for (int i=1;i<=n;i++)
//		    { 
//		      string s;
//		      getline(cin,s);
//		      try1(s,i);
//		    }
//	}
//	else { 
//	    string s;
//	    for (int k=j;k<q.length();k++)
//	    s=s+q[k];
//		try1(s,1);
//		for (int i=2;i<=n;i++)
//		    { 
//		      string s;
//		      getline(cin,s);
//		      try1(s,i);
//		    }
//	}
//    
//    return 0;
//}
