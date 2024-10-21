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
    
    for(int k = n - 1; k <= n; k++){
        // Set sample to a random int between 1 and k
        int sample = rand() % k + 1;
        // Either add sample or n to the set
        if (S.find(sample) != S.end())
        {
            S.insert(k);
        }
        else
        {
            S.insert(sample);
        }
    }
    
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