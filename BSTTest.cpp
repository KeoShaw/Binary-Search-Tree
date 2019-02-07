#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "BST.h"

using namespace std;

bool lessThan(const int& a, const int& b){
    if(a<b) return true;
    return false;
}

void output(const int& a){
    cout << a << endl;
}

void DisplayTreeContents(const BST<int>& tree){
    cout << "\nIn order:\n";
    tree.Traversal(output);
}

void TestFirstInsertion(){
    cout << "\n\nTest one:\n\n";
    BST<int> tree;

    for(int i = 0;i < 50;i++){
        tree.Insert(i, lessThan);
    }

    tree.Remove(0, lessThan);
    DisplayTreeContents(tree);
    if(tree.Search(0, lessThan)){
        cout << "Found zero (incorrect)" << endl;
    }
    if(tree.Search(1,lessThan)){
        cout << "Found one (correct)" << endl;
    }
    if(tree.Search(49,lessThan)){
        cout << "Found 49 (correct)" << endl;
    }
    if(tree.Search(50,lessThan)){
        cout << "Found 50 (incorrect)" << endl; //1 to 49 should be displayed, and it should find 1 and 49
    }
}

void LargeThenSmall(){
    cout << "\n\nTest two:\n\n";

    BST<int> tree;

    tree.Insert(10,lessThan);
    tree.Insert(0,lessThan);

    DisplayTreeContents(tree); //should display 0 then 10
    if(tree.Search(0,lessThan)){
        cout << "Found 0 (correct)" << endl;
    }
    if(tree.Search(10,lessThan)){
        cout << "Found 10 (correct)" << endl;
    }

    tree.Remove(10,lessThan);

    if(tree.Search(0,lessThan)){
        cout << "Found 0 (correct)" << endl;
    }
    if(tree.Search(10,lessThan)){
        cout << "Found 10 (incorrect)" << endl; //Should display 3 corrects
    }

    DisplayTreeContents(tree); //Should display 0
}
void RemoveRootWithTwoChildren(){ //Finds 9 and 11, then displays them
    cout << "\n\nTest 3:\n\n";
    BST<int> tree;

    tree.Insert(10,lessThan);
    tree.Insert(9,lessThan);
    tree.Insert(11,lessThan);

    tree.Remove(10,lessThan);

    if(tree.Search(10,lessThan)){
        cout << "Found 10 (incorrect)" << endl;
    }
    if(tree.Search(9,lessThan)){
        cout << "Found 9 (correct)" << endl;
    }
    if(tree.Search(11,lessThan)){
        cout << "Found 11 (correct)" << endl;
    }

    DisplayTreeContents(tree);
}

void RemoveLeftChildNoChild(){ //Finds ten and prints 10
    cout << "\n\nTest 4:\n\n";
    BST<int> tree;

    tree.Insert(10,lessThan);
    tree.Insert(9,lessThan);

    tree.Remove(9,lessThan);

    if(tree.Search(10,lessThan)){
        cout << "Found 10 (correct)" << endl;
    }
    if(tree.Search(9,lessThan)){
        cout << "Found 9 (incorrect)" << endl;
    }

    DisplayTreeContents(tree);
}

void RemoveLeftChildRightChild(){ //Should find and display 9, 10
    cout << "\n\nTest 5:\n\n";
    BST<int> tree;

    tree.Insert(10,lessThan);
    tree.Insert(8,lessThan);
    tree.Insert(9,lessThan);

    tree.Remove(8,lessThan);

    if(tree.Search(10,lessThan)){
        cout << "Found 10 (correct)" << endl;
    }
    if(tree.Search(9,lessThan)){
        cout << "Found 9 (correct)" << endl;
    }
    if(tree.Search(8,lessThan)){
        cout << "Found 8 (incorrect)" << endl;
    }

    DisplayTreeContents(tree);
}

void RemoveLeftChildLeftChild(){ //Should find and display 10 and 7
    cout << "\n\nTest 6:\n\n";
    BST<int> tree;

    tree.Insert(10,lessThan);
    tree.Insert(8,lessThan);
    tree.Insert(7,lessThan);

    tree.Remove(8,lessThan);

    if(tree.Search(10,lessThan)){
        cout << "Found 10 (correct)" << endl;
    }
    if(tree.Search(7,lessThan)){
        cout << "Found 7 (correct)" << endl;
    }
    if(tree.Search(8,lessThan)){
        cout << "Found 8 (incorrect)" << endl;
    }

    DisplayTreeContents(tree);
}

void RemoveLeftChildTwoChild(){ //Should find and display 7, 9, 10
    cout << "\n\nTest 7:\n\n";
    BST<int> tree;

    tree.Insert(10,lessThan);
    tree.Insert(8,lessThan);
    tree.Insert(7,lessThan);
    tree.Insert(9,lessThan);

    tree.Remove(8,lessThan);

    if(tree.Search(10,lessThan)){
        cout << "Found 10 (correct)" << endl;
    }
    if(tree.Search(9,lessThan)){
        cout << "Found 9 (correct)" << endl;
    }
    if(tree.Search(8,lessThan)){
        cout << "Found 8 (incorrect)" << endl;
    }
    if(tree.Search(7,lessThan)){
        cout << "Found 7 (correct)" << endl;
    }

    DisplayTreeContents(tree);
}

void RemoveRightChildNoChild(){ //Should find and display 10
    cout << "\n\nTest 8:\n\n";
    BST<int> tree;

    tree.Insert(10,lessThan);
    tree.Insert(11,lessThan);

    tree.Remove(11,lessThan);

    if(tree.Search(10,lessThan)){
        cout << "Found 10 (correct)" << endl;
    }
    if(tree.Search(11,lessThan)){
        cout << "Found 11 (incorrect)" << endl;
    }

    DisplayTreeContents(tree);
}

void RemoveRightChildRightChild(){ //Should find and display 10, 12
    cout << "\n\nTest 9:\n\n";
    BST<int> tree;

    tree.Insert(10,lessThan);
    tree.Insert(11,lessThan);
    tree.Insert(12,lessThan);

    tree.Remove(11,lessThan);

    if(tree.Search(10,lessThan)){
        cout << "Found 10 (correct)" << endl;
    }
    if(tree.Search(11,lessThan)){
        cout << "Found 11 (incorrect)" << endl;
    }
    if(tree.Search(12,lessThan)){
        cout << "Found 12 (correct)" << endl;
    }

    DisplayTreeContents(tree);
}

void RemoveRightChildLeftChild(){ //Should find and display 10, 11
    cout << "\n\nTest 10:\n\n";
    BST<int> tree;

    tree.Insert(10,lessThan);
    tree.Insert(12,lessThan);
    tree.Insert(11,lessThan);

    tree.Remove(12,lessThan);

    if(tree.Search(10,lessThan)){
        cout << "Found 10 (correct)" << endl;
    }
    if(tree.Search(11,lessThan)){
        cout << "Found 11 (correct)" << endl;
    }
    if(tree.Search(12,lessThan)){
        cout << "Found 12 (incorrect)" << endl;
    }

    DisplayTreeContents(tree);
}

void RemoveRightChildTwoChild(){ //should find and display, 10, 11, 13
    cout << "\n\nTest 11:\n\n";
    BST<int> tree;

    tree.Insert(10,lessThan);
    tree.Insert(12,lessThan);
    tree.Insert(11,lessThan);
    tree.Insert(13,lessThan);

    tree.Remove(12,lessThan);

    if(tree.Search(10,lessThan)){
        cout << "Found 10 (correct)" << endl;
    }
    if(tree.Search(11,lessThan)){
        cout << "Found 11 (correct)" << endl;
    }
    if(tree.Search(12,lessThan)){
        cout << "Found 12 (incorrect)" << endl;
    }
    if(tree.Search(13,lessThan)){
        cout << "Found 13 (correct)" << endl;
    }

    DisplayTreeContents(tree);
}

void TestMemoryLeak(){ //Should output nothing except three in order: texts
    cout << "\n\nTest 12:\n\n";
    BST<int> tree;

    for(int i = 0;i < 1000000; i++){ //Tests root node memory efficacy
        tree.Insert(i,lessThan);
        tree.Remove(i,lessThan);
    }
    DisplayTreeContents(tree);

    tree.Insert(20,lessThan);

    for(int i = 0;i < 1000000;i++){ //Tests sub-node memory efficacy
        tree.Insert(i,lessThan);
        tree.Remove(i,lessThan);
    }
    DisplayTreeContents(tree);

    for(int i = 0;i < 10000;i++){ //Tests sub-node memory efficacy when deleting large branches
        tree.Insert(i,lessThan);
    }
    for(int i = 0;i < 10000;i++){ ////////////////////////////////////Setting this to ~100,000 (possibly lower) will cause a stack overflow error (0xC00000FD)/////////////////////////////////////////////
        tree.Remove(i,lessThan);
    }
    DisplayTreeContents(tree); //All of these should display nothing
}

void TestDestructor(){
    BST<int> tree;
    tree.Insert(12,lessThan);
    tree.Insert(14,lessThan);
    tree.Insert(10,lessThan);
    tree.Insert(15,lessThan);
    tree.Insert(13,lessThan);
    tree.Insert(11,lessThan);
    tree.Insert(9,lessThan);
}

void TestEqualsOperator(){ //Should display all the inserted values, and should find 12
    cout << "\n\nTest 13:\n\n";
    BST<int> tree, copyTree;
    tree.Insert(12,lessThan);
    tree.Insert(14,lessThan);
    tree.Insert(10,lessThan);
    tree.Insert(15,lessThan);
    tree.Insert(13,lessThan);
    tree.Insert(11,lessThan);
    tree.Insert(9,lessThan);

    copyTree = tree;

    DisplayTreeContents(copyTree); //Should be the same as the elements inserted above

    copyTree.Remove(12,lessThan);
    copyTree.Insert(20,lessThan);

    if(tree.Search(12,lessThan)){
        cout << "Found 12 (correct)" << endl;
    }
    if(tree.Search(20,lessThan)){
        cout << "Found 20 (incorrect)" << endl;
    }
}

void TestCopyConstructor(){ //Should display elements inserted below, and should find 20
    cout << "\n\nTest 14:\n\n";
    BST<int> tree;
    tree.Insert(12,lessThan);
    tree.Insert(14,lessThan);
    tree.Insert(10,lessThan);
    tree.Insert(15,lessThan);
    tree.Insert(13,lessThan);
    tree.Insert(11,lessThan);
    tree.Insert(9,lessThan);

    BST<int> copyTree(tree);

    DisplayTreeContents(copyTree); //Should be the same as the elements inserted above

    copyTree.Remove(12,lessThan);
    copyTree.Insert(20,lessThan);

    if(tree.Search(12, lessThan)){
        cout << "Found 12 (correct)" << endl;
    }
    if(tree.Search(20, lessThan)){
        cout << "Found 20 (incorrect)" << endl;
    }
}

int main()
{
    TestFirstInsertion(); //Tests inserting 0 to 49, then removes zero and checks to see if everything is correct
    LargeThenSmall(); //Tests inserting a large number then small, Then deleting the large root and seeing if the small correctly becomes root
    RemoveRootWithTwoChildren(); //Tests removing a root with two direct children
    RemoveLeftChildNoChild(); //Removes child from root with no sub-children
    RemoveLeftChildRightChild(); //Removes child with a right sub-child
    RemoveLeftChildLeftChild(); //REmoves child with a left sub-child
    RemoveLeftChildTwoChild(); //Removes child with two sub-childs

    RemoveRightChildNoChild(); //Removes child from root with no sub-children
    RemoveRightChildRightChild(); //Removes child with a right sub-child
    RemoveRightChildLeftChild(); //REmoves child with a left sub-child
    RemoveRightChildTwoChild(); //Removes child with two sub-childs
    TestMemoryLeak(); //Tests for improper clearing of memory anywhere in insert and remove methods

    for(int i = 0;i<10000000;i++){
        TestDestructor(); //Makes sure destructor properly erases all memory (program will crash if problem occurs)
    }

    TestEqualsOperator();
    TestCopyConstructor();
    return 0;
}
