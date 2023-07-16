//Mem Opt
int marked[MAX/64 + 2];
#define isOn(x) (marked[x/64] & (1<<((x%64)/2)))
#define setOn(x)  marked[x/64] |= (1<<((x%64)/2))

//segmented
start=max(prime[i]*prime[i], ((low+prime[i]-1)/prime[i])*prime[i]);
for(j=start; j<=high; j+=prime[i])
   mark[j-low]=1;