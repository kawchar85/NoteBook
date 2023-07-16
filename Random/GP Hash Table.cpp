//gp_hash_table<key, int, chash> table;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct chash {
  const uint64_t C = 2713661325311;
  const uint32_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
  size_t operator()(uint64_t x) const {
      return __builtin_bswap64((x ^ RANDOM) * C); }
  size_t operator()(pair<uint64_t, uint64_t> x) const { 
    return x.first* 31 + x.second;
    //return __builtin_bswap64(((something) ^ RANDOM) * C);
  } };
