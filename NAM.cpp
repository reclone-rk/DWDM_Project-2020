#include<bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

bool cmp(const pair<char, int>&a, const pair<char,int>&b){
    return a.second > b.second;
}

int main(){
    clock_t start, end; 
    start = clock(); 
    char ch = 'k';
    int K = 3;
    // cout<<"\n\nEnter K value and Input Item\n\n"<<endl;
    // cin>>K>>ch;
    map<char,int>supportCnt;
    fstream newfile;
    newfile.open("dataset/db.txt",ios::in);
    if (newfile.is_open()){
        string tp;
        int cnt = 0;
        while(getline(newfile, tp)){
            cnt++;
            // cout << tp << "\n";
            int flag = 0;
            for(int i=0; i<tp.length(); i++){
                // if(tp[i] == ch){
                //     flag = 1;
                // }
                // if(flag == 0){
                //     continue;
                // }
              
                supportCnt[tp[i]]++;
            }
        }
        newfile.close();
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
    end = clock(); 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  << time_taken << setprecision(5); 
    cout << " sec " << endl; 
    return 0;
}

// VIAM : 0.003721 sec
// VAM  : 0.003920 sec
// NAM : 0.000536 sec 