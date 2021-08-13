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
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE

ll n,m,k;
ll answer(vector<ll> &x,int pos, int val)
{
  ll s = 30;
  ll sum = 0;
  for(int q=0;q<=pos;q++)
  {
    if(q==pos)sum += (1ll<<s)*val;
    else sum += (1ll<<s)*x[q];
    s--;
  }
  return sum;
}
void solve(int test)
{
  vector<ll> binN,binM,binX;
  scanf("%I64d%I64d",&n,&m);
  if(n > m)printf("0\n");
  else
  {
    int x = 31;
    for(int q=0;q<x;q++)
    {
      binN.pb(n%2);
      binM.pb(m%2);
      n/=2;
      m/=2;
    }
    reverse(binN.begin(),binN.end());
    reverse(binM.begin(),binM.end());

    ll ans = -1;
    for(int i=0;i<x;i++)
    {
      if(binN[i]==0 && binM[i]==0)
      {
        //put 1 and check.
        if(ans == -1)ans = answer(binX,i,1);
        else ans = min(ans, answer(binX,i,1));
        binX.pb(0);
      }
      else if(binN[i]==0 && binM[i]==1)
      {
        binX.pb(1);
      }
      else if(binN[i]==1 && binM[i]==1)
      {
        binX.pb(0);
      }
      else
      {
        ans = answer(binX,i,0);
        break;
      }
    }

    printf("%I64d\n",ans);

  }

}
void test()
{
  int t;
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
