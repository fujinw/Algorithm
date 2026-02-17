#include <iostream>
#include <unordered_map>
using namespace std;


int main(){
    int n, temp;
    cin >> n;
    int targetCount = n/2;
    vector<int> votes;
    unordered_map<int, int> counts;
    for(int i = 0; i < n; i++){
        cin >> temp;
        votes.push_back(temp);
        counts[temp]++;
    }

    for(auto [key, value]: counts){
        if(value > targetCount){
            cout << key << endl;
            return 0;
        }
    }
    cout << "Нет такого проекта";
    return 0;
}