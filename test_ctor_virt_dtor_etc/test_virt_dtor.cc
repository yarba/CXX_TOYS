// 
// Note-1: dtor is responsible for releasing memory, and in case of inhertance
//         should better be virtual to ensure proper and complete memory release.
//         The issue here is the following:
//         For a derived class a ctor is always called "in chain", in the correct 
//         order (there's no such thing as virtual ctor).
//         But a dtor is not necessarily called in chain.
//         One particular exmaple is when am instance of a derived class is deleted
//         through a pointer to a base class. I.e. one has a pointer of a base class
//         but the actual object is a derived class. In such case the delete operates
//         on the pointer of the "base" type. If the dtor is non-virtual, it'll all
//         end right there, and will never go deeper to the derived class.
//         This is also called UNDEFINED BEHAVIOR.
//
// Note-2: DOUBLE CHECK when a derived ctor must call base ctor explicitly and when
//         the call happens automatically (input arguments ? polymorphism ?... )
//         YES, the default ctor is always called automatically.
//         However, if there's a "non-default" ctor that takes input argument(s),
//         it's necessary to call it explicitly, the situation is a bit more complicated.
//         First of all, if there's more that 1 (one) ctor in the base class, the compiler
//         starts complaining about ambiguity.  <-------------- OK, resolved, see Note-3 !!!   
//         So yes, if there're 2 ctor's in the base class, and 2 "matching" ones in the
//         derived class, then default base ctor will be called in both derived ctor's.
//         If one wants Derived1(int) to call Base1(int), it has to be coded explicitly.
//
// Note-3: It's good to remember that, by default, the compiler provides the following:
//         1. Default (Parameterless) Ctor
//         2. Copy Ctor
//         3. Assignment operator
//         In case a user provides a non-default ("parametrized, or with input args) ctor
//         or copy ctor, then the compiler no longer provides the default ctor, and the user
//         is obliged to implement one.
//         BUT !!!! In this case, why the hell do I get complains about ambiguities with
//         both Base1() & Base1( const int ) in place ?????
//         OK,OK, OK, I've figured it out !
//         It wa complaining because I did Base1( const int i=0 ), i.e. I gave it a DEFAULT arg.
//         If I do NOT give any defaults to the input arg, everything is fine.
//
// Note-4: Needs to build with g++ (not gcc)
//
// Note-5: NEED TO ADD AN (separate) EXAMPLE WITH EXPLICIT CTOR !!!


#include <iostream>
// #include <string>

class Base1
{
public :
     Base1() { std::cout << " --> Base1 default ctor called " << std::endl; }
     Base1( const int i  ) { std::cout << " --> Base1 non-default ctor is called with arg = " << i << std::endl; }
    ~Base1() { std::cout << " --> ~Base1 dtor called " << std::endl; } 
};

class Derived1 : public Base1
{
public:
    Derived1() { std::cout << " --> Derived1 ctor called " << std::endl; }
    Derived1( const int i ) { std::cout << " --> Derived1 non-default ctor is called with arg = " << i << std::endl; }
    ~Derived1() { std::cout << " --> ~Derived1 dtor called " << std::endl; }

};

class Base2
{
public:
    Base2() { std::cout << " --> Base2 ctor called " << std::endl; }
    virtual ~Base2() { std::cout << " --> ~Base2 dtor called " << std::endl; }
};

class Derived2 : public Base2
{
public:
    Derived2() { std::cout << " --> Derived2 ctor called " << std::endl; }
    ~Derived2() { std::cout << " --> ~Derived2 dtor called " << std::endl; }
};

int main()
{

    Base1* p1 = new Derived1(5);
    delete p1;

    Base2* p2 = new Derived2();
    delete p2;

    return 0;
    
}