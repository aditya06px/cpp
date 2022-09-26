#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// vector<int> maxNumInEveryWindow(vector<int>arr,int k) {
//     vector<int>ans;
//     int i=0,j=0;
//     int max_num = INT_MIN;
//     while(j<arr.size()) {
//         max_num = max(max_num,arr[j]);

//         if(j-i+1 < k) {
//             j++;
//         }
//         else if(j-i+1 == k) {
//             //ans 
//             ans.push_back(max_num);  
//             //slide the window
            
//             if(max_num == arr[i]) {
//                 int temp = INT_MIN;
//                int k = i+1;
//                while(k<j) {
//                 temp = max(temp,arr[k]);
//                 k++;
//                }
            
//             max_num = temp;
//             }

//             i++;
//             j++;
//         }

//     }

//     return ans;
// }
vector<int> maxNumInEveryWindow(vector<int>arr,int k) {
    vector<int>ans;
    int i=0,j=0;
    deque<int>list;
    while(j<arr.size()) {
        
        //smaller than arr[j] -- arr[j]  -- smaller than arr[j]
        // starts popping from left so arr[j] will alaways be greater in above case
     
        //if list elements are less than arr[j] then 
        // pop them cause 
        while(list.back() < arr[j] && list.size() != 0) {
            list.pop_back();
        }

        list.push_back(arr[j]);
       
        if(j-i+1 < k) {
            j++;
        }
        else if(j-i+1 == k) {
            //ans 
            ans.push_back(list.front());
            
            //slide the window
            if(list.front() == arr[i]) {
               list.pop_front();
            }

            i++;
            j++;
        }

    }

    return ans;
}

int main() {
   vector<int>arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
   vector<int>v1 = maxNumInEveryWindow(arr,3);

   for(auto x: v1) {
    cout<<x<<" ";
   }
    return 0;
}