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

ll m,n,row,col;
//turn n into a vector
//left align with 2^k vector
//digit mismatchmeans 1+ cost
//size mismatch cost+
ll toteCost(ll n)
{
  vector<ll> mainVector;
  while(n!=0)
  {
    mainVector.pb(n%10);
    n/=10;
  }
  reverse(mainVector.begin(),mainVector.end());


  vector<ll> varVector;
  ll k = 0;
  ll ans = 100000000;
  for(ll ii=0;ii<=60;ii++)
  {
    k = (1ll<<ii);
    //cout << k << endl;
    varVector.clear();
    while(k!=0)
    {
      varVector.pb(k%10);
      k/=10;
    }
    reverse(varVector.begin(),varVector.end());

    ll i=0,j=0;
    ll del=0;
    while(true)
    {
      if(i>=mainVector.sz)
      {
        break;
      }
      else if(j>=varVector.sz)
      {
        break;
      }
      else if(mainVector[i]!=varVector[j])
      {
        i++;
        del++;
      }
      else if(mainVector[i] == varVector[j])
      {
        i++;
        j++;
      }
    }
    //cout << del+varVector.sz-j+mainVector.sz-i<< endl;
    ans = min(ans,(ll)(del+varVector.sz-j+mainVector.sz-i));
    //cout << ans << endl;

  }
  return ans;
}

void solve(int test)
{
  scanf("%I64d",&n);
  printf("%I64d\n",toteCost(n));
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
