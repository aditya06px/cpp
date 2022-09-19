#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int findSum(int arr[],int k,int len) {
    int maxx = INT_MIN;
    int i = 0;       //start of the window
    int j = 0;       //end of the window
    int sum = 0;
    while(j< len) {
       
       //calculations
        sum += arr[j];

        if(j-i+1 < k) {     // if size of window less than k
            j++;
        }

        else if(j-i+1 == k) {
        // if size of window is same     
            maxx = max(maxx,sum);  //ans from calculations
            sum -= arr[i];

            //sliding the window 
            i++;
            j++;
        }
    }


    return maxx;
}
int main() {

    int arr[] = {1,5,4,3,14,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<< findSum(arr,3,len); 
    return 0;
}