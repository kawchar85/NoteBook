int get(int ind){
  int ret = 0;
  for(;ind>0;ind-=ind&-ind) ret+=ft[ind];
  return ret; }
void upd(int ind,int val){
  for(;ind<=n;ind+=ind&-ind) ft[ind]+=val; }
