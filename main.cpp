#include <iostream>

#include "bst.cpp"

using namespace std;

int main()
{
    BST<int> b;
    b.insert(5);
    for (int i = 0; i < 10; i++)
        b.insert(i);
    for (int i = 0; i < 15; i++)
        cout << b.find(i) << " ";
   cout << endl;

   b.inorderPrint();

   b.remove(9);
   b.remove(8);
   b.inorderPrint();


    return 0;
}

