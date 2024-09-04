#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> months;

void MonthSetting()
{
    months[1] = 31;
    months[2] = 29;
    months[3] = 31;
    months[4] = 30;
    months[5] = 31;
    months[6] = 30;
    months[7] = 31;
    months[8] = 31;
    months[9] = 30;
    months[10] = 31;
    months[11] = 30;
    months[12] = 31;
}

string CalcDay(int _daynum)
{
    switch(_daynum)
    {
        case 1:
            return "FRI";
        case 2:
            return "SAT";
        case 3:
            return "SUN";
        case 4:
            return "MON";
        case 5:
            return "TUE";
        case 6:
            return "WED";
        case 0:
            return "THU";
        default:
            break;
    }
    
    return "error";
}

string solution(int a, int b) {
    MonthSetting();

    int daynum = 0;
    for (int month = 1; month <= a; ++month)
    {
        if (a == month)
        {
            daynum += b;
            break;
        }
        else
        {
            daynum += months[month];
        }
    }
    return CalcDay(daynum % 7);
}
