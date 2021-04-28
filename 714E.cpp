#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
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
bool check(int mask,int i){return ((1<<i)&mask);}
int Set(int mask,int i){return mask | (1<<i);}

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
ll power(ll a, ll b)
{
  if(b == 0)return 1;
  if(b==1)return a%MOD;
  ll p = power(a,b/2);
  p = mul(p,p);
  if(b%2==0)return p;
  return mul(p,a);
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE

int m,n,row,col;
ll ara[100005];
ll fact[100005];
ll invFact[100005];
void init()
{
  fact[0]=1;
  invFact[0]=1;
  for(ll i=1;i<100005;i++)
  {
    fact[i] = mul(fact[i-1], i);
    invFact[i] = power(fact[i],MOD-2);
  }
}
vector<ll>source,sink;
void solve(int test)
{
  scanf("%d",&n);
  ll sum=0;
  ll avg;
  for(int i=0;i<n;i++)scanf("%I64d",&ara[i]),sum+=ara[i];
  if(sum%(ll)n==0)
  {
    avg = sum/(ll)n;
    ll avgCnt=0,srcCnt=0,snkCnt=0;
    for(int i=0;i<n;i++)
    {
      if(ara[i]<avg)sink.pb(ara[i]);
      else if(ara[i]>avg)source.pb(ara[i]);
      else avgCnt++;
    }
    srcCnt = (ll)source.sz;
    snkCnt = (ll)sink.sz;
    if(srcCnt<=1 || snkCnt <=1)
    {
      //ans is n!
      ll ans = fact[n];
      sort(ara,ara+n);
      for(ll i=0;i<n;i++)
      {
        ll j=i+1;
        while(j<n&&ara[j]==ara[i])j++;
        ans = mul(ans,invFact[j-i]);
        i=j-1;
      }
      printf("%I64d\n",ans);
    }
    else
    {
      sort(source.begin(),source.end());
      sort(sink.begin(),sink.end());
      ll ans = mul(fact[srcCnt],fact[snkCnt]);

      for(ll i=0;i<srcCnt;i++)
      {
        ll j=i+1;
        while(j<srcCnt&&source[j]==source[i])j++;

        ans = mul(ans,invFact[j-i]);
        i=j-1;

      }

      for(ll i=0;i<snkCnt;i++)
      {
        ll j=i+1;
        while(j<snkCnt&&sink[j]==sink[i])j++;

        ans = mul(ans,invFact[j-i]);
        i=j-1;

      }

      ans = mul(ans, 2ll);

      ans = mul(ans,fact[srcCnt+snkCnt+avgCnt]);
      ans = mul(ans,invFact[srcCnt+snkCnt]);
      ans = mul(ans, invFact[avgCnt]);
      printf("%I64d\n",ans);
    }

  }
  else printf("0\n");

}
void test()
{
  int t=1;
  init();
  for(int test=1;test<=t;test++)
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
