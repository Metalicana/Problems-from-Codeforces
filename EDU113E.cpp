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
ll sub(ll a, ll b)
{
  if(a > b)return (a-b)%MOD;
  else
  {
    return (a+MOD-b)%MOD;
  }
}
ll fastExpo(ll b, ll p)
{
  if(p == 0)return 1;
  if(p == 1)return b%MOD;
  ll x = fastExpo(b,p/2);
  x = mul(x,x);
  if(p&1)return mul(x,b);
  return x;
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE

int m,n,row,col;
ll k,A,h;
map<ll,ll>pos;
map<ll,vector<ll>>kemneki;
bool arkoto = 0;
void funct(vector<ll>& list,ll val, ll depth,int tight,vector<ll> boss)
{
  if(arkoto == 1)return;
  if(list.sz == 1)
  {
    ll bruh = val;
    bruh = add(bruh, mul(list[0],fastExpo(A,2ll)));

    val = add(val, mul(list[0],A));
    // for(auto sex : boss)if(sex)cout<<sex<<" ";
    // cout  << endl;
    boss[list[0]]=1;
    kemneki[val] = boss;

    boss[list[0]]=2;
    kemneki[bruh] = boss;
    if(tight)
    {
      pos[val]  = 1;
      pos[bruh] = 1;
    }
    else
    {
      ll k = sub(h,val);
      if(pos[k])
      {
        for(auto sex : kemneki[k])if(sex)cout<< sex <<" ";
        boss[list[0]] = 1;
        //cout << endl;
        for(auto sex : boss)if(sex)cout<< sex << " ";
        cout << endl;
        arkoto = 1;
      }
      else
      {
        k = sub(h,bruh);
        if(pos[k])
        {
          for(auto sex : kemneki[k])if(sex)cout<< sex <<" ";
          boss[list[0]] = 2;
        //  cout << endl;
          for(auto sex : boss)if(sex)cout<< sex << " ";
          cout << endl;
          arkoto = 1;
        }
      }
    }
    return;
  }
  ll s = list.sz / 2;
  ll cost = (1<<depth) - (1<<(depth-1))+1;
  vector<ll>bist;
  for(ll i = 0; i < (1<<s); i++)
  {
    ll valk = val;
    bist.clear();
    for(ll j=0;j<s;j++)
    {
      if(!check(i,j))//2*j won
      {
        boss[list[2*j+1]] = cost;
        valk = add(valk, mul(list[2*j+1], fastExpo(A,cost)));
        bist.pb(list[2*j]);
      }
      else
      {
        boss[list[2*j]] = cost;
        valk = add(valk, mul(list[2*j], fastExpo(A,cost)));
        bist.pb(list[2*j+1]);
      }
    }
    funct(bist,valk,depth-1,tight,boss);
  }
}
void solve(int test)
{
  fastio
  arkoto = 0;
  scanf("%I64d%I64d%I64d",&k,&A,&h);
  if(k == 1)
  {
    ll c = add(mul(1ll,fastExpo(A,1ll)),mul(2ll,fastExpo(A,2ll)));
    if(c == h)printf("1 2\n");
    else
    {
      c = add(mul(1ll,fastExpo(A,2ll)),mul(2ll,fastExpo(A,1ll)));
      if(c== h)printf("2 1\n");
      else printf("-1\n");
    }
  }
  else
  {
    //upper half
    vector<ll>ok;
    vector<ll>bro((1<<k)+1);
    fill(bro.begin(),bro.end(),0);
    for(ll i=1;i<=(1<<(k-1));i++)ok.pb(i);
    funct(ok,0,k,1,bro);

    ok.clear();
    fill(bro.begin(),bro.end(),0);
    for(ll i=(1<<(k-1))+1;i<=(1<<(k));i++)ok.pb(i);
    funct(ok,0,k,0,bro);
    if(!arkoto)cout<<"-1\n";
  }

}
void test()
{
  int t=1;
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
