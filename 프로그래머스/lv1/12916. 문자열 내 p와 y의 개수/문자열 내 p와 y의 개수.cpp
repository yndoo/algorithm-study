#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int i = 0, j = 0;
    int cntp = 0,cntj = 0;
    while (s.find("p",i)!=string::npos){
        i = s.find("p",i)+1;
        cntp++;
        }
    while (s.find("y",j)!=string::npos){
        j = s.find("y",j)+1;
        cntj++;
        }
    i=0;
    j=0;
    while (s.find("P",i)!=string::npos){
        i = s.find("P",i)+1;
        cntp++;
        }
    while (s.find("Y",j)!=string::npos){
        j = s.find("Y",j)+1;
        cntj++;
        }

    if (cntp == cntj) {return true;}
    else {return false;}
}
/*
bool solution(string s)
{
    int p=0, y=0;
    for (int i=0; i<s.length(); i++){
        if (s[i] == 'p' || s[i] == 'P'){
            p++;
        }
        else if (s[i] == 'y' || s[i] == 'Y'){
            y++;
        }
    }
    return p==y;
}
*/
