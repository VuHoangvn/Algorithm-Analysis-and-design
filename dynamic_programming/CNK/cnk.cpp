#include <iostream>

using namespace std;

int calculate_CNK(int n, int k, int m)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    return ((calculate_CNK(n - 1, k, m) % m) + calculate_CNK(n - 1, k - 1, m) % m) % m;
}

int nCrModpDP(int n, int r, int p) 
{ 
    // The array C is going to store last row of 
    // pascal triangle at the end. And last entry 
    // of last row is nCr 
    int C[r+1]; 
    for(int i = 0; i < r+1; i++){
        C[i] = 0;
    }
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (int i = 1; i <= n; i++) 
    { 
        // Fill entries of current row using previous 
        // row values 
        for (int j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 

int nCrModpLucas(int n, int r, int p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
   // Compute last digits of n and r in base p 
   int ni = n%p, ri = r%p; 
  
   // Compute result for last digits computed above, and 
   // for remaining digits.  Multiply the two results and 
   // compute the result of multiplication in modulo p. 
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r 
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits 
}


int main()
{
    int T, n, k, m;
    cin >> T;
    int i = 0;
    while (i++ < T)
    {
        scanf("%d %d %d", &n, &k, &m);
        cout << nCrModpLucas(n, k, m) << endl;
    }
    return 0;
}