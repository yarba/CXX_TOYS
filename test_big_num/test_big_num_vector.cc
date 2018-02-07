#include <iostream>
#include <vector>

// NOTE-1: to compile, use g++ (NOT gcc or somethig, because others would not know of STD):
//         g++ test_big_num_vector.cc -o test_vector
//
// Note-2: 1 byte = 8 bits
//         char = 1 byte
//         short int = 2 bytes
//         int, long int, float (what else ?) = 4 bytes (32 bits)
//         long long int & double = 8 bytes (64 bits)
//
// Note-3: the number of bits one would need to represent a number NN: Log_2(NN)
//
// Note-4: alternative view of (binary representation) is to keep dividing NN by 2 until there's nothing more left
// Example: NN=15  --> 15/2 = 7 r 1
//                      7/2 = 3 r 1
//                      3/2 = 1 r 1
//                      1/2 = 0 r 1
//          15 --> 1111 ( ((8*1)+(4*1)+(2*1)+(1*1)) or ((2^3*1)+(2^2*1)+(2^1*1)+(2^0*1)) )
//
// Another example: NN=13 --> 13/2 = 6 r 1
//                             6/2 = 3 r 0
//                             3/2 = 1 r 1
//                             1/2 = 0 r 1
//                  13 --> 1101 ( ((2^3*1)+(2^2*1)+(2^1*0)+(2^0*1)) ) 
//

int main()
{

    double avg = 0.;
    // std::vector<int> Vc; // wont work with numbers >2B (2e+09)

    // either double or long long int will work since they're 64-bits
    //
    // std::vector<double> Vc;
    std::vector<unsigned long long int> Vc;
    Vc.push_back(200000000000); // 200B
    Vc.push_back(2000000000);

    //std::vector<double>::iterator it=Vc.begin();    
    std::vector<unsigned long long int>::iterator it=Vc.begin();

    for ( it; it!=Vc.end(); ++it )
    {
	avg += *it;
    }

    avg /= Vc.size();

    std::cout << " average = " << avg << std::endl;

    return 0;
    
}