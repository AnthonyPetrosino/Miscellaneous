/*
Name: Anthony Petrosino
Homework 5

Discussion Log:

Prompted ChatGPT with general questions about syntax. Also used 
ChatGPT to run and test the code instead of writing out testing 
programs myself. Specifically prefaced every prompt with "Do not 
make any altercations to the logic or the efficiency of my code. 
Simply and breifly answer this specific question:". 

*/



#include <vector>
#include <algorithm>                                // Needed for max_element in maxContiguousSubsequenceSum

using namespace std;

vector<int> longestIncreasingSubsequence(const vector<int>& A) {

    int n = A.size();

    if (n == 0)
    {
        return {};
    }

    vector<int> L(n, 1);                            // Create L with all values initialized to 1
    vector<int> prev(n, -1);                        // Create prev with all values initialized to -1, will hold past indexes
    int maxSubsequenceIndex = 0;                    // Tracks end of the maximum subsequence

    for (int j = 1; j < n; ++j)                     // Where we are checking
    {                   
        for (int i = 0; i < j; ++i)                 // Where arrows might be from
        {               
            if (A[i] < A[j])                        // Check if there is an arrow from A[i] to A[j] 
            {                      
                if (L[j] < L[i] + 1)                // Make updates if we found a longer subsequence
                {              
                    L[j] = L[i] + 1;                // Update L[j] 
                    prev[j] = i;                    // Update the previous index
                }
            }
        }
        if (L[j] > L[maxSubsequenceIndex])          // Keep track of the index of the end of the longest subsequence
        {        
            maxSubsequenceIndex = j;                
        }
    }

    vector<int> result;                 // An empty vector to hold the longest subsequence 
    for (int i = maxSubsequenceIndex; i >= 0; i = prev[i])      // Have i start at the "last" recorded subsequence index and update i to prev[i] each iteration
    {
        result.push_back(A[i]);         // Add the value at index i to the longest subsequence
        if (prev[i] == -1) break;
    }
    
    reverse(result.begin(), result.end());     // When I created result, I created it backwards
    return result;
}

int maxContiguousSubsequenceSum(const vector<int>& A) {

    int n = A.size();

    if (n == 0)
    {
        return 0;
    }

    vector<int> maxSum(n);                          // This holds what is the maximum sum of the substring ending at each index
    maxSum[0] = A[0];

    for (int i = 1; i < n; i++)                     // Which element we are checking
    {
        maxSum[i] = A[i];                           // Setting the current maxSum to be the element's value
        if (maxSum[i - 1] + maxSum[i] > maxSum[i])  // Checks if we want to add to the current subsequence or starts a "new" one 
        {
            maxSum[i] += maxSum[i - 1];
        }
    }

    return *max_element(maxSum.begin(), maxSum.end());  // Return the highest recorded sum

}


vector<int> maxContiguousSubsequence(const vector<int>& A) {

    int n = A.size();

    if (n == 0)
    {
        return {};
    }

    vector<int> maxSum(n);                          // This holds what is the maximum sum of the substring ending at each index
    maxSum[0] = A[0];

    int maxSumValue = A[0];                         // Storing the max sum, start and end of the desired subsequence
    int start = 0;
    int end = 0;
    int temp = 0;          

    for (int i = 1; i < n; i++)                     // Which element we are checking
    {
        maxSum[i] = A[i];                           // Setting the current maxSum to be the element's value
        if (maxSum[i - 1] + maxSum[i] > maxSum[i])  // Checks if we want to add to the current subsequence or starts a "new" one 
        {
            maxSum[i] += maxSum[i - 1];             // Continue the subsequence
        }
        else 
        {   
            temp = i;                               // Create a new subsequence
        }

        if (maxSum[i] > maxSumValue) {              // If this is a new max sum subsequence, change the start and end of the desired subsequence
            maxSumValue = maxSum[i];
            start = temp;
            end = i;
        }

    }

    vector<int> result;                             // An empty subsequence that we will return
    for (int i = start; i <= end; i++) {            // Iterate through the desired indexes in A (from start to finish) appending them to result
        result.push_back(A[i]);
    }

    return result;                                  // Return the desired subsequence

}