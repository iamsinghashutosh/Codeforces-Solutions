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
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define f(i,n) for(int i=0;i<n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i++)
#define fr(i,k,n) for(int i=k;i>=n;i--)
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;


void solve()
{ 
  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  int dot[n+1]={0};
  int grp=0,cnt=0;
  fp(i,1,n)
  {
      if(s[i-1]=='.')
      {
          cnt++;
          if(i==1 || s[i-1]!=s[i-2])
            grp++;
          dot[i]=1;
      }
  }
//   cout << cnt << " " << grp << '\n';
  f(i,m)
  {
      int x;
      char c;
      cin >> x >> c;
      if(dot[x]==0)
        {
            if(c=='.')
                {
                    cnt++;
                    if((x==1 && dot[x+1]==0) || (x==n && dot[x-1]==0) || (dot[x-1]==0 && dot[x+1]==0))
                        grp++;
                    if(x!=1 && x!=n && dot[x-1]==1 && dot[x+1]==1)
                        grp--;
                    dot[x]=1;
                }
            cout << cnt-grp << '\n';
        }
      else
        {
            if(c!='.')
            {
                cnt--;
                if((x==1 && dot[x+1]==0) || (x==n && dot[x-1]==0) || (dot[x-1]==0 && dot[x+1]==0))
                    grp--;
                else if((x==1 && dot[x+1]==1) || (x==n && dot[x-1]==1) || (dot[x-1]==0 && dot[x+1]==1) || (dot[x-1]==1 && dot[x+1]==0))
                {}
                else
                grp++;
                dot[x]=0;
            }
            cout << cnt-grp << '\n';
        }
  }
 return;
}

signed main()
{
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
