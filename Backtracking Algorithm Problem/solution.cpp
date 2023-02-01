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
int a[100],x[100], n;
ll k;
vector<vector<int>> v;
void nhap(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
}
void Try(int i){
	for(int j = 0; j <= 1; j++){
			x[i] = j;
			if(i == n){
				ll sum = 0;
				for(int c = 1; c <= n; c++){
					if(x[c]) sum += a[c];
				}
				if(sum == k){
					vector<int> tmp;
					for(int c = 1; c <= n; c++){
						if(x[c]) tmp.push_back(a[c]);
					}

					v.push_back(tmp);
				}
				}
			else Try(i + 1);
		}
}
int main(){
	faster();
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	nhap();
	Try(1);
	if(!v.empty()){
		sort(v.begin(),v.end());
		for(auto it : v){
			cout << "[";
			for(int i = 0; i < it.size() - 1; i++){
				cout << it[i] << ' ';
			}
			cout << it[it.size()-1] << "]" << endl;
		}
	}
	else cout << -1;
}



