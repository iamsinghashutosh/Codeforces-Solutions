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

const int sz=200005;
int BIT[sz],n;
string s;

void update(int pos,int val)
{
  while(pos<=n)
  {
    BIT[pos]+=val;
    pos+=(pos&(-pos));
  }
}

int sum(int pos)
{
  int res=0;
  while(pos>0)
  {
    res+=BIT[pos];
    pos-=(pos&(-pos));
  }
  return res;
}

int get(int pos)
{
  int low=0,high=n+1;
  while(low<high)
  {
    int mid=(low+high)/2;
    if(sum(mid)>=pos)
      high=mid;
    else
      low=mid+1;
  }
  return low;
}


void solve()
{
  int m;
  cin >> n >> m;
  cin >> s;
  s="c"+s;
  map<char,set<int> > nxt ;
  fp(i,1,n)
  {
    nxt[s[i]].insert(i);
    update(i,1);
  }
  while(m--)
  {
    int l,r;
    cin >> l >> r;
    char c;
    cin >> c;
    l=get(l);
    r=get(r);
    vector<int> pos;
    for(auto itr=nxt[c].lower_bound(l);itr!=nxt[c].end();itr++)
    {
      if(*itr<=r)
      {
        pos.pb(*itr);
      }
      else
        break;
    }
    f(i,pos.size())
    {
      update(pos[i],-1);
      nxt[c].erase(pos[i]);
    }
  }
  fp(i,1,n)
  {
    if((sum(i)-sum(i-1))==1)
    {
      cout << s[i] ;
    }
  }
  cout << '\n';
  return;
} 

signed main()
{
  FAST
  int T=1;
  // cin >> T;
  while(T--)
  {
    solve();
  }
  return 0;
}
