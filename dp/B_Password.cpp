/*
  Ashutosh Singh
  Problem Link:-https://codeforces.com/contest/126/problem/B
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

vector<int> prefix_sum(string s)
{
    int n=s.length();
    vector<int> pf;
    pf.pb(0);
    fp(i,1,n-1)
    {
        int j=pf[i-1];
        while(j>0 && s[i]!=s[j])
        {
            j=pf[j-1];
        }
        if(s[i]==s[j])
            j++;
        pf.pb(j);
    }
    return pf;
} 
 
void solve()
{
    string s;
    cin >> s;
    vector<int> pf=prefix_sum(s);
    int l=pf[pf.size()-1];
    int flg=0;
    f(i,pf.size()-1)
    {
        if(pf[i]==l)
            {flg=1;break;}
    }
    if(flg==0)
        l=pf[l-1];
    if(l==0 || s.length()<3)
     cout << "Just a legend\n";
    else
     cout << s.substr(0,l) << '\n';
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
