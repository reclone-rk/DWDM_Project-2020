#include<bits/stdc++.h>
using namespace std;

int main(){
    fstream newfile;
    newfile.open("db.txt",ios::in);
    if (newfile.is_open()){
        string tp;
        while(getline(newfile, tp)){
            cout << tp << "\n";
        }
        newfile.close();
    }
    return 0;
}