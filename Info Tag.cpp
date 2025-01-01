struct Tag {
  int add = 0;
  
  void apply(const Tag &t) & {
    
  }
  
  bool operator==(const Tag &t) const {
    return add == t.add;
  }
};
struct Info {
  int mn = 1e9;
  void apply(const Tag &t) & {
    
  }
};
 
Info operator+(const Info &l, const Info &r) { // f(0, mid) “ + “ f(mid , n ) define “+” here
  return {min(l.mn, r.mn)};
}

// pred (find first function)

	auto predicate = [&](const Info &info) {
		if(info.val >= k) return true;
		k -= info.val;
		return false;
	};
