const int N = 10004; const int t_sz= 26;
struct Palindromic_Tree{
  int tree[N][t_sz], idx,len[N], link[N], t,n;
  int endHere[N],occ[N],total=0; string s="#";
  int stop[N];//for printing
  Palindromic_Tree(){
    memset(occ, 0, sizeof(occ));
    len[1] = -1, link[1] = 1; len[2] = 0, link[2] = 1;
    endHere[1]=endHere[2]=0; idx = t = 2; }
  void add(int p) {
    while(s[p-len[t]-1] != s[p]) t=link[t];
    int x=link[t], c=s[p]-'a';
    while(s[p-len[x]-1] != s[p]) x=link[x];        
    if(!tree[t][c]) {
      tree[t][c] = ++idx; len[idx] = len[t] + 2;
      link[idx] = len[idx] == 1 ? 2 : tree[x][c];
      endHere[idx]=1+endHere[link[idx]];  }
    t = tree[t][c]; occ[t]++; stop[t]=p; }
  void init(string &ss){
    s+=ss; n=(int)s.size();
    for(int i=1; i<n; i++){ add(i); total+=endHere[t];
    /*palindrom end in pos i=endHere[t]*/  }
    for(int i=idx; i>2; i--){
      occ[link[i]]+=occ[i];
      /*print palindrom 
      int r=stop[i],l=stop[i]-len[i]+1;
      cout<<s.substr(l,len[i])<<endl;
      cout<<"len="<<len[i]<<",cnt="<<occ[i]<<"\n";*/  }  }
  void clear(){
    for(int i=0; i<=idx; i++){
      occ[i]=endHere[i]=len[i]=link[i]=0;
      for(int j=0; j<t_sz; j++) tree[i][j]=0;  }
    len[1] = -1, link[1] = 1;  len[2] = 0, link[2] = 1;
    endHere[1]=endHere[2]=0; idx = t = 2; total=0; s="#";}
  int cntDistinct(){ return idx-2; }
  int cntTotal(){ return total; }  };
