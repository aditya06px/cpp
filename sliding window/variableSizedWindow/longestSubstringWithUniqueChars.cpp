#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestSubstringWithAlluniqueChars(string s) {
    int maxWindow = INT_MIN;
    int i=0,j=0;
    map<char,int>mp;

    while(j<s.size()) {

        mp[s[j]]++;

        if(mp.size() == j-i+1) {
            maxWindow = max(maxWindow,j-i+1);
            j++;
        }

        else if(mp.size() < j-i+1) {
                while(mp.size()< j-i+1) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
        }
    }

    return maxWindow;

}
int main() {
    string s = "aditya";
    cout<<longestSubstringWithAlluniqueChars(s);
    return 0;
}