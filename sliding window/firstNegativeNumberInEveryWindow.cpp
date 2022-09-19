#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> firstNegativeNumberInEveryWindow(int arr[],int k,int len) {

    queue<int>list;
    vector<int>ans;

    int i = 0;
    int j = 0;

    while(j<len) {

        //calculations
        if(arr[j]<0) {
            list.push(arr[j]);
        }

        if(j-i+1 < k) {
            j++;
        }
        else if(j-i+1 == k) {
            //ans from calculations
            if(list.empty()) {
                ans.push_back(0);  // if list is empty add 0 to ans
            }
            else {
                ans.push_back(list.front());  // if not add first element
            }

            if(list.front() == arr[i]) {
                list.pop();   // remove i calculation
            }

            i++;
            j++;
        }
    }


    return ans;
}

