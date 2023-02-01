#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
int a[100][100],n;
bool used[1000][1000];
string s;
vector<string> v;
void nhap(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}	
	}
}
void Try(int i, int j, string s){
	if(i == n && j == n){
		v.push_back(s);
	}
	if(a[i+1][j] == 1 && i + 1 <= n && !used[i + 1][j]){
		used[i][j] = true;
		Try(i+1,j,s + "D");
		used[i][j] = false;
	}
	if(a[i][j+1] == 1 && j + 1 <= n && !used[i][j+1]){
		used[i][j] = true;
		Try(i,j+1,s + "R");
		used[i][j] = false;
	}
	if(a[i][j-1] == 1 && j - 1 >= 1 && !used[i][j-1]){
		used[i][j] = true;
		Try(i,j-1,s + "L");
		used[i][j] = false;
	}
	if(a[i-1][j] == 1 && i - 1 >= 1 && !used[i-1][j]){
		used[i][j] = true;
		Try(i-1,j,s + "U");
		used[i][j] = false;
	}

}
int main(){
	faster();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	nhap();
	Try(1,1,"");
	if(v.empty()){
		cout << -1;
	}
	else{
		sort(v.begin(),v.end());
		for(auto it : v) cout << it << endl;
	}
}



