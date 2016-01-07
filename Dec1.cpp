#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	long long t,n1,n2,m,removed;
	cin>>t;
	while(t--)
	{
		cin>>n1>>n2>>m;
		removed = min(min(n1,n2),(m*(m+1))/2);
		cout<<max(n1-removed,(long long)0) + max(n2-removed,(long long)0)<<"\n";
	}
	return 0;
}

