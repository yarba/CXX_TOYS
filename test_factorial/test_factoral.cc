#include <iostream>

using namespace std;

int main()
{

    // Note-1: This code wont work properly if num<0.
    //
    // Note-2: This code operates on int's and is not guaranteed 
    //         to work properly in case of really big numbers.
    //         If operating on big numbers is the case, then
    //         one may try with long long int and/or double's.
    //
    // Note-3: The nature of implementation is affected by the
    //         desire to display the factorial in the REVERSE
    //         order - this calls for more than 1 loop (either
    //         nested or sequential). 
    //
    // Note-4: The code covers 3 possible implementations, but 
    //         there might be other attempts and/or creativities. 
    //         Isn't the nature of the algorithms optimization ?

    int num=5;

    if (num < 0 ) 
    {
	cout << " illegal input: " << num << endl;
	return 0;
    }

    // Case-1: nested loops
    // Straightforward implementation.
    // NOt necessarily most CPU efficient 
    // (CPU is roughly num*num)

    cout << " --> CASE-1: implemented as nested loops " << endl; 

    for ( int i=num; i>0; --i )
    {
      int result = i;
      int count = i - 1;
      for ( int j=count; j>0; --j )
      {
         result *= j;
      }
      cout << " result of " << i << "! = " << result << endl;
    }
    // 0! is a special case
    //
    cout << " result of 0! = 1" << endl;

    // Case-2
    // This is perhaps the simplest way...
    // It's implemented with 2 sequential loops, 
    // which means that the CPU is ~2*num, i.e. linear.
    // No additional memory manipulation.
    //

    cout << " CASE-2: implemented with 2 seq. loops;  no need to deal with memory management ot any..." << endl;  
    cout << " CPU is ~ 2*num... which is linear, yes, no ?" << endl;

    int result1 = 1;
    for ( int i=2; i<=num; ++i )
    {
      result1 *= i;
    }

    cout << " result of " << num << "! = " << result1 << endl;
    for ( int i=num-1; i>0; --i )
    {
	result1 /= (i+1); 
	cout << " result of " << i << "! = " << result1 << endl; 
    }
    cout << " result of 0! = 1" << endl;

    // Case-3; 
    // Similar to case-2, is implemented as 2 seq. loops, with 
    // with the CPU ~ 2*num (linear), but also involves some memory 
    // manipulations for storage,... just in case the numbers need 
    // to be preserved/storeed/reused.
    //
    // Note-4: If storage/reuse of the numbers is needed,
    //         one may also opt for std::vector instead of 
    //         flat out memry allocation for the array variable.
    // Note-5: In general, the code is not "super-generic" as
    //         it maakes certain assumptions, such as 0!=1... 

    cout << " CASE-3: similar to Case-2 and with CPU ~2*N" << endl; 
    cout << " but involves some memory management in case the calculated numbers need to be preserved/reused" << endl;
 

    int* array = new int[num+1];

    array[0] = 1;

    for ( int i=1; i<=num; ++i )
    {
      array[i] = array[i-1]*i;
    }

    for ( int i=num; i>=0; --i )
    {
      cout << " result of " << i << "! = " << array[i] << endl;
    }

    delete [] array;

    cout << " All 3 (somewhat different) cases seem to have worked as expected. " << endl;
    cout << " La vita e' bella !!!" << endl;

    return 0;

}
