#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int longestSubStringWithKUniqChar(string s,int k) {
    int maxN = 0 ;
    int i = 0,j=0;
    map<char,int>mp; 

    while (j<s.size())
    {
        mp[s[j]]++;

        if(mp.size() < k ) {
            j++;
        }
        else if(mp.size() == k) {
            maxN = max(maxN,j-i+1);
            j++;
        }
        else if(mp.size() > k) {
            while(mp.size() > k) {
                 mp[s[i]]--;
                 if(mp[s[i]] == 0) {
                    mp.erase(s[i]);
                 }
                 i++;   
            }
            j++;
        }
    }

    return maxN;
    

}

int main() {

    string s = "aabbcc";
    int k = 3;
    cout<<longestSubStringWithKUniqChar(s,2);
    return 0;
}