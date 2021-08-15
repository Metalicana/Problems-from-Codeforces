#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);i++)
#define x first
#define y second
#define gap ' '
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define eps 1e-9
#define maxn 100000
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}
bool check(ll mask,ll i){return ((1<<i)&mask);}
ll Set(ll mask,ll i){return mask | (1<<i);}

ll add(ll a, ll b)
{
  if(a+b<MOD)return a+b;
  return (a+b)%MOD;
}
ll mul(ll a, ll b)
{
  if(a*b < MOD)return a*b;
  return (a*b)%MOD;
}
ll dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
ll dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE

ll m,n,row,col;
ll ara[200005];
ll tree[800005];
vector<ll>dif;
struct segtree
{
  #define LEFT (node<<1)
  #define RIGHT (node<<1|1)
  #define MID (b+e>>1)
  ll tree[800005];
  void init(int node,int b,int e)
  {
    if(b==e)
    {
      tree[node] = dif[b];
      return;
    }
    init(LEFT,b,MID);
    init(RIGHT,MID+1,e);
    tree[node] = __gcd(tree[LEFT],tree[RIGHT]);
  }
  ll query(int node,int b,int e,int i,int j)
  {
    if(b>j||e<i)return 0;
    if(b>=i&&e<=j)return tree[node];
    ll p1,p2;
    p1 = query(LEFT,b,MID,i,j);
    p2 = query(RIGHT,MID+1,e,i,j);
    if(p1==0)return p2;
    if(p2 == 0)return p1;
    return __gcd(p1,p2);
  }
}seg;



void solve(ll test)
{
  dif.clear();
  scanf("%I64d",&n);
  for(ll i=0;i<n;i++)scanf("%I64d",&ara[i]);
  for(ll i=1;i<n;i++)
  {
    if(ara[i]-ara[i-1] == 0)dif.pb(ara[i]);
    else dif.pb(abs(ara[i]-ara[i-1]));
  }
  ll s = dif.size();

  if(s==0)
  {
    printf("1\n");
    return;
  }
  seg.init(1,0,s-1);
  ll gcd;
  ll ans = 1;
  int i=0;
  int j=0;
  gcd = dif[i];
  while(i<s  && j<s)
  {

    gcd = seg.query(1,0,s-1,i,j);
    if(gcd>1)
    {
      ans = max(ans,(ll)(j-i+2));
      j++;
    }
    else
    {
      ans = max(ans,(ll)(j-i+1));
      if(i==j)
      {
        i++;j++;continue;
      }
      //from j to i+1, how far can you go till gcd is > 1
      int b = i+1;
      int e = j;
      if(b==e)
      {
        i++;
        continue;
      }
      while(b<e)
      {
        if(b+1==e)
        {
          if(seg.query(1,0,s-1,b,j)>1)i=b;
          else i=e;
          break;

        }
        if(seg.query(1,0,s-1,(b+e)>>1,j)>1)e=(b+e)>>1;
        else b=(b+e)>>1;
      }
    }
  }
  for(ll i=0;i<n;i++)
  {
    if(ara[i]!=1)continue;
    j = i+1;

    while(j<n && ara[i]==ara[j])j++;
    ans=max(ans,j-i);
    i=j-1;
  }
  printf("%I64d\n",ans);

}
void test()
{
  ll t;
  scanf("%I64d",&t);
  for(ll test=1;test<=t;test++)
  {
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
