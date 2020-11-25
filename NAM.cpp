#include<bits/stdc++.h>
using namespace std;

int main(){
    
    clock_t start, end; 
    start = clock(); 
    cout<<"\n\nEnter K value and Input Item : \n\n"<<endl;
    int inpk;
    cin>>inpk;
    char input;
    cin>>input;
    vector<int>v(26,0);
    fstream newfile;
    int temp = 0;
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
                for(int j=0; j<tp.size(); j++){
                    if(tp[i] == tp[j]){
                        temp += tp[i] * tp[j];
                    }
                }
            }
            for(int i=k+1;i<tp.size();i++)
            {
                v[tp[i]-'a']++;
            }
        }
        newfile.close();
    }
    int b=1;
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            b=0;
        }
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
    end = clock(); 
    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    // cout << "\e[1mTime taken by program is : \e[0m" <<fixed  << time_taken << setprecision(5); 
    // cout << " sec " << endl; 
    // cout << "Time taken by program is : " << fixed  << time_taken << setprecision(5); 
    // cout << " sec " << endl; 
    return 0;
}
