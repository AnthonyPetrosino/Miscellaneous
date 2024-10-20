#include<iostream>
#include<random>
#include<unordered_set>

using namespace std;

/*
Precondition: 
    n is a positive integer greater than 2
Postcondition: 
    return S, a set of two integers picked 
    randomly from {1, 2, ..., n}
*/
unordered_set<int> randomSample2(int n){
    unordered_set<int> S;
    // TODO:
    // Implement the algorithm from Problem 2
    
    
    return S;
}

void printSet(unordered_set<int> S){
    for(auto it = S.begin(); it != S.end(); it++)
        cout << *it << " ";
    cout << "\n";
}

int main(){

    int n;
    cin >> n;
    for(int i = 0; i < 10; i++){
        unordered_set<int> S = randomSample2(n);
        cout << "Experiment " << i + 1 << ": ";
        printSet(S);
    }

}