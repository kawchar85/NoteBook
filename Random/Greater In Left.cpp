void print(ll i){
  if(st.empty()) cout<<"No element in left";
  else cout<<st.top();
  cout<<" > "<<arr[i]<<endl;  }
twoMax(ll n){
  st.push(arr[0]);
  for(ll i=1; i<n; i++){
    while(!st.empty() && arr[i]>=st.top()){
      //max_1st=arr[i],max_2nd=top()
      st.pop();  }
    print(i);
    //max_1st=top(),max_2nd=arr[i]
    st.push(arr[i]);  } }