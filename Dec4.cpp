#include<bits/stdc++.h>
using namespace std;
 
#define mod 1000000007;
int max_val = 1<<10;
static int dp[100001][1<<10];

long long solve(vector<int>& v, int key,int pos,int val)
{
	if(pos>=v.size())
		return 0;
	if(dp[pos][key]!=-1)
		return dp[pos][key];
	if(val^v[pos] == key)
	{
		dp[pos][key] = 1 + solve(v,key,pos+1,val) + solve(v,key,pos+1,val^v[pos]);
		return dp[pos][key] %= mod;
	}
	dp[pos][key] = solve(v,key,pos+1,val) + solve(v,key,pos+1,val^v[pos]);
	return dp[pos][key] %= mod;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	string s,str;
	long long t,n;
	int key;
	cin>>t;
	int pow[10];
	pow[0] = 1;
	for(int i=1;i<10;i++)
		pow[i] = pow[i-1]*2;
	
	while(t--)
	{
		vector<int> v;
		cin>>s;
		key = 0;
		for(int i=0;i<10;i++)
			if(s[i] == 'w')
				key += pow[9-i];
		
		cin>>n;
		v.push_back(-1);
		for(int i=0;i<n;i++)
		{
			int val = 0;
			cin>>str;
			for(int i=0;i<10;i++)
			if(str[i] == '+')
				val += pow[9-i];
			v.push_back(val);
		}
		
		for(int i=0;i<=n;i++)
			for(int j=0;j<max_val;j++)
				dp[i][j] = -1;
		
		dp[0][0] = 1;
		
		for(int i=1;i<max_val;i++)
			dp[0][i] = 0;
		
		solve(v,key,0,0);
		
		printf("%d\n",dp[n][key]);
	}
	return 0;
}
