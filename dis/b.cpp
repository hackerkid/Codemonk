#include <iostream>
#include <map>

#define SIZE 100006


using namespace std;

int dj_a[SIZE];
int dj_size[SIZE];
int parent[SIZE];
int count[SIZE];
int cost[SIZE];

int dj_parent(int x)
{

	if(dj_a[x] == x) {
		return x;
	}

	else {
		dj_a[x] = dj_a[dj_a[x]];
		x = dj_a[x];
		return dj_parent(x);
	}

}

int dj_union(int x, int y)
{
	int par_a;
	int par_b;

	if(dj_parent(x) == dj_parent(y)) {
		return 0;
	}

	par_a = dj_parent(x);
	par_b = dj_parent(y);

	if(dj_size[par_a] > dj_size[par_b]) {
		dj_a[par_b] = par_a;
		dj_size[par_a] = dj_size[par_a] + dj_size[par_b];
	}

	else {
		dj_a[par_a] = par_b;
		dj_size[par_b] = dj_size[par_a] + dj_size[par_b];
	}

}

int find(int x, int y)
{

	if(dj_parent(x) == dj_parent(y)) {
		return true;
	}

	else {
		return false;
	}

}



int main()
{
	int n;
	int m;
	int x;
	int y;
	long long ans;
	long long mod;

	mod = 1e9+7;

	ans = 1;

	map <int, int> mp;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		dj_a[i] = i;
		dj_size[i] = 1;
		cin >> cost[i];
	}

	cin >> m;


	for (int i = 0; i < m; i++) {
		cin >> x;
		cin >> y;
		dj_union(y, x);
	}


	for (int i = 1; i <= n; i++) {
		parent[i] = dj_parent(i);

	}

	for (int i = 1; i <= n; i++) {
		if(mp.count(parent[i]) == 0) {
			mp[parent[i]] = cost[i];
			count[parent[i]] = 1;
		}

		else {
			if(mp[parent[i]] >  cost[i]) {
				mp[parent[i]] = cost[i];
				count[parent[i]] = 1;
			}

			else {
				if(mp[parent[i]] == cost[i]) {
					count[parent[i]]++;
				}
			}
		}
	}

	for (int i = 1; i <=n; i++) {
		if(count[i] != 0) {
			ans = ans * count[i];
			ans = ans % mod;
		}

	}

	cout << ans << endl;

	
}


