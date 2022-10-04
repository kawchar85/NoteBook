/*Finds the primitive root modulo p. g is a primitive root 
modulo p if and only if for any integer a such that gcd(a,p)
=1, there exists an integer k such that: g^k = a(mod p)*/
int PrimitiveRoot (int p) {
  vector<int> fact;
  int phi = p-1; // if p is prime
  int n = phi;
  for(int i=2; i*i<=n; ++i){
    if(n%i == 0){
        fact.push_back (i);  while(n % i == 0)  n /= i; }  }
  if(n>1) fact.push_back (n);
  for(int res=2; res<=p; ++res){
    bool ok = true;
    for(size_t i=0; i<fact.size() && ok; ++i)
      ok &= BigMod (res, phi/fact[i], p) != 1;
    if (ok)  return res;
  }  return -1;  }
//find all numbers x such that x^k = a (mod n)
void printDiscreteRoot(int k, int a, int n){
	if(a==0){	cout<<"1\n0\n"; return;  }
 	int g=PrimitiveRoot(n);
 	int phi=n-1; //if n is not a prime calculate phi(n)
 	int sq=(int) sqrt(n+0.0)+1;
	vector<pair<int,int> > dec (sq);
	for(int i=1; i<=sq; ++i)
		dec[i-1]={BigMod(g, 1LL*i*sq%phi*k%phi,n), i};
 	sort(dec.begin(), dec.end());
 	int any_ans = -1;
 	for(int i=0; i<sq; ++i) {
 		int my=BigMod(g, 1LL*i*k%phi, n)*1LL*a%n;
 auto it=lower_bound(dec.begin(),dec.end(),make_pair(my,0));
	 	if(it != dec.end() && it->first == my){
 			any_ans = it->second * sq - i;	break;	} 	}
 	if(any_ans==-1){	cout<<"0\n"; return ; 	}
 	// all possible answers
  int delta = (n-1) / __gcd(k, n-1);
  vector<int> ans;
  for(int cur=any_ans%delta; cur<n-1; cur+=delta)
    ans.push_back(powmod(g,cur,n));
  sort(ans.begin(), ans.end());
  cout<<(int)ans.size()<<"\n";
  for(int answer : ans) cout<<answer<<" ";  }
