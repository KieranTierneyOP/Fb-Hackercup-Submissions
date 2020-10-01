#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1001;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("alchemy_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll i,j,k,n,r,t,q,c;
	cin>>t;
	string s;
	for(q=0;q<t;q++){
		cin>>n;
		cin>>s;
		c = 0;
		for(i=0;i<n;i++)
			if(s[i]=='A')
				c++;
		cout<<"Case #"<<q+1<<":\n";
		if(abs(c-(n-c))>1)
			cout<<"N\n";
		else
			cout<<"Y\n";

	}

	return 0;
}