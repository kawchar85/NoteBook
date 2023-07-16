bool B_S(int key){
  int id=0; //-1
  for(int jump=n; jump>0; jump/=2)
    while(id+jump<n && arr[id+jump]<=key) id+=jump;
  return arr[id]==key; }
T_S(ll l, ll r) {
  while(r - l > 3) {
    m1 = l + (r - l) / 3; m2 = r - (r - l) / 3;
    f1 = f(m1); f2 = f(m2);
    if(f1 < f2) l = m1;
    else  r = m2;
  }
  for(i=l; i<=r; i++) mx = max(mx, f(i)); }
