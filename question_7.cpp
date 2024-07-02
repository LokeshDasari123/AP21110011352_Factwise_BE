#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxScore(vector<int>& cardPoints, int k)
{
    int n = cardPoints.size();
    int windowSize = n - k; 
    
    int totalSum = 0; 
    for(int i=0;i<n;i++)
    {
        totalSum += cardPoints[i];
    }
    
    int currentWindowSum = 0;
    for(int i=0;i<windowSize;i++)
    {
        currentWindowSum += cardPoints[i];
    }
    
    int minSubarraySum = currentWindowSum;
    for (int i=windowSize;i<n;i++)
    {
        currentWindowSum += cardPoints[i] - cardPoints[i - windowSize];
        minSubarraySum = min(minSubarraySum, currentWindowSum);
    }
    
    return totalSum - minSubarraySum;
}

int main() {
    int n,k;
    cout<<"Enter the number of cards: ";
    cin>>n;
    
    vector<int> cardPoints(n);
    
    cout<<"Enter the card points: ";
    for (int i=0;i<n;i++)
    {
        cin>>cardPoints[i];
    }
    cout<<"Enter the value of k: ";
    cin>>k;
    
    int result = maxScore(cardPoints, k);
    cout<<"Maximum score for the test case: "<<result<<endl;
    
    return 0;
}
