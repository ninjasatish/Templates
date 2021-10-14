struct dsu {
   vector<int> v;
   int components ;
   dsu (int n ){
      components = n;
      v = vector<int>(n+1, -1);
   }

   int get(int x){
      return (v[x] < 0 ? x : v[x] = get(v[x]));
   }

   bool unite(int x , int y){
      x = get(x) ; y = get(y) ;
      if(x == y) return false;

      if(v[x] > v[y]) swap(x, y);

      v[x] += v[y];
      v[y] = x; 
      components --;
      return true;
   }

   bool same_set(int x, int y){
      return get(x) == get(y);
   }
   int size (int x){
      return -(v[get(x)]);
   }
};
