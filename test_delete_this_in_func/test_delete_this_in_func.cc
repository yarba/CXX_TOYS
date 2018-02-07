
#include <iostream>

class Test
{
public:
    Test() : ii(5) {}
    ~Test() {}
    void show_data() { std::cout << " ii = " << ii << std::endl; return; }
    void have_fun() { delete this; return; }
private:
    int ii;
};

int main()
{

    Test* p = new Test();
    p->show_data();
    p->have_fun();
    p = NULL;

    std::cout << " everything is fine so far " << std::endl;

    Test p1;
    p1.show_data();
    p1.have_fun();

    std::cout << "... things are still fine " << std::endl;

    // NOTE: BUT it'll be crash on exit !!!

    return 0;
    
}
