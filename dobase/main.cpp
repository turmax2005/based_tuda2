#include <bits/stdc++.h>

using namespace std;
#define int long long
const int cnt=70;
mt19937 rnd;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    rnd.seed(time(NULL)+getpid());
    setlocale(LC_ALL,"Russian");
    string s;
    while(cin>>s)
    {
        ifstream fin("length.txt");
        if(!fin) cout<<" ban "<<endl;
        int len;
        fin>>len;
        //cout<<len<<endl;
        fin.close();
        if(s=="exit") {return 0;}
        if(s=="add")
        {
            ifstream file("problem.txt");
            string s;
            vector <string> h;
            while(file>>s)
            {
                h.push_back(s);
            }
            //cout<<len<<" len "<<endl;
            string o=to_string(len);
            o+=".txt";
            //cout<<o<<" o "<<endl;
            ofstream fileout(o);
            int sz=0;
            for(auto h1:h) {sz+=h1.size();if(sz>cnt) {sz=0;cout<<h1<<endl;} else {cout<<h1<<' ';}}
            cout<<endl;
            sz=0;
            for(auto h1:h) {sz+=h1.size();if(sz>cnt) {sz=0;fileout<<h1<<endl;} else {fileout<<h1<<' ';}}
            fileout.close();
            file.close();
            ofstream fileoutlen("length.txt");
            ++len;
            fileoutlen<<len;
            fileoutlen.close();
            continue;
        }
        else if(s=="pickrand")
        {
            int f=rnd()%len;
            string o=to_string(f);o+=".txt";
            ifstream file(o);
            vector <string> h;
            while(file>>s)
            {
                h.push_back(s);
            }
            int sz=0;
            for(auto h1:h) {sz+=h1.size();if(sz>cnt) {sz=0;cout<<h1<<endl;} else {cout<<h1<<' ';}}
            cout<<endl;
            continue;
        }
        else if(s=="popback")
        {
             if(!len)
             {
                 cout<<" len=0 zachem??? "<<endl;
                 continue;
             }
             ofstream fileoutlen("length.txt");
             --len;
             fileoutlen<<len;
             fileoutlen.close();
             continue;
        }
    }
    return 0;
}
