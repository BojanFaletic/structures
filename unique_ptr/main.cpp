#include <iostream>
#include "unique_ptr.hpp"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    unique_ptr<int> ptr(new int(5));
    cout << *ptr << endl;

    unique_ptr<int> ptr2 = std::move(ptr);
    cout << *ptr2 << endl;

    return 0;
}
