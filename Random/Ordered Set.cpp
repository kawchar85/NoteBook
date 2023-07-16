#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/*find_by_order(),order_of_key(),greater<int>,
less_equal<int>,less_equal<int> -->multiset, 
order_of_key will return 1st pos, multiset er jonno
upper_bound --> lower_bound hisebe kaj kore. 
To avoid: use pair {a[i], uniqueID} 
tree<pii, null_type,less<pii>,...*/
