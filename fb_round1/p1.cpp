#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1001;
const int mmod = 1000000007;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("perimetric_chapter_1_input.txt", "r", stdin);		
	freopen("output.txt", "w", stdout);
	ll i,j,k,n,r,t,w,a1,b1,c1,d1,a2,b2,c2,d2,v,p1,p2,p3,p4;

	cin>>t;

	for(v=0;v<t;v++){
		cin>>n>>k>>w;
		ll l[k],h[k],l1,h1;

		for(i=0;i<k;i++)
			cin>>l[i];
		cin>>a1>>b1>>c1>>d1;

		for(i=0;i<k;i++)
			cin>>h[i];
		cin>>a2>>b2>>c2>>d2;

		// for(i=k;i<n;i++){
		// 	l[i] = (a1*l[i-2]+b1*l[i-1]+c1)%d1+1;
		// }
		// for(i=k;i<n;i++){
		// 	h[i] = (a2*h[i-2]+b2*h[i-1]+c2)%d2+1;
		// }

		ll ans,end,p,tmp;
		ans = 1;
		end = -1;
		p = 0;
		p1 = l[k-2];
		p2 = l[k-1];
		p3 = h[k-2];
		p4 = h[k-1];

		deque<pair<ll,ll>> dq;
		for(i=0;i<n;i++){
			if(i>=k){
				l1 = (a1*p1+b1*p2+c1)%d1+1;
				h1 = (a2*p3+b2*p4+c2)%d2+1;
				p1 = p2;
				p2 = l1;
				p3 = p4;
				p4 = h1;
			}
			else{
				l1 = l[i];
				h1 = h[i];
			}
			// cout<<"i: "<<i<<" l1: "<<l1<<" h1: "<<h1<<"\n";


			while(dq.size()>0){
				if(dq.front().first+w<l1)
					dq.pop_front();
				else
					break;
			}
			if(end>l1)
				p += 2*(l1+w-end);
			else
				p += 2*w;

			r = 0;
			for(j=0;j<dq.size();j++){
				r = max(r, dq[j].second);
			}			
			p += h1;
			p -= r;
			p += (max(h1,r)-min(h1,r));
			// cout<<"i: "<<i<<" p: "<<p<<"\n";
			p = p%mmod;
			ans *= p;
			ans = ans%mmod;
			end = l1+w;
			dq.pb(make_pair(l1, h1));
		}	

		cout<<"Case #"<<v+1<<": "<<ans<<"\n";
	}


	return 0;
}