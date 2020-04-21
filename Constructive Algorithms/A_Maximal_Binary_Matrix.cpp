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
#define pii pair<int,int>
#define dbg(x) cout << (#x) << " is " << (x) << '\n' 
#define F first
#define S second
#define all(a) a.begin(),a.end()
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

void solve()
{ 
  int n,k;
  cin >> n >> k;
  if(k>n*n)
    {cout << -1 << '\n';return;}
  int mat[n+1][n+1];
  memset(mat,0,sizeof mat);
  if(k==0)
  {
      fp(i,1,n)
       fp(j,1,n)
        cout << mat[i][j]<< " \n"[j==n];
    return;
  }
  k--;
  int r=1,c=1;
  mat[r][c]=1;
  r++;
  while(k>=2)
  {
     if(mat[r][c]==0)
     {
         mat[r][c]=1;
        mat[c][r]=1;
        if(r!=c)
         k-=2;
        else
          k--;
     }
     r++;
     if(r>n)
       {
           c++;
           r=c;
       }
  }
  fp(i,1,n)
  {
      if(k==0)
        break;
      if(mat[i][i]==0)
        mat[i][i]=1,k--;
  }
  fp(i,1,n)
       fp(j,1,n)
        cout << mat[i][j]<< " \n"[j==n];
  return;
}

signed main()
{
  FAST
  int T=1;
  //  cin >> T;
  fp(i,1,T)
  {
    solve();
  }
  return 0;
}