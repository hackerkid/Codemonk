#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int modularexponentiation(long long int a, long long int b, long long int c)
{   long long int ans=1;
    while(b !=0 )
    {   if(b&1)
            ans = (ans*a)%c;
        a = (a*a)%c;
        b = b>>1;
    }
return ans;
}
int main()
{	ios_base::sync_with_stdio(0);
	long long int n,i;
	cin>>n;
	long long int p=1,a[n],g=0;
	for(i=0;i<n;i++)
	{	cin>>a[i];
		p*=a[i];
		g = __gcd(g,a[i]);
	}
	cout<<modularexponentiation(p,g,mod)<<endl;;
    return 0;
}
