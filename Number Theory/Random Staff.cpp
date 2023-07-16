number theory stuff and tricks:
every prime number modulo 4 = 1 can be written as sum of two
squares. beizuts identity, if gcd(x1,x2,x3,....xn) = g, then
(a1x1+12x2+13x3+....anxn) = k*g (for any k>=1) where a1,a2,
a3 are integers(might be negative or zero)
*** going from left to right taking prefix gcd, after we add
a new number(different from any number seen sofar) gcd will
becrease by at least a prime factor... so we can have at 
most 20/30 element before we hit gcd = 1;

A number is Fibonacci iff one or both of (5*n*n+4) or 
(5*n*n-4) is a perfect square. (n - 1)! = (n-1)= 
−1(mod n) exactly when n is a prime number.

Pythagorean Triple(a,b,c):
	a = m*m - n*n
	b = 2*m*n
	c = m*m + n*n
	for m>n>0

gcd(a1+d, a2+d, a3+d,...)=gcd(a1+d, a2-a1, a3-a1, ...)
gcd(pow(n,a)-1, pow(n,b)-1)=pow(n, gcd(a,b))-1
gcd(a,lcm(b,c))=lcm(gcd(a,b),gcd(a,c))
phi(lcm(a,b))*phi(gcd(a,b))=phi(a)*phi(b)

x1+x2+...+xk=n, xi>=0 : NOS = nCr(n+k-1, k-1)
x1+x2+...+xk=n, xi>=ai : NOS = nCr(n+k-1-(sum of ai), k-1)
