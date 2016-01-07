#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

struct line{
	long long a,b,c;
	bool operator<(const line& l)const
	{
		if(a!=l.a)
			return a<l.a;
		if(b!=l.b)
			return b<l.b;
		if(c!=l.c)
			return c<l.c;
		return false;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	long long t,n,a,b,c,d,ans;
	cin>>t;
	while(t--)
	{
		ans = INT_MIN;
		set<line> s;
		map<pair<long long,long long>,long long> hash;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b>>c;
			d = gcd(gcd(a,b) , c);
			a/=d;
			b/=d;
			c/=d;
			//cout<<a<<" "<<b<<" "<<c<<"\n";
			line newline;
			newline.a = a;
			newline.b = b;
			newline.c = c;
			s.insert(newline);
		}
		//cout<<"\n\n";
		set<line>::iterator it = s.begin();
		while(it!=s.end())
		{
			d = gcd((*it).a,(*it).b);
			pair<long long,long long> p ((*it).a/d,(*it).b/d);
			if(hash.count(p) == 1)
				hash[p]++;
			else
				hash[p] = 1;
			ans = max(ans,hash[p]);
			it++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

