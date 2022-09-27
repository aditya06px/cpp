#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int largestSubarrayOfSumK(vector<int>arr , int k) {
    int i=0,j=0;
    int maxN = 0;
    int sum = 0;
    while(j<arr.size()) {
          sum = sum + arr[j];

          if(sum < k) {
                j++;
          } 
          else if (sum == k) {
                maxN = max(maxN,j-i+1);
                j++;
          } 
          else if(sum > k) {
                while(sum > k) {
                    sum = sum - arr[i];
                    i++;
                }
                j++;
          }

    }

    return maxN;
}
int main() {
    
    vector<int>arr = {4,1,1,1,1,1,2,3,5};
    int k = 5;
    cout<<largestSubarrayOfSumK(arr,k);
    return 0;
}