#include <iostream>
using namespace std;

int findRotationIndex(int arr[], int size){
    int start, mid, end;
    start = 0;
    end = size-1;
    
    while(start+1 < end){
        mid = ((end - start)/2) + start;
        
        if(arr[mid] < arr[start])
            end = mid;
        else if(arr[mid] > arr[end])
            start = mid;
        else
            return -1;
    }
    return end;
}




int main() {
//     int arr[] = {4, 5, 6, 7, 8, 1, 2};
    int arr[] = {5, 6, 1, 2, 3, 4};
    
    cout << findRotationIndex(arr, 6) << endl;
    
    return 0;
}
