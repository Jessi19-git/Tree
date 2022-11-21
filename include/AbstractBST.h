#ifndef AbstractBST_h
#define AbstractBST_h

class AbstractBST
{
public:
    virtual void addBST(int value, int target) = 0;
    virtual bool isEmpty() = 0;
    virtual void deleteBST(int value, int target) = 0;
    virtual bool searchBST(int target) = 0;
    virtual void traverse() = 0;
};
#endif
