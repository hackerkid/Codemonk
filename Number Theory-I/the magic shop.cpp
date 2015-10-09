#include <bits/stdc++.h>
using namespace std;
#define iOS ios_base::sync_with_stdio(0)
#define lli long long int
int main()
{	unsigned lli i,a,b,c=0;
	string n;
	cin>>a>>b>>n;
	for(i=0;i<n.length();i++)
	{	if(n[i]=='1')
		{	c=((c%b)+((a)%b))%b;
		}
		a = (a*a)%b;
	}
	cout<<c%b<<endl;
	return 0;
}
