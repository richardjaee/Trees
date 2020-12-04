#include "WordTree.h"
#include <cassert>

using namespace std;
int main(){
    

   

    WordTree w;
    w.add(4);
    w.add(2);
    w.add(5);w.add(1);w.add(3);w.add(7);
    int product = 4;
    
    cout << w << endl;
    cout << w.tf(product);
        
    
    
}
