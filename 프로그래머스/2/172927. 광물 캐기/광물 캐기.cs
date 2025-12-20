using System;
using System.Linq;
using System.Collections.Generic;

public struct Mineral
{
    public int S;
    public int E;
    public int Sum;
    public Mineral(int s, int e, int sum)
    {
        S = s;
        E = e;
        Sum = sum;
    }
}
public class Solution {
    public int solution(int[] picks, string[] minerals) {
        int answer = 0;
        int mineralCnt = minerals.Length;
        int pickCount = 0;
        List<Mineral> energies = new List<Mineral>();
        foreach(int pick in picks)
            pickCount += pick;
        mineralCnt = Math.Min(mineralCnt, 5 * pickCount);
        for(int i = 0; i < mineralCnt; i+=5)
        {
            int end = i+5 < mineralCnt ? i+5 : mineralCnt;
            int sum = 0;
            for(int j = i; j < end; j++)
            {
                switch(minerals[j])
                {
                    case "diamond":
                        sum+=25;
                        break;
                    case "iron":
                        sum+=5;
                        break;  
                    case "stone":
                        sum+=1;
                        break;                          
                }
            }
            energies.Add(new Mineral(i, end, sum));
        }
        energies.Sort((a,b)=>b.Sum.CompareTo(a.Sum));
        foreach(Mineral min in energies)
        {            
            int myPick = -1;
            //다이아부터꺼내쓰기
            for(int pick = 0; pick < 3; pick++)
            {
                if(picks[pick] > 0)
                {
                    picks[pick] -= 1;
                    myPick = pick;
                    break;
                }
            }
            if(myPick == -1) break; // 곡괭이 부족함
            else if(myPick == 2) // 돌곡괭 다시계산할 필요 없음
            {
                answer += min.Sum;
                continue;
            }
            for(int i = min.S; i < min.E; i++)
            {
                //곡괭이에맞게다시계산
                if(myPick == 0) // 다이아곡괭이
                {
                    answer += 1;
                }
                else
                {
                    answer += minerals[i] == "diamond" ? 5 : 1;
                }
            }
        }
        return answer;
    }
}