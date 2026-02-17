#include <iostream> 
#include <vector>
using namespace std;


bool (int sum, int arr, int size = 5){
    if (sum% 2 == 1) return false;
    int target = sum/2;


}


// Для решения данной задачи предположу, что оценки выставляются, как в школе
// То есть от 1го до 5ти
// Тогда задачу можно решить за О(n) при помощи подсчета количества каждой из оценок 
int main(){
    int n;
    cin >> n;

    int temp;
    int supp[5] = {0,0,0,0,0};
    for(int i = 0; i < n; i++){
        cin >> temp;
        supp[temp - 1]++;
    }
    int sum = supp[0] + supp[1]*2 + supp[2]*3 + supp[3]*4 + supp[4]*5
    
}