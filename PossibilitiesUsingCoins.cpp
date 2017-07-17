/* Shows total possible ways to make amount using certain values of coins.
  O(n∗m) time and O(n) space where n is amount and m is number of denominations(coins)
 */

#include <iostream>
#include <vector>
#include <array>
using namespace std;

void print(vector<int> v){
    for(int i=0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


int makeChange(int total, vector<int>* denominations){
    int possibilities = 0;
    
    vector<int> amount(total+1, 0);
    amount[0] = 1;
    
    for(int coin=0; coin < denominations->size(); coin++){
        for(int currAm=1; currAm < amount.size(); currAm++){
            if(currAm - denominations->at(coin) >= 0){
                amount[currAm] += amount[currAm - denominations->at(coin)];
            }
        }
        print(amount);
    }
    
    return amount.back();
}




int main() {
    int amount = 5;
//     vector<int> denominations = {1,2,3};
    vector<int> denominations = {1,3,5};
    
    cout << makeChange(amount, &denominations);
    

    
    
    return 0;
}
