#include <iostream>
#include <string>
using namespace std;


bool isPermutation(string str1, string str2){
    if(str1.size() != str2.size())
        return false;
    
    int allChars[128] = {0};
    
    for(char c : str1){
        allChars[c]++;
    }
    
    for(char c : str2){
        allChars[c]--;
        if(allChars[c] < 0){
            return false;
        }
    }
    
    return true;
}




int main() {
    string str1 = "awesome";
    string str2 = "someawe";
    string str3 = "what?";
    
    
    cout << isPermutation(str1, str2) << endl;
    cout << isPermutation(str1, str3) << endl;
    
    
    return 0;
}
