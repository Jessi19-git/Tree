#ifndef AbstractBST_h
#define AbstractBST_h




class AbstractBST{
public:
virtual bool isEmpty() = 0;
virtual void addBST(int key, int value) = 0;
virtual void removeBST(int value) = 0;
virtual void searchBST(int targetkey) = 0;


};























#endif