#include "LinkedBST.h"

bool LinkedBST::isEmpty()
{
    if (root == nullptr)
    {
        return true;
    }
    else
        return false;
}

void LinkedBST::addBST(int key, int value)
{
    if (root == nullptr)
    {
        Node *newNode = new Node(nullptr, nullptr, nullptr);
        newNode->data.key = key;
        newNode->data.value = value;
        root = newNode;
        return;
    }
    else
    {

        Node *n = root;
        while (true)
        {

            if (value > n->data.value)
            {

                if (n->rightChild == nullptr)
                {

                    Node *newNode = new Node(n, nullptr, nullptr);
                    newNode->data.value = value;
                    newNode->data.key = key;
                    n->rightChild = newNode;

                    break;
                }
                n = n->rightChild;
            }
            else if (value < n->data.value)
            {
                if (n->leftChild == nullptr)
                {
                    Node *newNode = new Node(n, nullptr, nullptr);
                    n->leftChild = newNode;
                    newNode->data.value = value;
                    newNode->data.key = key;

                    break;
                }
                n = n->leftChild;
            }
        }
    }
}

bool LinkedBST::searchBST(int target)
{
    searchBST(target, root);
}

bool LinkedBST::searchBST(int target, Node *temp)
{
    if (temp->data.value == target)
    {
        cout << "Value is found" << endl;
        return true;
    }
    else
    {
        if (temp->leftChild != nullptr)
        {

            searchBST(target, temp->leftChild);
        }
        if (temp->rightChild != nullptr)
        {
            searchBST(target, temp->rightChild);
        }
    }

    return false;
}

void LinkedBST::traverse()
{
    traverse(root);
}

void LinkedBST::traverse(Node *temp)
{
    if (isEmpty())
    {

        return;
    }

    cout << temp->data.value << endl;
    if (temp->leftChild != nullptr)
    {

        traverse(temp->leftChild);
    }
    if (temp->rightChild != nullptr)
    {

        traverse(temp->rightChild);
    }
    return;
}
Node *LinkedBST::inOrderPredecessor(Node *temp)
{
    temp = temp->leftChild;
    while (temp->rightChild != nullptr)
    {
        temp = temp->rightChild;
    }
    return temp;
}

void LinkedBST::deleteBST(int value, int target)
{
    deleteBST(root, target);
}

Node *LinkedBST::deleteBST(Node *temp, int value)
{
    Node *iPre;

    if (temp->leftChild == nullptr && temp->rightChild == nullptr)
    {
        delete (temp);
        return nullptr;
    }

    if (value < temp->data.value)
    {
        temp->leftChild = deleteBST(temp->leftChild, value);
    }
    else if (value < temp->data.value)
    {
        temp->rightChild = deleteBST(temp->rightChild, value);
    }
    else
    {
        iPre = inOrderPredecessor(temp);
        temp->data.value = iPre->data.value;

        temp->leftChild = deleteBST(temp->leftChild, iPre->data.value);
    }
    return temp;
}