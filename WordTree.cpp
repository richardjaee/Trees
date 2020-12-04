#include "WordTree.h"

WordTree::WordTree(const WordTree& rhs){
    
    if (rhs.root == nullptr){ //if the tree is empty
        root = nullptr; //set the root equal to nullptr
        return;
    }
    copyConstructor(root, rhs.root); //else call the copyConstructor helper
}

const WordTree& WordTree::operator=(const WordTree& rhs){
    if (this != &rhs){ //copy and swap
        WordTree temp = rhs;
        temp.swap(*this);
    }
    return *this; //return this
}

void WordTree::swap( WordTree &rhs){
    WordNode*temp = root; //create a temporary WordNode pointer equal to root
    root = rhs.root; //set root equal to the parameter's root
    rhs.root = temp; //set the parameter's root equal to temp
}

void WordTree::copyConstructor(WordNode * &curr, WordNode * rhsCurr){
    if (rhsCurr == nullptr){ //empty tree, base call
        return;
    }
    
    curr = new WordNode; //create a new WordNode
    curr->m_data = rhsCurr->m_data; //set curr's m_data equal to the rhs's m_data
    curr->count = rhsCurr->count; //set curr's count equal to the rhs's count
    curr->m_left = nullptr; //set curr's m_left and m_right equal to nullptr
    curr->m_right = nullptr;
    
    copyConstructor(curr->m_left, rhsCurr->m_left); //recursive call for the left side of the tree
    copyConstructor(curr->m_right, rhsCurr->m_right); //recursive call for the ight side of the tree
    
}

WordTree::~WordTree(){
    destructor(root); //call destructor helper with root as a parameter
}

void WordTree::destructor(WordNode * &curr){
    if (curr == nullptr){ //base case
        return;
    }
    destructor(curr->m_left); //recursive call on left side of tree
    destructor(curr->m_right); //recursive call on right side of tree
    delete curr; //delete current pointer
    curr = nullptr; //set curr equal to nullptr
}
bool WordTree::productOfTheRoad(WordNode* node, double product){
    
    if (node == nullp-t)
        return false;
        
    if (product == 1){
    return true;
    }

    return (productOfTheRoad(node->m_left, product/node->m_data) || productOfTheRoad(node->m_right, product/node->m_data));
    
    
}
bool WordTree::tf(int product){
    
    return productOfTheRoad(root, product);
}
void WordTree::add(WordType v){
    if (root == nullptr){ //if the root is a nullptr, if the tree is empty
        WordNode *newWordNode = new WordNode; //create a new wordNode
        newWordNode -> m_data = v; //set the new WordNode's m_data equal to v
        newWordNode -> count++; //increment newWordNode's count
        root = newWordNode; //set root equal to the newWordNode
        newWordNode->m_left = nullptr; //set the new WordNode's m_left equal to nullptr
        newWordNode->m_right = nullptr; //set the new WordNode's m_right equal to nullptr
        return;
    }
    
    WordNode*curr = root;
    for (;;){ //will continuously iterate
        if (v == curr->m_data){
            curr->count++; //increment count
            return; //duplicate found
        }
        else if (v < curr->m_data){
            if (curr->m_left != NULL){ //if there exists another left node
                curr = curr->m_left;
            }
            else{ //the node to the left does not exist
                WordNode *newWordNode = new WordNode; //create a new wordNode
                newWordNode -> m_data = v;
                
                curr->m_left = newWordNode; //set curr's pointer to m_left equal to the new WordNode
                
                curr->m_left->count++; //increment count
                curr->m_left->m_right = NULL; //set curr's pointer to m_left's pointer to m_right equal to NULL
                curr->m_left->m_left = NULL; //set curr's pointer to m_left's pointer to m_left equal to NULL
                return;
            }
        }
        else if (v > curr->m_data){
            if (curr->m_right != NULL){ //if there exists a right node
                curr = curr->m_right;
            }
            else{
                WordNode *newWordNode = new WordNode; //create a new wordNode
                newWordNode -> m_data = v;
                
                curr->m_right = newWordNode; //set curr's pointer to m_right equal to the new WordNode
                
                curr->m_right->count++; //increment count
                curr->m_right->m_right = NULL; //set curr's pointer to m_right's pointer to m_right equal to NULL
                curr->m_right->m_left = NULL; //set curr's pointer to m_right's pointer to m_left equal to NULL
                return;
            }
        }
    }
}

std::ostream& operator<<(std::ostream &out, const WordTree& rhs){
    
    rhs.InOrder(rhs.root, out); //call InOrder with the rhs's root
    
    return out;
}

void WordTree::InOrder(WordNode * curr, std::ostream &out) const{
    if (curr == nullptr){ //base case
        return;
    }
   
    InOrder(curr->m_left, out); //recursive call with left node
    out << curr->m_data << " " << curr->count << std::endl; //print out the curr's m_data and count
    InOrder(curr->m_right, out); //recursive call with right node
    
    
}
int WordTree::distinctCount(WordNode * curr) const {
    int count = 1; //initialize count to 1
    if (curr == NULL){ //base case
        return 0;
    }
    if (curr->m_left != NULL){ //if there exists a left node
        count += distinctCount(curr->m_left); //add count with recursive call
    }
    if (curr ->m_right != NULL){ //if there exists a right node
        count += distinctCount(curr->m_right); //add count with recursive call
    }
    return count;
}

int WordTree::totalCount(WordNode * curr) const{
    if (curr == NULL){ //base case
        return 0;
    }
    int count = curr->count; //set count equal to curr's pointer to count
    
    if (curr->m_left != NULL){ //if there exists a left node
        count += totalCount(curr->m_left); //add count with recursive call
    }
    if (curr ->m_right != NULL){ //if there exists a right node
        count += totalCount(curr->m_right); //add count with recursive call
    }
    return count;
}

int WordTree::totalWords() const{
    
    return totalCount(root); //call totalCount with root as parameter
}

int WordTree::distinctWords() const{
    
    return distinctCount(root); //call distinctCount with root as parameter
    
}
