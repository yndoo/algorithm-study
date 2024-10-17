#include <string>
#include <vector>
#include <map>
#include <list>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> parking; // 주차장
    map<string, int> history; // 주차장
     for(string rec : records)
     {
         int hour = stoi(rec.substr(0,2));
         int minute = stoi(rec.substr(3,2));
         string name = rec.substr(6,4);
         string type = rec.substr(11,rec.size() - 11);
         if(type == "IN")
         {
             parking[name] = 60 * hour + minute;
         }
         else // "OUT"
         {
             int time = (60 * hour + minute) - parking[name];
             if(history.find(name) != history.end())
             {
                 history[name] += time;
             }
             else 
             {
                 history[name] = time;
             }
             parking.erase(parking.find(name));
         }
     }
    // 안 나간 차 요금 계산
    for(auto car : parking)
    {
        int time = (60 * 23 + 59) - car.second;
        if(history.find(car.first) != history.end())
        {
            history[car.first] += time;
        }
        else
        {
            history[car.first] = time;
        }
    }
    // 요금 계산
    for(auto h : history)
    {
        if(h.second <= fees[0]) answer.push_back(fees[1]);
        else    // 기본 시간 초과한 경우
        {
            int over = h.second - fees[0]; // 초과한 시간
            if(over % fees[2] == 0) answer.push_back(fees[1] + fees[3] * (over / fees[2]));
            else answer.push_back(fees[1] + fees[3] * (over / fees[2] + 1));
        }
    }
    return answer;
}