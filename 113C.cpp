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
#define MOD 998244353
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

ll sub(ll a, ll b)
{
  if(a-b < 0)
  {
    ll c = a-b;
    while(c < 0)c+=MOD;
    return c;
  }
  return a-b;
}
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
  if(b==0)return 1;
  if(b==1)return a%MOD;
  ll x = power(a,b/2);
  x = mul(x,x);
  if((b&1)==0)return x;
  return mul(x,a);
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE

int m,n,row,col;
ll ara[200005];
ll fact[200005];
ll invFact[200005];
ll ncr(ll a, ll b)
{
  return mul(fact[a],mul(invFact[b],invFact[a-b]));
}
void solve(int test)
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%I64d",&ara[i]);
  sort(ara,ara+n);
  if(ara[n-1] - ara[n-2] <= 1)
  {
    if(ara[n-1]==ara[n-2])
    {
      printf("%I64d\n",fact[n]);
    }
    else
    {
      int cnt = lower_bound(ara,ara+n,ara[n-2])-ara;
      cnt = n-1-cnt;
      ll sum = 0;
      for(ll q = cnt;q<n;q++)
      {
        sum = add(sum , ncr(q,cnt));
      }
      sum = mul(sum,fact[n-cnt-1]);
      sum = mul(sum,fact[cnt]);
      sum = sub(fact[n],sum);
      printf("%I64d\n",sum);
    }
  }
  else printf("0\n");
}

void test()
{
  int t;
  fact[0] = invFact[0] = 1;
  fact[1] = invFact[1] = 1;
  for(ll i=2;i<=200002;i++)
  {
    fact[i] = mul(fact[i-1],i);

    //invFact[i] = power(fact[i],MOD-2);
  }
  invFact[200002] = power(fact[200002],MOD-2);
  for (ll i = 200001; i >= 1; i--)
	{
    	invFact[i] = mul(invFact[i+1], i + 1);
  }
  scanf("%d",&t);
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
