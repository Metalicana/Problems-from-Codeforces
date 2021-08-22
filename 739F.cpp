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

ll m,n,row,col,k;
ll mxn = 100000000000;
vector<ll>digits;
ll power(ll a, ll b)
{
  if(b == 0)return 1;
  if(b == 1)return a;
  ll x = power(a,b/2);
  if(b%2==0)return x*x;
  return x*x*a;
}
ll bruh(ll a,ll b)
{
  ll ans = 0;
  ll pw = power(10,m-b-1);
  for(int x=b;x<m;x++)
  {
    ans += a*pw;
    pw/=10;
  }
  return ans;
}
ll dp(int i,int mask,int tight)
{

  if(i>=m)
  {
    if(__builtin_popcount(mask) > k)return -1;
    return 0;
  }
  if(tight == 0)
  {
    //smallest number for the rest of em
    for(int q=0;q<=9;q++)
    {
      if(__builtin_popcount(Set(mask,q)) <= k)return bruh(q,i);
    }
  }
//  cout << i << " " << digits[i] << endl;

  //KEEP I
  ll ans1=-1,ans2=-1;
  ll y;
  ans1 = dp(i+1,Set(mask,digits[i]),tight);
  if(ans1 != -1)
  {
    ans1 += digits[i]*power(10ll,m-i-1);
    return ans1;
  }
  else
  {
    for(ll x =digits[i]+1; x<= 9;x++)
    {
      //if I use
      if(__builtin_popcount(Set(mask,x))<= k)
      {
        y = dp(i+1,Set(mask,x),0);
        if(y !=-1)
        {
          return y + x*power(10ll,m-i-1);;
        }
      }
    }
  }
  return -1;



}
void solve(ll test)
{

  scanf("%I64d%I64d",&n,&k);
  digits.clear();
  while(n)
  {
    digits.pb(n%10);n/=10;
  }
  m = digits.sz;
  reverse(digits.begin(),digits.end());
  cout << dp(0,0,1) << endl;


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
