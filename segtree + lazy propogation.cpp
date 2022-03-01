
struct seg{
   vll v, lazy;
   int sz = 1;
 
   seg(int len, int val ){
      while(sz <= len) sz *= 2;
      v.assign(4 * sz , 0ll);
      lazy.assign(4 * sz, 0ll);
   }
 
   ll qry(int l , int r , int x , int lx , int rx){
      if(lazy[x] != 0){
         v[x] += (rx - lx) * lazy[x];
         if(rx - lx > 1) {
            lazy[2 * x + 1] += lazy[x] ;
            lazy[2 * x + 2] += lazy[x] ;
         }
         lazy[x] = 0 ;
      }
 
      if(l >= rx or r <= lx) return 0;
      if(lx >= l and rx <= r) return v[x];
      int mid = lx + rx >> 1 ;
 
      return qry(l, r, 2 * x + 1 , lx, mid) + qry(l, r, 2 * x + 2 , mid, rx);
   }
 
   ll qry(int l , int r ){
      return qry(l, r, 0, 0, sz);
   }
   void upd(int l , int r ,ll val, int x , int lx , int rx ){
      if(lazy[x] != 0){
         v[x] += (rx - lx) * lazy[x];
         if(rx - lx > 1) {
            lazy[2 * x + 1] += lazy[x] ; 
            lazy[2 * x + 2] += lazy[x] ;
         }
         lazy[x] = 0 ;
      }
 
      if(l >= rx or r <= lx) return ;
      if(lx >= l and rx <= r) {
         v[x] += (rx - lx) * val;
         if(rx - lx > 1) {
            lazy[2 * x + 1] += val ;
            lazy[2 * x + 2] += val ;
         }
         return ;
      }
 
      int mid = lx + rx >> 1 ;
      upd(l, r, val, 2 * x + 1 , lx , mid);
      upd(l, r, val, 2 * x + 2 , mid, rx);
 
      v[x] = v[2 * x + 1] + v[2 * x + 2];
   }
   void upd(int l , int r , ll val){
      upd(l, r, val, 0 , 0 , sz);
   }
 
};
