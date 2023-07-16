sum of the distances from the node to all other nodes:
in[u]: from u to each node in subtree rooted at u
out[u]: excluding the subtree rooted at u
in[u] = sum of in[child] + size[child]
out[u] = contribution of par (out[par]) +
  contribution of edge u <--> par (n - size[par] + 1) +
 contribution of each siblings (in[sib] + 2 * size[sib])
