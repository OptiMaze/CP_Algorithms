
void multiply(int F[2][2], int M[2][2]);

void power(int F[2][2], int n);

int fib(int n,int f0,int f1)
{
int F[2][2] = {{1,1},{1,0}};
if (n == 1)
	return f0;
if(n==2)
    return f1;
power(F, n-2);
return ((F[0][0]*f1)%mod+(F[0][1]*f0)%mod)%mod;
}

void power(int F[2][2], int n)
{
if( n == 0 || n == 1)
	return;
int M[2][2] = {{1,1},{1,0}};

power(F, n/2);
multiply(F, F);

if (n%2 != 0)
	multiply(F, M);
}

void multiply(int F[2][2], int M[2][2])
{
int x = ((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod;
int y = ((F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod)%mod;
int z = ((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod;
int w = ((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod;

F[0][0] = x;
F[0][1] = y;
F[1][0] = z;
F[1][1] = w;
}
