#include <iostream> 
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 1, previous, current;
    int maxCount = -1;
    cin >> previous;
    for(int i = 1; i < n; i++){
        cin >> current;
        if(current == previous){
            count++;
        }else{
            maxCount = max(maxCount, count);
            count = 1;
        }
        previous = current;
    }
    cout << maxCount << endl;
    return 0;
}