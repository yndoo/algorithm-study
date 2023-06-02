#include <string>
#include <vector>

using namespace std;

int solution(int numm) {
    int i = 0;
    long num = 0;
    num = (long)numm;
    while (num!=1){
        i++;
        if (num%2==0){
            num = num/2;
        }
        else {
            num = num*3+1;
        }
        if (i==500) {return -1;}
    }
    return i;
}