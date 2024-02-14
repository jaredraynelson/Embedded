/*
Give the summation of all even numbers in a Fibonacci sequence up to, but not including, the number passed to your function.
Or, in other words, sum all the even Fibonacci numbers that are lower than the given number n (n is not the nth element of Fibonacci
sequence) without including n.
The Fibonacci sequence is a series of numbers where the next value is the addition of the previous two values. The series starts with 0 and 1:

0 1 1 2 3 5 8 13 21...

For example:

even_fib(0)==0
even_fib(33)==10
even_fib(25997544)==19544084
*/

typedef unsigned long long ull;

ull even_fib(ull limit) {

  ull i1 = 0;
  ull i2 = 1;
  ull sum = 0;
  ull evenSum = 0;
  
  while (sum < limit) {
    sum = i1 + i2;
    if ( i1<i2 ) { i1 = sum; }
    else { i2 = sum; }
    if ( sum < limit ){ if ( sum % 2 == 0 ) { evenSum+=sum; } }
  }
  return evenSum;
}
