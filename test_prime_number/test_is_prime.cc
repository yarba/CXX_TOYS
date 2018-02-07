#include <iostream>

using namespace std;

bool is_prime( int num )
{

    // NOTE: a prime number is natural number that is greater than 1 (one)
    // that has no positive divisors other than 1 or itself 

    // QUESTION: can it be done faster than this ?????

    if ( num == 1 ) return false; // 1 is NOT prime by definition

    int i = 2;
    for ( ; i<=num; ++i )
    {
	if ( num%i == 0 ) break; // found a divisor
    }
    if ( i < num ) return false; // divisor is smaller than num, 
                                 // thus it's not a prime number

    return true;
    
}

int main()
{

    bool status = false;

    status = is_prime(4);
    cout << " Is 4 prime ? " << status << endl;

    status = is_prime(7);
    cout << " Is 7 prime ? " << status << endl;

    return 0;
}
