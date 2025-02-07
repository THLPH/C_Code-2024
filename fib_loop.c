#include <stdio.h>

void gen_fib(int fib[], int n) {
    if (n < 1) {return;}
    
    fib[0] = 0; // First Fibonacci number
    fib[1] = 1; // Second Fibonacci number
    // Print the first two Fibonacci numbers
    printf("%d %d ", fib[0], fib[1]);

    
    // Generate the rest of the Fibonacci sequence
    for (int idx = 2; idx < n; idx++) 
    {
        fib[idx] = fib[idx - 1] + fib[idx - 2];
        printf("%d ", fib[idx]); // Print the current Fibonacci number
    }
    
    printf("\n"); // Print a newline for better formatting
}

int main(void) 
{
    int n = 40; // Generate the first 40 Fibonacci numbers
    int fib[40];
    
    gen_fib(fib, n); // Generate and print the Fibonacci sequence
    
    return 0;
}
