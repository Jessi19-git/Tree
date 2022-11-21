#include <iostream>
#include "AbstractBST.h"
#include "LinkedBST.h"

int main()
{
    AbstractBST *ptr;
    LinkedBST L;
    ptr = &L;

    cout << endl;
    if (ptr->isEmpty())
    {
        cout << "The binary tree is empty" << endl;
    }

    ptr->addBST(1, 80);
    ptr->addBST(2, 13);
    ptr->addBST(3, 30);
    ptr->addBST(4, 70);
    ptr->addBST(5, 67);
    ptr->addBST(6, 11);
    ptr->traverse();
    cout << endl;

    ptr->searchBST(11);

    ptr->deleteBST(6, 11);
    ptr->traverse();
}