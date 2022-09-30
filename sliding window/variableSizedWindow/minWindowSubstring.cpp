#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int minWindowSubstring(string s, string t) {
    int minW = INT_MAX;
    int i= 0,j=0;
    map<char,int>mp;

    //put t string in a map
    for(int k = 0;k<t.size();k++) {
        mp[t[k]]++;
    }

    //to check condition
    int count = mp.size();

    while(j<s.size()) {

        //if s[j] present in map;
        if(mp.find(s[j]) != mp.end()) {
            mp[s[j]]--;

            if(mp[s[j]] == 0) {
                count--;  // it means we have sufficient amount of single letter s[j] in window
            }
        }

        if(count > 0 ) {
            j++;  //    it means we don't have sufficient amount of letters in window
        }
        else if(count == 0) {
            minW = min(minW,j-i+1);  // check for min
            
            //optimizing solution , check if there are more number of letters than needed in window 
            // and can we remove it
            while(count == 0) {

                //if not present in map move i , will not affect the map just decrease the window size
                 if(mp.find(s[i]) == mp.end()){
                    i++;
                    minW = min(minW,j-i+1);
                }
                  else {
                    mp[s[i]]++;  

                    if(mp[s[i]] > 0) {
                        count++;
                    }
                    else {
                        i++;
                        minW = min(minW,j-i+1);
                    }
                          
                  }  
            }
            j++;
        }
    }

    cout<<"ans is "<<minW<<endl;
    return minW;
}

int main() {
   string s = "totmtaptat";
   string t = "tta";
   cout<<minWindowSubstring(s,t);
    return 0;
}