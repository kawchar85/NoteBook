Stirling numbers 1st kind:
S(n,k)=k⋅S(n−1,k)+S(n−1,k−1)
Base case:
S(0,0)=1,S(n,0)=S(0,n)=
S(n,2)=2^(n−1)−1

Stirling numbers 2nd kind: (put r objects in n shelves)
Base cases:
S(r, 0) = 0
S(r, 1) = (r – 1)!
S(r, r) = 1.
S(r, r -1) = rC2
Transition:
S(r,n) = S(r–1,n–1)+(r–1) * S(r–1,n)