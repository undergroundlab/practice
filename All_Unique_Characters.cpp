#include <iostream>
#include <string>
using namespace std;


bool isAllUniqueChar(string s){
    unsigned int bitVector = 0;
    
    for(int i=0; i < s.size(); i++){
        int charValue = s[i] - 'a';
        if(bitVector & (1 << charValue)){
            return false;
        }
        else{
            bitVector |= (1 << charValue);
        }
    }
    
    return true;
}



int main() {
    
    cout << isAllUniqueChar("harrypotter") << endl;
    cout << isAllUniqueChar("abcdefghijklmnopqrstuvwxyz") << endl;
    
    return 0;
}
