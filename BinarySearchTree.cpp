#include "BinarySearchTree.h"

#include <algorithm>
#include <iostream>

BinarySearchTree::BinarySearchTree(int value)
    : value(value), leftSubTree(nullptr), rightSubTree(nullptr) {}

BinarySearchTree::~BinarySearchTree()
{
    if (leftSubTree != nullptr)
        delete leftSubTree;
    if (rightSubTree != nullptr)
        delete rightSubTree;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other): value(other.value)
{
    if (other.leftSubTree != nullptr)
        leftSubTree = new BinarySearchTree(*other.leftSubTree);
    if (other.rightSubTree != nullptr)
        rightSubTree = new BinarySearchTree(*other.rightSubTree);
}

void BinarySearchTree::add(int newValue)
{
    if (newValue < value)
    {
        if (leftSubTree != nullptr)
            leftSubTree->add(newValue);
        else
            leftSubTree = new BinarySearchTree(newValue);
    }
    else if (newValue > value)
    {
        if (rightSubTree != nullptr)
            rightSubTree->add(newValue);
        else
            rightSubTree = new BinarySearchTree(newValue);
    }
}

bool BinarySearchTree::hasValue(int valueToFind) const
{
    if (valueToFind == value)
        return true;
    if (valueToFind < value && leftSubTree != nullptr)
        return leftSubTree->hasValue(valueToFind);
    if (valueToFind > value && rightSubTree != nullptr)
        return rightSubTree->hasValue(valueToFind);
    return false;
}

void BinarySearchTree::print(int depth=0) const
{
    if(this == nullptr)
        return;
    rightSubTree->print(depth+1);
    for (int j = 0; j < depth; j++) // Print the node value
        std::cout << '\t';
    std::cout << value << std::endl;
    
    leftSubTree->print(depth+1); // Recursion: left sub-tree

}


//Task 1
bool BinarySearchTree::isSame(const BinarySearchTree* other)
{
    // base case 1.. ? 
    if (other == nullptr) {
        return true;
    }

    if (!this->hasValue(other->value)) {
        return false;
    } 

    // check left recursively,
    return this->leftSubTree->isSame(other->leftSubTree);


    // check right recursively
    return this->leftSubTree->isSame(other->rightSubTree);

    



}

//Entry of task2
void BinarySearchTree::buildNewBST(BinarySearchTree* newBST, int newValue)
{
    if (!this->hasValue(newValue))
    {
        std::cout << "Invalid value!" << std::endl;
    }
    newBST->value = newValue;      
     //Hint: as the add function will ignore the existing nodes, 
     //you do not neet to consider the ruplicate "newValue" in the newBST  
    this->traverseAdd(newBST);
}

//Task 2
void BinarySearchTree::traverseAdd(BinarySearchTree* newBST)
{
    // determine node from old tree to add to new tree
    if (newBST == nullptr || this == nullptr) {
        return;
    }

    this->leftSubTree->traverseAdd(newBST);
    newBST->add(this->value);
    this->rightSubTree->traverseAdd(newBST);





    // determine where to add the node to the new tree.

   
    

}
