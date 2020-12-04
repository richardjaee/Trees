
#ifndef WORDTREE_INCLUDED
#define WORDTREE_INCLUDED

#include <iostream>
#include <string>

typedef int WordType;
struct WordNode {
    WordType m_data;
    WordNode *m_left;
    WordNode *m_right;
    
    int count = 0;
    
   // You may add additional data members and member functions
   // in WordNode
};
class WordTree {
private:
    WordNode *root;
    
    // NAME: swap
    // INPUT: A reference to a WordTree
    // OUTPUT: None, void
    // DESCRIPTION: swaps the WordTree with the passed in WordTree
    void swap(WordTree &rhs);

    
    // NAME: assignment
    // INPUT: pointer to WordNode
    // OUTPUT: None, void
    // DESCRIPTION: assignment operator helper
    void assignment(WordNode * curr);
    
    // NAME: CopyConstructor
    // INPUT: pointer to WordNode, pointer to rhs WordNode
    // OUTPUT: None, void
    // DESCRIPTION: Copy Constructor Helper
    void copyConstructor(WordNode * &curr, WordNode * rhsCurr);
    
    // NAME: destructor
    // INPUT: reference to a pointer to WordNode
    // OUTPUT: none
    // DESCRIPTION: Destructor Helper
    void destructor(WordNode * &curr);
    
    // NAME: InOrder
    // INPUT: pointer to WordNode, ostream out
    // OUTPUT: None, void
    // DESCRIPTION: Prints the tree in order
    void InOrder(WordNode * curr, std::ostream &out) const;
    
    // NAME: distinctCount
    // INPUT: pointer to WordNode
    // OUTPUT: an integer
    // DESCRIPTION: returns an integer that shows the amount of distinct words
    int distinctCount(WordNode * curr) const;
    
    // NAME: totalCount
    // INPUT: pointer to WordNode
    // OUTPUT: an integer
    // DESCRIPTION: returns an itneger that shows the total number of words inserted
    int totalCount(WordNode * curr) const;
    bool productOfTheRoad(WordNode* node, double product);

public:
    
    // NAME: defauly constructor
    // INPUT: None
    // OUTPUT: None
    // DESCRIPTION: default constructor
    WordTree() : root(nullptr) { };
    
      
    bool tf(int product);
    // NAME: copy constructor
    // INPUT: a constant reference to a WordTree
    // OUTPUT: None
    // DESCRIPTION: copy constructor
    WordTree(const WordTree& rhs);
    

    
    // NAME: assignment operator
    // INPUT: A constant reference to a wordTree
    // OUTPUT: a WordTree
    // DESCRIPTION: overloads assignment operator
  const WordTree& operator=(const WordTree& rhs);
    
      
    
    // NAME: add
    // INPUT: WordType variable
    // OUTPUT: None, void
    // DESCRIPTION: Inserts v into the WordTree
    void add(WordType v);
    
      
    
    // NAME: distinctWords
    // INPUT: None
    // OUTPUT: integer of distinct words
    // DESCRIPTION: Returns the number of distinct words nodes
   int distinctWords() const;
    
      
    
    // NAME: totalWords
    // INPUT: none
    // OUTPUT: integer of total number of words
    // DESCRIPTION: Returns the total number of words inserted, including duplicate values
   int totalWords() const;
    
          
    
    // NAME: ostream operator
    // INPUT: ostream out, a constant reference to a WordTree
    // OUTPUT: ostream
    // DESCRIPTION: Prints the LinkedList
    friend std::ostream& operator<<(std::ostream &out, const WordTree& rhs);
    
    
    // NAME: Destructor
    // INPUT: None
    // OUTPUT: None
    // DESCRIPTION: Destroys all the dynamically allocated memory in the tree
   ~WordTree();
    };

#endif //WORDTREE_INCLUDED
