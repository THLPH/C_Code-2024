#include <stdio.h>

void gen_fib(int fib[], int n, int idx) 
{
    if (idx >= n) 
    {
        return;
    }
    fib[idx] = fib[idx - 1] + fib[idx - 2];
    printf("%d ", fib[idx]);  // Print the current Fibonacci number
    gen_fib(fib, n, idx + 1);
}

int main(void) 
{
    int n = 40; // Generate the first 40 Fibonacci numbers
    int fib[40];
    
    fib[0] = 0; // First Fibonacci number
    fib[1] = 1; // Second Fibonacci number
    // Print the first two Fibonacci numbers
    printf("%d %d ", fib[0], fib[1]);

    // Generate the Fibonacci sequence starting from index 2
    gen_fib(fib, n, 2);

    // Print a newline for better formatting
    printf("\n");

    return 0;
}
