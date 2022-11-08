#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    //to loop over array
        for(int step = 0;step<n-1;step++) {
            

            for(int i=0;i<n-1-step;i++) {
                //find max number and put it at the last 
                //of unsorted array
                    if(arr[i] > arr[i+1] ) {
                        swap(arr[i],arr[i+1]);
                    }
            }
        }
}

int main() {
        int arr[] = {20,10,50,40,30};
        int n = 5;

        bubbleSort(arr,n);

        for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
        }

        return 0;
}