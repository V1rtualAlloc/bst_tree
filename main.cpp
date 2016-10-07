#include <iostream>

#include "bst.cpp"

using namespace std;

int main()
{
    BST<int> b;

    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(3);
    b.insert(7);
    b.insert(15);
    b.insert(22);

    cout << b.find(10) << " " << b.find(5) << " " << b.find(20) << " " << b.find(3)
         << " " << b.find(7) << " " << b.find(15) << " " << b.find(22) << endl;

    b.remove(20);

    cout << b.find(10) << " " << b.find(5) << " " << b.find(20) << " " << b.find(3)
         << " " << b.find(7) << " " << b.find(15) << " " << b.find(22) << endl;

    return 0;
}

