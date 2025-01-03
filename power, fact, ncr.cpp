ll mod = 1e9 + 7;
int sz = 1000005;
ll fact[1000005];
ll ifact[1000005];
 
ll power(ll x, ll n) {
    if(n==0) return 1;
    x = x%mod;
    if(x==0) return 0; 
    ll pow = 1;
    while (n) {
        if (n & 1) pow = (pow*x)%mod;
        n = n >> 1;
        x = (x*x)%mod;
    }
    return pow;
}
 
ll inv_mod(ll x) { return power(x , mod - 2)%mod; }
 
void factorial() {
	fact[0] = fact[1] = 1;
	ifact[0] = ifact[1] = 1;
	for(int i = 2 ; i < sz ; i ++)
		fact[i] = (fact[i-1]*i)%mod;	
	ifact[sz-1] = inv_mod(fact[sz-1]);
	for(int i = sz-2 ; i > 0 ; i --)
		ifact[i] = (ifact[i+1]*(i+1))%mod;
}
 
ll ncr(ll n , ll r) {
	if(n<r || r<0) return 0;
	if(r == 0) return 1;
	return (((fact[n]*ifact[n-r])%mod)*ifact[r])%mod;
}
