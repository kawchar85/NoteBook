// returns mu[x]  O(logn)
ll mu(ll x){ll cnt=0;while(x>1){ll cur=0,d=spf[x];
    while(x%d==0){x/=d;cur++;if(cur>1) return 0;}
    cnt++;}if(cnt&1) return -1;else return 1;}
// from 1 to n
void mobius(){mu[1] = 1;for(ll i=2;i<N;i++){
    mu[i]--;for(ll j=2*i;j<N;j+=i)mu[j]-=mu[i];}}