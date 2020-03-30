/*
  @Ashutosh Singh
  Problem Link:-https://codeforces.com/problemset/problem/522/A 
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define mod 1000000007
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i++)
#define fr(i,k,n) for(int i=k;i>=n;i--)
#define pb push_back
#define F first
#define S second
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

int visited[201]; 
vector<int> v[201];
int maxm=0,cnt=0;

void dfs(int s)
{
    visited[s]=1;
    cnt++;
    int x=cnt;
    for(int i=0;i<v[s].size();i++)
    {
        if(!visited[v[s][i]])
        {
            dfs(v[s][i]);
            maxm=max(cnt,maxm);
            cnt=x;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    map<string,int> m;
    int num=1;
    f(i,n)
    {
        string a,b,c;
        cin >> a >> b >> c;
        transform(a.begin(),a.end(),a.begin(), ::tolower);
        transform(c.begin(),c.end(),c.begin(), ::tolower);
        if(m[c]==0)
            m[c]=num++;
        if(m[a]==0)
            m[a]=num++;
        v[m[a]].pb(m[c]);
        v[m[c]].pb(m[a]);
    }
    dfs(1);
    cout << maxm<< '\n';
  return ;
}

signed main()
{
   FAST;
	int T=1;
	// cin >> T;
	while(T--)
	{
		solve();
	}
    return 0;
}
