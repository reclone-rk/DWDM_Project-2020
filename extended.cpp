#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<char, int>&a, const pair<char,int>&b){
    return a.second > b.second;
}

int main(){
    clock_t start, end;
    char ch = 'k';
    int K = 3;
    fstream newfile;
    unordered_map<char, vector<int>> supportV;
    newfile.open("dataset/db.txt",ios::in);
    for(char c = 'a'; c<='z'; c++){
        vector<int>arr(26, 0);
        if (newfile.is_open()){
            string tp;
            int cnt = 0;
            while(getline(newfile, tp)){
                // cout << tp << "\n";
                for(int j=0; j<tp.size(); j++){
                    arr[tp[j]-'a']++;
                }
            }
            newfile.close();
        }
        supportV[c] = arr;
    }
    start = clock(); 
    vector<pair<int,int>>vp;
    for(int i=0; i<supportV[ch].size(); i++){
      vp.push_back({i, supportV[ch][i]});
    }
    sort(vp.begin(), vp.end(), cmp);
    for(int i=0; i<K; i++){
        char rch = (char) (vp[i].first + 'a');
        cout<<rch<<endl;
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  << time_taken << setprecision(5); 
    cout << " sec " << endl; 
    return 0;
}