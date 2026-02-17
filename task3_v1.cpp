#include <iostream>
#include <vector>
using namespace std;

int majorityVote(vector<int> v){ // алгоритм Бойера-Мура Majority Vote
    int candidate, count;
    for(int i = 0; i < v.size(); i++){
        if (count == 0){
            candidate = v[i];
            count = 1;
        }else if(v[i] == candidate){
            count++;
        }else{
            count--;
        }
    }

    count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == candidate){
            count++;
        }
    }
    if(count > v.size()/2){
        return candidate;
    }else{
        return -1;
    }
}

// работает столько же по времени, 
// сколько и вторая версия решения задания (через map)
// но занимает О(1) памяти

int main(){
    int n, temp;
    cin >> n;
    vector<int> votes;
    for(int i = 0; i < n; i++){
        cin >> temp;
        votes.push_back(temp);
    }

    int result = majorityVote(votes);
    if(result == - 1){
        cout << "Нет такого проекта" << endl;
        return 0;
    }
    cout << result << endl;
    return 0;
}
