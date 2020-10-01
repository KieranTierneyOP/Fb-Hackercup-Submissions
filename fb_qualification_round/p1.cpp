#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1001;
vector<ll> adj[51];
ll visited[51];
void dfs(ll i){
	if(visited[i])
		return;
	visited[i] = 1;
	ll j;
	for(j=0;j<adj[i].size();j++)
		dfs(adj[i][j]);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("output.txt", "w", stdout);
	freopen("travel_restrictions_input.txt", "r", stdin);
	ll i,j,k,n,r,t,q;
	cin>>t;
	string s1,s2;
	for(q=0;q<t;q++){
		cin>>n;
		cin>>s1>>s2;
		for(i=0;i<51;i++)
			adj[i].clear();
		for(i=1;i<n;i++){
			if(s1[i-1]=='Y' && s2[i]=='Y'){
				adj[i].pb(i-1);
			}
			if(s1[i]=='Y' && s2[i-1]=='Y'){
				adj[i-1].pb(i);
			}
		}
		cout<<"Case #"<<q+1<<":\n";
		for(i=0;i<n;i++){
			memset(visited, 0, sizeof(visited));
			dfs(i);
			for(j=0;j<n;j++){
				if(visited[j])
					cout<<"Y";
				else
					cout<<"N";
			}
			cout<<"\n";
		}


	}

	return 0;
}