/** @file BST.h - Binary Search Tree definition
    @author Keo Tom-Shaw
    @date 14/05/2018
    @version 2
*/

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <iostream> //Included for use of NULL, no io is done in the class

using namespace std;

///A BST Node which contains data and points to two other Nodes
template <typename Type>
struct Node{
    ///Data stored in Node
    Type data;
    ///Pointer to the left sub-Node
    Node<Type> *leftNode;
    ///Pointer to the right sub-Node
    Node<Type> *rightNode;
};

///A binary search tree class which can store any data type. All data is stored in order so that binary search can be used when accessing elements. Data cannot appear twice in the tree.
template <typename Type>
class BST{

    /** A function pointer which takes a parameter of const Type& and returns void.
        @param outData The data stored in the tree which will be sent to the Callback
        @return void
    */
    typedef void (*OutputCallback)(const Type& outData);

    /** A function pointer which takes two parameters of type const Type&, and returns a boolean if the left-hand parameter is less than the right
        @param left The left-hand operand of the < operator.
        @param right The right-hand operand of the < operator.
        @return Returns true if left is less than right, otherwise it returns false.
    */
    typedef bool (*LessThan)(const Type& left, const Type& right);

    public:
        ///Default constructor
        BST();

        ///copy constructor
        BST(const BST<Type>& copiedTree);

        ///Destructor
        ~BST();

        /** Equals operator, copies the right operand into the left operand, and returns the operand which has been copied to.
            @param copiedTree The right operand which is to be copied
            @return A reference to the BST which has been overridden.
        */
        const BST& operator =(const BST<Type>& copiedTree);

        /** Method for inserting an element, type, into the tree
            @param type The Type reference which is to be inserted into the BST
            @param lessThan callback function of type LessThan which takes two parameters and returns true if the left operand is less than the right
            @return void
        */
        void Insert(const Type& type, LessThan lessThan);

        /** Method for removing an element from the BST
            @param type Element to be removed from the BST
            @param lessThan callback function of type LessThan which takes two parameters and returns true if the left operand is less than the right
            @return void
        */
        void Remove(const Type& type, LessThan lessThan);

        /** Method for searching the BST to see if an element exists inside it.
            @param type Element to be searched for.
            @param lessThan callback function of type LessThan which takes two parameters and returns true if the left operand is less than the right
            @return True if type exists in the tree.
        */
        bool Search(const Type& type, LessThan lessThan) const;

        /** Traverses the BST in order and sends each element to the callback function (func).
            @param func Function which takes a single parameter of type const Type&
            @return void
        */
        void Traversal(OutputCallback func) const;


    private:

        ///Pointer to the root node of the BST
        Node<Type> *root;

        /** Recursive function which copies a BST into another BST.
            @param copiedRoot The pointer to the Node to be copied into otherRoot
            @param otherRoot The pointer to the Node to receive copiedRoot's data
            @return void
        */
        void CopyTree(Node<Type> *copiedRoot, Node<Type>* &otherRoot);

        /** Recursive function to delete a tree (called by destructor)
            @param rootNode The pointer to the root of the BST
            @return void
        */
        void DeleteTree(Node<Type>* &rootNode);

        /** Recursive function for inserting an element into the BST
            @param newNode The pointer to the Node which is to be inserted into BST
            @param rootNode The pointer to the root of the BST
            @param lessThan callback function of type LessThan which takes two parameters and returns true if the left operand is less than the right
            @return void
        */
        void Insert(Node<Type>* &newNode, Node<Type>* &rootNode, LessThan lessThan);

        /** Recursive function for removing an element from the BST
            @param type const Type& element to be removed from tree
            @param rootNode The pointer to the root Node of the BST
            @param parentNode The pointer to the parent Node of rootNode, this is NULL if rootNode has no parent.
            @param lessThan callback function of type LessThan which takes two parameters and returns true if the left operand is less than the right
            @return void
        */
        void Remove(const Type& type, Node<Type>* rootNode, Node<Type>* parentNode, LessThan lessThan);

        /** Recursive function for searching the BST for an element.
            @param type The const Type& element to be searched for
            @param rootNode Pointer to the root of the BST
            @param lessThan callback function of type LessThan which takes two parameters and returns true if the left operand is less than the right
            @return True if the item is in the tree, else false.
        */
        bool Search(const Type& type, Node<Type> *rootNode, LessThan lessThan) const;

        /** Traverses the BST in order and sends each element to the callback function (func).
            @param rootNode Pointer to the root of the BST
            @param func Function which takes a single parameter of type const Type&
            @return void
        */
        void InOrderTraversal(Node<Type> *rootNode, OutputCallback func) const;
};

template <typename Type>
BST<Type>::BST(){
    root = NULL;
}

template <typename Type>
BST<Type>::BST(const BST<Type>& copiedTree){
    CopyTree(copiedTree.root, root);
}

template <typename Type>
void BST<Type>::CopyTree(Node<Type> *copied, Node<Type>* &otherRoot){
    if(copied==NULL){
        otherRoot = NULL;
    }

    else{
        otherRoot = new Node<Type>;
        otherRoot->data = copied->data;
        CopyTree(copied->leftNode, otherRoot->leftNode);
        CopyTree(copied->rightNode, otherRoot->rightNode);
    }
}

template <typename Type>
BST<Type>::~BST(){
    DeleteTree(root);
}

template <typename Type>
void BST<Type>::DeleteTree(Node<Type>* &rootNode){
    if(rootNode != NULL){
        DeleteTree(rootNode->leftNode);
        DeleteTree(rootNode->rightNode);
        delete rootNode;
        rootNode = NULL;
    }
}

template <typename Type>
const BST<Type>& BST<Type>::operator =(const BST<Type>& copiedTree){
    if(this != &copiedTree){
        if(root != NULL){
            DeleteTree(root);
        }
        CopyTree(copiedTree.root, root);
    }

    return *this;
}

template <typename Type>
void BST<Type>::Insert(const Type& type, LessThan lessThan){
    Node<Type> *newNode = new Node<Type>;
    newNode->data = type;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;

    Insert(newNode, root, lessThan);
}

template <typename Type>
void BST<Type>::Insert(Node<Type>* &newNode, Node<Type>* &rootNode, LessThan lessThan){
    if(rootNode == NULL){
        rootNode = newNode; //Node is empty, so insert new node here.
    }

    else if( lessThan(newNode->data, rootNode->data) ){ //The new node is less than the root, so insert into the left tree
        Insert(newNode, rootNode->leftNode, lessThan); //Recursive insertion to the left
    }

    else if( lessThan(rootNode->data, newNode->data) ){ //The new node is greater than the root, so insert into the right tree
        Insert(newNode, rootNode->rightNode, lessThan); //Recursive insertion to the right
    }

    else{ //Node already exists
        delete newNode; //So delete the new node and return
        newNode = NULL;
    }
}

template <typename Type>
void BST<Type>::Remove(const Type& type, LessThan lessThan){

    Remove(type, root, NULL, lessThan);

}

template <typename Type>
void BST<Type>::Remove(const Type& type, Node<Type>* rootNode, Node<Type>* parentNode, LessThan lessThan){
    if(rootNode == NULL){
        return;
    }

    if(lessThan(type, rootNode->data)){

        Remove(type, rootNode->leftNode, rootNode, lessThan);

    }else if(lessThan(rootNode->data, type)){

        Remove(type, rootNode->rightNode, rootNode, lessThan);

    }else{ //Root node has to be removed because a is the same as its data
        if(parentNode != NULL){ //If there is no parent then the children have to be shuffled up without changing the parent's children pointers (because there is no parent)
            if(parentNode->leftNode == rootNode){ //The parent's left node is the one to be removed
                if(rootNode->leftNode != NULL){ // In this case because the root's left node is not null, it is used as the new branch beneath the parent
                    parentNode->leftNode = rootNode->leftNode; // Parent's left node is now root node's left
                    if(rootNode->rightNode != NULL){ //If root node's right node is not empty, insert it into the old left node
                        Insert(rootNode->rightNode,parentNode->leftNode, lessThan);
                    }
                } else if(rootNode->rightNode != NULL){ //If root node's left is empty, but right full, then make the parent's left node root's right node
                    parentNode->leftNode = rootNode->rightNode;
                } else parentNode->leftNode = NULL; //If both branches of root node are empty, parent's left pointer is now null.

            } else{ //The parent's right node is the one to be removed
                if(rootNode->leftNode != NULL){ //If the root node's left node isn't null
                    parentNode->rightNode = rootNode->leftNode; //Make the parent's right node the root's left
                    if(rootNode->rightNode != NULL){ //If the root had a populated right node
                        Insert(rootNode->rightNode,parentNode->rightNode, lessThan); //Insert that node into the parent's new right node
                    }
                } else if(rootNode->rightNode != NULL){ //If the root's right node is populated and the left isn't
                    parentNode->rightNode = rootNode->rightNode; //Make the parent's right node the root's right
                } else parentNode->rightNode = NULL; //Otherwise the parent's right is null because the root didn't have any children
            }
        }else{
            if(rootNode->leftNode != NULL){
                if(rootNode->rightNode != NULL){
                    Node<Type> *temp = rootNode->rightNode;
                    root = rootNode->leftNode;
                    Insert(temp, root, lessThan);
                }
                else {
                    root = rootNode->leftNode;
                }
            }else if(rootNode->rightNode != NULL){
                root = rootNode->rightNode;
            } else root = NULL;
        }
        delete rootNode; //Clears memory from the deleted root node
        rootNode = NULL;
    }
}

template <typename Type>
bool BST<Type>::Search(const Type& type, LessThan lessThan) const{
    return Search(type, root, lessThan);
}

template <typename Type>
bool BST<Type>::Search(const Type& type, Node<Type> *rootNode, LessThan lessThan) const{
    if(rootNode == NULL){
        return false;
    }

    if(lessThan(type, rootNode->data)){
        return Search(type, rootNode->leftNode, lessThan);
    }

    else if(lessThan(rootNode->data, type)){
        return Search(type, rootNode->rightNode, lessThan);
    }

    else return true;
}

template <typename Type>
void BST<Type>::Traversal(OutputCallback func) const{
    InOrderTraversal(root, func);
}

template <typename Type>
void BST<Type>::InOrderTraversal(Node<Type> *rootNode, OutputCallback func) const{
    if(rootNode != NULL){
        InOrderTraversal(rootNode->leftNode, func);
        func(rootNode->data);
        InOrderTraversal(rootNode->rightNode, func);
    }
}


#endif // BST_H_INCLUDED
