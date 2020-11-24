#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"\n\nEnter K value and Input Item : \n\n"<<endl;
    int inpk;
    cin>>inpk;
    char input;
    cin>>input;
    vector<int>v(26,0);
    fstream newfile;
    newfile.open("dataset/db.txt",ios::in);
    cout<<"\nComputing elements...\n";
    std::chrono::seconds dura( 5);
    std::this_thread::sleep_for( dura );
    if (newfile.is_open()){
        string tp;
        while(getline(newfile, tp)){
            // cout << tp << "\n";
            int k = tp.length();
            for(int i=0;i < tp.size();i++)
            {
                if(tp[i]==input)
                {
                    k=i;
                    break;
                }
            }
            for(int i=k+1;i<tp.size();i++)
            {
                v[tp[i]-'a']++;
            }
        }
        newfile.close();
    }

    vector<pair<int,char>>ans;
    for(int i=0;i<26;i++)
    {
    	ans.push_back({v[i],i+'a'});
    }
    sort(ans.begin(),ans.end(), greater<pair<int,char>>());
    cout<<"\n";
    cout<<"\n";
    cout<<"\n";
    cout<<"These are the top K elements we have : \n\n\n";
    cout<<"\t\t-------\n";
    for(int i=0;i<min(inpk,(int)ans.size());i++)
    {
        cout<<"\t\t|  "<<ans[i].second<<"  |\n";
        cout<<"\t\t-------\n";
    }
    cout<<"\n\n";
    return 0;
}