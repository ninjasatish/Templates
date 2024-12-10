
//   Geometry Template - By Satish  //
// cosine rule : a^2 = b^2 + c^2 – 2bc cos α

#define point complex<lld>
#define X real()
#define Y imag()
#define PI 3.141592653589793238462

lld dot(point x, point y){ // accurate
   return (conj(x) * y).X ;
}

lld cross(point x, point y){ // accurate
   return (conj(x) * y).Y  ;
}


point rotate(point x, lld angle, point p = point(0, 0)){ // precision
   // rotate point x w.r.t. point p with 'angle' Rad. similar scaling
   // default rotation is done w.r.t. origin (0, 0) counterclockwise
   return (x - p) * polar((lld)1.0, angle) + p ;
}

lld angle(point v, point w) { // precision
   lld cosTheta = dot(v,w) / abs(v) / abs(w);
   return acos(max((lld)-1.0, min((lld)1.0, cosTheta)));
}

lld orient(point a, point b, point c){ // accurate
   // orient(a, b, c) = ab X ac
   // positive if C is on left side of ab (counterclockwise of ab)
   return cross(b-a, c-a);
}

bool isConvex(vector<point> p) { // accurate
   // check if polygon is convex, points in the order of indices
   bool hasPos=false, hasNeg=false;
   for (int i=0, n=p.size(); i<n; i++) {
      lld o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
      if (o > 0) hasPos = true;
      if (o < 0) hasNeg = true;
   }
   return !(hasPos && hasNeg);
}

bool half(point p) { // true if angle is in [0, PI) false if [PI, 2*PI)
   assert(p.X != 0 || p.Y != 0); // the argument of (0,0) is undefined
   return p.Y > 0 || (p.Y == 0 && p.X > 0);
}

void polarSort(vector<point> &v) { // accurate
   sort(v.begin(), v.end(), [&](point x, point y){
      return make_tuple(!half(x), 0) < make_tuple(!half(y), cross(x, y));
  });
}

point intersectionLine(point a, point b, point p, point q) { // precision
   // finds intersection of infinite lines AB and PQ
   lld c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
   return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}

point project(point p, point v){ // precision
   // Project p onto vector v (line ov)
   return v * dot(p, v) / norm(v);
}

point reflect(point p, point a, point b){ // precision
   // reflect point p across line passing through ab
   return a + conj((p - a) / (b - a)) * (b - a);
}


struct line {
   point v; lld c;
   // From direction vector v and offset cons
   line(point dir, lld cons) { v = (dir), c = (cons); } 
   // From equation ax+by=cons (prefer not to use this due to bidirectional problems)
   // we don't know if direction is (-b, a) or (b, -a) so avoid using this if possible
   line(lld a, lld b, lld cons) { v = point({-b, a}), c= (cons) ;}
   // From points P and Q  -> line PQ
   line(point p, point q) { v = (q-p), c = (cross(v,p)) ;}
   
   lld side(point p){ // accurate
      return cross(v, p) - c ;
   }

   lld distLinePoint(point p) { // precision
      return abs(side(p)) / abs(v);
   }

   void LineSort(vector<point> &a){ // sort points along the line
      sort(a.begin(), a.end(), [&](point x, point y){
         return dot(v, x) < dot(v, y);
      }); // accurate
   }
}; 



/*------------ useful geometric functions ------*/

bool inDisk(point a, point b, point p) {// check if p lies inside circle with Daimeter AB
   return dot(a-p, b-p) <= 0;  // accurate
}
bool onSegment(point a, point b, point p) { // check if P lies on AB
   return orient(a,b,p) == 0 && inDisk(a,b,p); // accurate
}


point properIntersection(point a, point b, point c, point d) { // precision
   // used to return the only single point of intersection btw AB and CD
   lld oa = orient(c,d,a),
   ob = orient(c,d,b),
   oc = orient(a,b,c),
   od = orient(a,b,d);
   // Proper intersection exists iff opposite signs
   if (oa*ob < 0 && oc*od < 0) { // accurate
      point ans = (a*ob - b*oa) / (ob-oa);
      return ans;
   }
   return point(-2e9, -2e9);
}
point intersectionLineSegment(point a, point b, point c, point d) {
   // finds any point of intersection between AB and CD
   // returns {-2e9, -2e9} if no point is found !!
   if (onSegment(c,d,a)) return a;
   if (onSegment(c,d,b)) return b;
   if (onSegment(a,b,c)) return c;
   if (onSegment(a,b,d)) return d;
   return properIntersection(a,b,c,d) ;
}


lld areaTriangle(point a, point b, point c) {
   return abs(cross(b-a, c-a)) / 2.0;
}
lld areaPolygon(vector<point> &p) { // Risky!! careful sums can overflow
   ll area = 0;
   for (int i = 0, n = p.size(); i < n; i++) {
      ll x = cross(p[i], p[(i+1)%n]); 
      area += x;
   }

   return abs((lld)area / 2.0);
}


bool above(point a, point p) { // accurate
   // true if P at least as high as A (blue part)
   return p.Y >= a.Y;
}
bool crossesRay(point a, point p, point q) { // accurate
   // check if [PQ] crosses ray from A
   // casts a ray towards right if points are in counter-clockwise
   // otherwise casts ray towards left
   return (above(a,q) - above(a,p)) * orient(a,p,q) > 0;
}
int inPolygon(vector<point> &p, point a) { // accurate
   // -1 if pt(a) -> inside polygon, 0 if lies on a side, 1 otherwise
   int numCrossings = 0;
   for (int i = 0, n = p.size(); i < n; i++) {
      if (onSegment(p[i], p[(i+1)%n], a))
         return 0;
      numCrossings += crossesRay(a, p[i], p[(i+1)%n]);
   }

   return (numCrossings & 1 ? -1 : 1); // inside if odd number of crossings
}


ll ClosestPairDist(vector<point> &p, ll l, ll r){ // accurate
   // returns the square of the two closest points in range [l, r]
   if(l >= r) return 8e18 ;
   ll mid = (l + r) / 2 ;

   ll DisL = ClosestPairDist(p, l, mid);
   ll DisR = ClosestPairDist(p, mid + 1, r);

   ll allowD = min(DisL, DisR);

   vector<point> candidates ;
   for(auto i = l; i <= r; i ++){
      point v = p[i];
      ll d = v.X - p[mid].X;
      if(d * d <= allowD) candidates.push_back(v);
   }

   sort(all(candidates), [&](point x, point y){
      return x.Y != y.Y ? x.Y < y.Y : x.X < y.X ;
   });


   for(ll i = 0 ; i < sz(candidates); i ++){ // this won'b be n^2
      for(ll j = i + 1; j < sz(candidates) ; j ++){ 
         ll dx = candidates[i].X - candidates[j].X ;
         ll dy = candidates[i].Y - candidates[j].Y ;

         if(dy * dy >= allowD) break; // this limits to maximum 7 iterations
         allowD = min(allowD, dx * dx + dy * dy);
      }
   }

   return allowD;
}
ll ClosestPairDist(vector<point> &a){
   // returns the square of the two closest points
   sort(all(a), [&](point x, point y){
      return x.X == y.X ? x.Y < y.Y : x.X < y.X ;
   });

   return ClosestPairDist(a, 0, a.size() - 1) ;
}

vector<point> ConvexHull(vector<point> &p){ // accurate
   // returns the convex Hull of some set of points
   ll n = p.size();
   if(n <= 2) return p ;

   vector<point> up, down; // stores ans for top and bottom HULLS
   vector<point> active ; // acts as stack
   map<pll, ll> vis ; // helps avoid taking duplicates


   sort(all(p), [&](point x, point y){
      return x.X != y.X ? x.X < y.X : x.Y < y.Y ;
   });

   active.push_back(p[0]);
   active.push_back(p[1]);

   for(ll i = 2; i < n; i ++){
      while(active.size() > 1 and cross(active[active.size() - 1] - active[active.size() - 2], p[i] - active[active.size() - 2]) > 0){
         active.pop_back();
      }
      active.push_back(p[i]);
   }

   up = active ;
   active.clear();

   for(auto i: up) vis[{i.X, i.Y}] = 1 ;

   active.push_back(up[up.size() - 2]);
   active.push_back(up.back());

   for(ll i = n - 2; i > -1; i --){
      while(active.size() > 1 and cross(active[active.size() - 1] - active[active.size() - 2], p[i] - active[active.size() - 2]) > 0){
         active.pop_back();
      }
      active.push_back(p[i]);
   }

   down = active ;

   for(auto i: down) {
      if(not vis[{i.X, i.Y}]) up.push_back(i);
   }
   return up;
}