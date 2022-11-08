#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void bubbleSort() {

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