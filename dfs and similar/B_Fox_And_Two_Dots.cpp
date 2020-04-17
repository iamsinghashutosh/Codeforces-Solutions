/*
  GOOD is not Enough
  You've got to be GREAT.
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// #include<boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define mod 1000000007
#define FAST ios: :sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i++)
#define fr(i,k,n) for(int i=k;i>=n;i--)
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

map<pii,vector<pii>> v;
map<pii,int> vis;
map<pii,pii> pa;
pii st,ed;

int dfs(pii pos)
{
    vis[pos]=1;
    for(pii i:v[pos])
    {
        if(vis[i]==0)
        {
            pa[i]=pos;
            if(dfs(i))
                return 1;
        }
        else if(vis[i]==1)
        {
            st=pos;
            ed=i;
            if(ed!=pa[st])
                return 1;
            else
            {
                st={-1,-1};
                ed={-1,-1};
            }
        }
    }
    vis[pos]=2;
    return 0;
}

void solve()
{ 
  int n,m;
  cin >> n >> m;
  string s[n];
  f(i,n)
    cin >> s[i];
   f(i,25)
   {
       pii pos;
       pos={-1,-1};
       map<pii,int> mp;
       v.clear();
       vis.clear();
       f(j,n)
       {
           f(k,m)
           {
               if(s[j][k]-'A'==i)
                {
                    pos={j,k};
                    if(k<m-1 && s[j][k+1]-'A'==i)
                    {
                        v[{j,k}].pb({j,k+1});
                        v[{j,k+1}].pb({j,k});
                        mp[{j,k}]=1;
                        mp[{j,k+1}]=1;
                    }
                    if(j!=n-1 && s[j+1][k]-'A'==i)
                    {
                        v[{j,k}].pb({j+1,k});
                        v[{j+1,k}].pb({j,k});
                        mp[{j,k}]=1;
                        mp[{j+1,k}]=1;
                    }
                }
           }
       }
       f(j,n)
       {
           f(k,m)
           {
                if(mp[{j,k}]==1)
                    {
                        if(vis[{j,k}]==0 && dfs({j,k})==1)
                        {
                            if(st.F!=-1 || st.S!=-1)
                            {
                                cout << "Yes\n";return;
                            }
                        }
                    }
           }
       }
   }
   cout << "No\n";
 return;
}

signed main()
{
  int T=1;
//   cin >> T;
  while(T--)
  {
    solve();
	}
  return 0;
}