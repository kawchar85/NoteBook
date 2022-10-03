struct cmp{
  bool operator() (segment a, segment b) const{
    return (a.len>b.len)||((a.len==b.len) && a.l<b.l); } };
/* bigger len will be first and if lens are equal 
then less l will be first *///////////////////
