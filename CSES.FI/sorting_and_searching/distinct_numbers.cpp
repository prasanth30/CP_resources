#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main(){
	int n,x;cin>>n;
	set<int> s;
	for(int i=0;i<n;i++){
		cin>>x;
		s.insert(x);
	}
	cout<<s.size();
	return 0;
}
