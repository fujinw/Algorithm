#include <iostream> 
#include <vector>
using namespace std;


// Для решения данной задачи предположу, что оценки выставляются, как в школе
// То есть от 1го до 5ти( не обязательно брать такой отрезок
// но потолок оценок/баллов явно должен быть конечным ).
// Тогда задачу можно решить за О(n) по скорости
// при помощи подсчета количества каждой из оценок
// и динамического программирования.
int main(){
    int n;
    cin >> n;

    int temp;
    int supp[5] = {0,0,0,0,0};
    for(int i = 0; i < n; i++){
        cin >> temp;
        supp[temp - 1]++;
    }
    int sum = supp[0] + supp[1]*2 + supp[2]*3 + supp[3]*4 + supp[4]*5;
    
    if(sum%2 != 0){
        cout << "NO" << endl;
        return 0;
    }
    int target = sum/2;
    vector<int> dp(target+1, -1);
    dp[0] = 0;

    for(int m = 1; m <= 5; m++){ // перебираем в отрезке оценок m(mark)
        int count = supp[m-1];
        for(int s = 0; s <= target; s++){
            if(dp[s] >= 0){
                dp[s] = count;
            }else if( s >= m && dp[s - m] > 0){
                dp[s] = dp[s - m] - 1;
            }else{
                dp[s] = -1;
            }
        }
    }
    
    if (dp[target] >= 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;

}