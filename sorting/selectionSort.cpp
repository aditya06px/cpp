#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void selectionSort(int arr[],int n) {

    for(int step = 0;step<n-1;step++) {
        int max_index = step;

        for(int i = step+1;i<n;i++) {
            if(arr[i] > arr[max_index]) {
                max_index = i;
            }
        }

        swap(arr[step],arr[max_index]);
    }
}

int main() {
        int arr[] = {20,10,50,40,30};
        int n = 5;

        selectionSort(arr,n);

        for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
        }

        return 0;
}