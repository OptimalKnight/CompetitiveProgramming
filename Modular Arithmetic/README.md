# Modular Arithmetic

Modular arithmetic is a system of arithmetic where calculations are performed modulo a fixed integer, called the modulus. In modular arithmetic, the result of an operation is the remainder of that operation when divided by the modulus. For example, in modulo 5 arithmetic, 6 + 4 = 5 because the remainder of 6 + 4 when divided by 5 is 1. Modular arithmetic is often used in computer science and cryptography, as it allows computations to be performed efficiently using limited hardware resources.

## Usage

To use the class for calculating factorials, inverse factorials, and performing related operations, you should instantiate an object of the class by passing the parameters N and M to the constructor. The parameter N denotes the maximum number for which you may need to calculate a result, whereas the parameter M denotes the number with respect to which you need to perform the modulo operation.

After initializing the object, the constructor will initialize the factorials and inverse factorials modulo M up to the required limit, starting from 1. You can then find the exponent of a number, factorial of a number, inverse modulo of a number, or the number of combinations by calling the respective methods and properties. All these results will be returned modulo M.

## Time Complexity

- Constructor(N, M): O(n)
- mpow(A, B): O(log2(B))
- invmod(A): O(log2(A))
- nCr(N, R): O(1)

## Output

The output for the provided sample program would be,

    Factorial of 97 (modulo 1000000007): 275417893
    Inverse factorial of 97 (modulo 1000000007): 267903845
    97 raised to power 97 (modulo 1000000007): 489000099
    Number of ways of chossing 47 objects out of 97 objects (modulo 1000000007): 368362674