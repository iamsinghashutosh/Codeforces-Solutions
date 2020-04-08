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
 int a,b,c,d;
 cin >> a >> b >> c>> d;
 string s;
  while(a>0)
  {
      s+="0";
      a--;
      if(b>0)
       s+="1",b--;
      if(b==0 && (a>0 && (c>0 || d>0)))
      {
          cout << "NO\n";return;
      }
  }
  if(b>0)
    s="1"+s,b--;
//   cout << s << '\n';
  while(b>0)
  {
        if(c==0)
        {
            cout << "NO\n";return;
        }
      if(c>0)
        s+="2",c--;
      
        s+="1",b--;   
  }
//   cout << s << '\n';
  while(c>0)
  {
       s+="2";
       c--;
    if(d==0 && c>0)
    {
        if(c==1 && s[0]=='1')
            s="2"+s,c=0;
        else
        {cout << "NO\n";return;}
    }
      if(d>0)
        s+="3",d--;
  }
  if(a==1)
  {
      if(s[0]=='1')
        s="0"+s,a=0;
      else if(s[s.length()-1]=='1')
        s=s+"0",a=0;
  }
  if(b==1)
  {
     if(s[0]=='0' || s[0]=='2')
        s="1"+s,b=0;
     else if(s[s.length()-1]=='0' || s[s.length()-1]=='2')
        s=s+"1",b=0;
  }
  if(c==1)
  {
      if(s[0]=='1' || s[0]=='3')
        s="2"+s,c=0;
     else if(s[s.length()-1]=='1' || s[s.length()-1]=='3')
        s=s+"2",c=0;
  }
  if(d==1)
  {
      if(s[0]=='2')
        s="3"+s,d=0;
     else if(s[s.length()-1]=='2')
        s=s+"3",d=0;
  }
  if(d==1 && s.length()==0)
    s="3",d=0;
  if(a==0 && b==0 && c==0 && d==0)
  {
     f(i,s.length()-1)
     {
         if(abs(s[i]-s[i+1])!=1)
         {cout << "NO\n";return;}
     }
  cout << "YES\n" ;
  f(i,s.length())
  {
      cout << s[i] << " \n"[i==s.length()-1];
  }
  }
  else
  cout << "NO\n";
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
