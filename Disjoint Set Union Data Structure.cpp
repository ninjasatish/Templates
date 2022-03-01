struct dsu {
   // #define ll long long int
   
   vector<ll> par , siz ;
   ll components ;

   dsu (ll n){
      components = n ;
      par.assign(n + 1 , 0); siz.assign(n + 1, 1);
      for(ll i = 0; i <= n; ++i) par[i] = i ;
   }

   ll get(ll x){
      return x == par[x] ? x : par[x] = get(par[x]) ;
   }

   bool unite(ll x , ll y){
      x = get(x); y = get(y);
      if(x == y) return 0 ;
      if(siz[x] > siz[y]) swap(x , y);
      par[x] = y ;
      siz[y] += siz[x];
      components --;
      return 1 ;
   }

   ll getsize(ll x){
      return siz[get(x)] ;
   }

};
