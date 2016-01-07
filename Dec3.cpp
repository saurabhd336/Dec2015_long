#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	long long t,n,a_len,b_len,min_a_len,min_b_len;
	cin>>t;
	while(t--)
	{
		min_a_len = min_b_len = INT_MAX;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			a_len = b_len = 0;
			cin>>str;
			for(int i=0;i<str.length();i++)
			{
				if(str[i] == 'a')
					a_len++;
				else
					b_len++;
			}
			min_a_len = min(min_a_len,a_len);
			min_b_len = min(min_b_len,b_len); 
		}
		cout<<min(min_a_len,min_b_len)<<"\n";
	}
	
	return 0;
}

