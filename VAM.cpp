#include<bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

bool cmp(const pair<char, int>&a, const pair<char,int>&b){
    return a.second > b.second;
}

int main(){
    char ch;
    int K;
    cout<<"\n\nEnter K value and Input Item\n\n"<<endl;
    cin>>K>>ch;
    map<char,int>supportCnt;
    map<int, string> originalData;
    map<char, vector<int>> vamDS;
    for(char ch = 'a'; ch<='z'; ch++){
        vector<int>v;
        vamDS[ch] = v;
    }

    fstream newfile;
    newfile.open("dataset/db.txt",ios::in);
    if (newfile.is_open()){
        string tp;
        int cnt = 0;
        while(getline(newfile, tp)){
            cnt++;
            originalData[cnt] = tp;
            // cout << tp << "\n";
            for(int i=0; i<tp.length(); i++){
                vamDS[tp[i]].push_back(cnt);
            }
        }
        newfile.close();
    }
    cout<<"\nCreating Table...\n";
    std::chrono::seconds dura( 5);
    std::this_thread::sleep_for( dura );
    for(auto it = vamDS.begin(); it != vamDS.end(); it++){
        cout<<"__________________________________________________________________________________________\n\n";
        cout<<(it->first)<<": ";
        vector<int>vj = it->second;
        for(int j=0; j<vj.size(); j++){
            cout<<vj[j]<<" ";
        }
        cout<<endl;
    }
    cout<<"__________________________________________________________________________________________\n\n";
    vector<int>vj = vamDS[ch];
    for(int i=0; i<vj.size(); i++){
        int sid = vj[i];
        string s = originalData[sid];
        for(int j=0; j<s.length(); j++){
            supportCnt[s[j]]++;
        }
    }
    vector<pair<char,int>>pq;
    for(auto i : supportCnt){
        pq.push_back({i.first, i.second});
    }
    sort(pq.begin(), pq.end(), cmp);
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"These are the top K elements we have : \n\n\n";
    cout<<"\t\t-------\n";
    for(int i=0; i<K; i++){
        cout<<"\t\t|  "<<pq[i].first<<"  |\n";
        cout<<"\t\t-------\n";
    }
    cout<<"\n\n";
    return 0;
}