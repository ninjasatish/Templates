#include <bits/stdc++.h>
using namespace std ;
using namespace chrono;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define ll long long 
#define ull unsigned long long
#define lld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define int128 __int128
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vi vector<int>
#define nline endl
#define inf (ll)1e18
#define iinf (int)2e9
#define eb emplace_back
#define vb vector<bool>
#define vll vector<ll> 
#define vvll vector<vll>
#define vpll vector<pll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define fs first
#define sc second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define oset ordered_set
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
#ifndef ONLINE_JUDGE
#define working cerr << "Working here.." << "\n" ;
#else
#define working 
#endif
 

void _print(__int128 x) {if (x < 0) { cerr <<('-'); x = -x; } if(x > 9) _print(x / 10); cerr << (ll)(x % 10 + '0');}
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T> void _print(stack<T> v);
template <class T> void _print(list<T> v);
template <class T> void _print(priority_queue<T> v);
template <class T> void _print(ordered_set<T> st);
template <class T, class V> void _print(unordered_map<T, V> m);
template <class T> void _print(deque<T> d);
 
template <class T> void _print(deque<T> d){cerr<<"[ "; for(auto i:d){_print(i);cerr << ' ';} cerr <<" ]";}
template <class T, size_t siz> void _print(const T (&array)[siz]){cerr << "{ "; for(ll i = 0; i < siz; ++i){_print(array[i]); cerr<<' ';} cerr<<"}";}
template <class T, class V> void _print(unordered_map<T, V> m){cerr<<"{ "; for(auto i: m){_print(i); cerr<<" ";} cerr<<"}";}
template <class T> void _print(ordered_set<T> st){cerr<<"{ ";for(auto i: st){_print(i);cerr<<" ";} cerr<<"}";}
template <class T> void _print(priority_queue<T> v){cerr<<"{ ";while(!v.empty()){_print(v.top()); cerr<<" "; v.pop();} cerr<<" }";}
template <class T> void _print(stack<T> v){cerr<< "[" ; while(!v.empty()){_print(v.top()); cerr<< " " ; v.pop();} cerr<< "]" ;}
template <class T> void _print(list<T> v) {cerr << "["; for(auto i: v){_print(i);cerr << " " ;} cerr<< "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fs); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template<typename T> void amin(T &a, T &b) { a = min(a, b); }
template<typename T> void amax(T &a, T &b) { a = max(a, b); }
/*--------------------------------------------------------------------------------------------------------------------------------*/
ll power(ll a, ll b){ll res = 1; while(b){if(b&1){res *= a;} b /=2; a*=a;} return res ;}
ll mod_pow(ll a, ll b, ll mod = (ll)(1e9 + 7)){if(b < 0 or a <= 0) return 0 ; ll res = 1; while(b){if(b&1){res = (res*a)%mod;} b /=2; a=(a*a)%mod;} return (res%mod) ;}
void usaco (string filename = ""){if(sz(filename)){ freopen((filename+ ".in").c_str() , "r", stdin); freopen((filename+ ".out").c_str() , "w", stdout); } }
inline ll modadd (ll a , ll b , ll mod = (ll)(1e9 + 7)){ return (a + b) - (a + b >= mod ? mod : 0); }
/*--------------------------------------------------------------------------------------------------------------------------------*/
struct custom_hash {
   static uint64_t splitmix64(uint64_t x) { x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x = (x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);}
   size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM); }
};
// int128 template for cin and cout
ostream& operator << (ostream &os, __int128 const& value) { static char buffer[64]; int index = 0; __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) os << '-'; else if (T == 0) return os << '0'; for (; T > 0; ++index) { buffer[index] = static_cast<char>('0' + (T % 10)); T /= 10; } while (index > 0) os << buffer[--index]; return os;}

istream& operator >> (istream& is, __int128& T) { static char buffer[64]; is >> buffer; size_t len = strlen(buffer), index = 0; T = 0; int mul = 1;
   if (buffer[index] == '-') ++index, mul *= -1; for (; index < len; ++index) T = T * 10 + static_cast<int>(buffer[index] - '0'); T *= mul; return is; }
/*---------------------------------------------------------------------------------------------------------------------------------*/
 
 
const ll mod = 1e9 + 7 , mod0 = 998244353, mod1 = 1e9 + 9 ;
const ll N = 1e5 + 10 ;

int rand(int l, int r){
   static mt19937 
   rng(chrono::steady_clock::now().time_since_epoch().count());
   uniform_int_distribution<int> ludo(l, r); 
   return ludo(rng);
}




void solve() {
   ll n = rand(1, 20);
   ll k = rand(1, n);

   cout << n << ' ' << k << endl;

   for(int i = 0 ; i < n; i ++){
      cout << rand(1, 1e5) << ' ' ;
   }
   cout << endl;


}
 
inline void testcases(){

   int test = 1, testcase = 1 ;
   cin >> test ;
   cout << test << nline;
   
   cout << setprecision(12) << fixed ;
   cerr << setprecision(4) << fixed ;
   while(test --){
      // cout << "Case #" << testcase++ << ": ";
      solve () ;
   } 
}
 
 
 
 
int main (){
   fastio();
 
   #ifndef ONLINE_JUDGE
      freopen("output.txt", "w", stdout);
      freopen("input.txt", "r", stdin);
      freopen("error.txt", "w", stderr);
   #endif
   
   chrono::steady_clock::time_point begin = chrono::steady_clock::now();
 
   testcases();
 
   chrono::steady_clock::time_point end = chrono::steady_clock::now();
   cerr << "[Finished in " << chrono::duration_cast<chrono::microseconds>(end - begin).count() / 1000 << "ms]" << endl;
 }