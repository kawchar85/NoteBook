//implicit_seg_tree_sum.cpp
int t[siz],n,m,k,a[siz];	const int INF = 1e9+3e5;
class SGT {
	private:
		int ls[siz], rs[siz], tag[siz], head;
  	public:
		SGT(): head(0) {}
	int root;
	void modify(int &p, int id, int l = 1, int r = INF){
		if (!p) p = ++head;
		if(l == r) { tag[p] = 1; return; }
		int mid = (l + r) >> 1;
		if (id <= mid) modify(ls[p], id, l, mid);
		else if(id > mid) modify(rs[p], id, mid + 1, r);
		tag[p] = tag[ls[p]]+tag[rs[p]]; return;
	}
	int query(int p,int L,int R,int l = 1, int r = INF) {
		if (!p) return 0; if(l>R or r<L) return 0;
		if (L <= l && R >= r) return tag[p];
		int mid = (l + r) >> 1;
		return query(ls[p], L,R, l, mid)+query(rs[p], L,R, mid + 1, r);
	}
} seg;
int32_t main(){
    for(int i = 1;i<=n;i++) cin>>a[i];
    vector<pair<int,int> >v;
    for(int i = 1;i<=n;i++) cin>>t[i],v.pb({t[i],a[i]});
    sort(v.begin(),v.end());
    long long ans = 0;
    for(int i = n-1;i>=0;i--){
        int x = v[i].second,cost = v[i].first;
        int l = x,r = INF-5,cur = x;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(mid-x+1>seg.query(seg.root,x,mid)){
                cur = mid; r = mid-1;
            } else l = mid+1; }
        ans+=1LL*(cur-x)*cost; seg.modify(seg.root,cur);
    } cout<<ans<<"\n";	}
