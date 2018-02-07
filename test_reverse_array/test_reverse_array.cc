#include <iostream>
#include <vector>

using namespace std;

int main()
{

   vector<int> vc;

    for ( int i=0; i<10; ++i )
    {
	vc.push_back(i);
    }

    // NOTE: this approach will work when the length
    // of the array is even or odd (tested for 10 or 9).
    // If the length is an odd number, the half-length
    // will actually be (size-1)/2, and in this case
    // the "middle element will stay untouched.
    

    int size = vc.size();
    for ( int i=0; i<size/2; ++i )
    {
	int tmp = vc[i];
	vc[i] = vc[size-i-1];
	vc[size-i-1] = tmp;
    }

    for ( int i=0; i<size; ++i )
    {
	cout << i <<"th element = " << vc[i] << endl;
    }

    return 0;
    
}