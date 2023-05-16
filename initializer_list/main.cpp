#include <iostream>
#include "initializer_list.hpp"

using namespace std;

int main(){
    cout << "Hello World!" << endl;

    InitializerList<int> list{ 1, 2, 3, 4, 5 };
    for (auto& i : list)
        cout << i << " ";
    cout << endl;
    return 0;
}
