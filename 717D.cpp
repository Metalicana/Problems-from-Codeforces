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
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE

int n,q,l,r,x,m,ara[100005];
bitset<100005>nums;
vector<int>primes;
vector<int>pf_idx[100005];
vector<int>pf[100005];
int go[100005];
int jump[100005][25];
void siv()
{
  primes.pb(2);
  for(ll i=3;i<100005;i+=2)
  {
    if(!nums[i])
    {
      primes.pb(i);
      for(ll j=i*i;j<100005;j+=(2*i))nums[j]=1;
    }
  }
}

void solve(int test)
{
  scanf("%d%d",&n,&q);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&ara[i]);
    x=ara[i];
    for(int j=0;primes[j]*primes[j]<=x;j++)
    {
      if(x%primes[j]==0)
      {
        pf_idx[primes[j]].pb(i);//list all indices that have primes[j] as a prime divisor
        pf[i].pb(primes[j]);//list all prime divisors that occur in ara[i]
        while(x%primes[j]==0) x/=primes[j];
      }
    }
    if(x>1)
    {
      pf[i].pb(x);
      pf_idx[x].pb(i);
    }
  }
  go[n]=n;
  for(int i=n-1;i>=0;i--)
  {
    go[i] = go[i+1];
    for(int p : pf[i])//go through all the prime divisors
    {
      auto at = upper_bound(pf_idx[p].begin(),pf_idx[p].end(),i);
      int idx = at==pf_idx[p].end()?n:*at;
      go[i]=min(go[i],idx);
    }
  }
  for(int i=0;i<=n;i++)
  {
    jump[i][0]=go[i];
  }
    for(int i=1;i<=20;i++)
    {
      for(int idx=0;idx<=n;idx++)
      {
        jump[idx][i] = jump[jump[idx][i-1]][i-1];
        //trace(jump[idx][i])
      }

    }

  while(q--)
  {
    scanf("%d%d",&l,&r);
    int steps=1;
    l--;
    r--;
    for(int i =l, bit=19;bit>=0;bit--)
    {
    //  trace2(jump[i][bit],i)
      if(jump[i][bit]<=r)
      {
        steps+= 1<<bit;
        i = jump[i][bit];
      }
    }
    printf("%d\n",steps);
  }
}
void test()
{
  int t=1;
  siv();
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
