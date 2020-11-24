#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<char, int>&a, const pair<char,int>&b){
    return a.second > b.second;
}

int main(){
    char ch;
    int K;
    cin>>ch>>K;
    map<char,int>supportCnt;
    map<int, string> originalData;
    map<char, vector<pair<int,int>>> vamDS;
    for(char ch = 'a'; ch<='z'; ch++){
        vector<pair<int,int>>v;
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
                vamDS[tp[i]].push_back({cnt, i+1});
            }
        }
        newfile.close();
    }

    for(auto it = vamDS.begin(); it != vamDS.end(); it++){
        cout<<(it->first)<<": ";
        vector<pair<int,int>>vj = it->second;
        for(int j=0; j<vj.size(); j++){
            cout<<"["<<vj[j].first<<","<<vj[j].second<<"]"<<" ";
        }
        cout<<endl;
    }
    vector<pair<int,int>>vj = vamDS[ch];
    for(int i=0; i<vj.size(); i++){
        int sid = vj[i].first;
        int newIndex = vj[i].second + 1;
        string s = originalData[sid];
        for(int j = newIndex; j<s.length(); j++){
            supportCnt[s[j]]++;
        }
    }
    vector<pair<char,int>>pq;
    for(auto i : supportCnt){
        pq.push_back({i.first, i.second});
    }
    sort(pq.begin(), pq.end(), cmp);
    for(int i=0; i<K; i++){
        cout<<pq[i].first<<" ";
    }
    return 0;
}