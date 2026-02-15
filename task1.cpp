#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream> 
using namespace std;

vector<int> input(string nums){
    stringstream ss(nums);
    string word;
    vector<int> result;
    while(ss >> word){
        result.push_back(stoi(word));
    }
    return result;
}


vector<int> isNotReturn(vector<int> given, vector<int> returned){
    unordered_set<int> isReturned;
    for(int i = 0; i < returned.size(); i++){
        isReturned.insert(returned[i]);
    }
    vector<int> result;
    for(int i = 0; i < given.size(); i++){
        if(isReturned.find(given[i]) == isReturned.end()){
            result.push_back(given[i]);
        }
    }
    return result;
}



int main(){
    int lenght;
    string returned;
    vector<int> g;
    cin >> lenght;
    int temp;
    for(int i = 0; i < lenght; i++){
        cin >> temp;
        g.push_back(temp);
    }
    cin.ignore();
    getline(cin, returned);
    vector<int> r = input(returned);
    vector<int> ans = isNotReturn(g, r);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}