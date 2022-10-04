theorem:area=In+(on_boundary/2)-1;in=strictly inside polygon
/*Grundy/Nimbers: smallest number jei state a jawa jabe nah
Problem: Divide pile in two unequal piles */
void Grandy(int n){
  int G[sz]; set<int>s;
  for(i=1; ; i++){
      j=n-i; if(j<=i) break;
      //i,j te jabo. insert i,j othoba i^j
      s.insert(G[i]^G[j]); }
  i=0;
  while(s.find(i)!=s.end()) i++;
  G[n]=i; }
