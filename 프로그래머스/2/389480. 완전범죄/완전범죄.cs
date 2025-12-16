using System;
using System.Collections.Generic;

public struct Data
{
    public int Index;
    public int CurA;
    public int CurB;
    public Data(int idx, int a, int b)
    {
        Index = idx;
        CurA = a;
        CurB = b;
    }
}
public class Solution {
    public HashSet<Data> Visited = new HashSet<Data>();
    public int N;
    public int M;
    public int Answer = 121;
    private int _infoLen = 0;
    
    public int solution(int[,] info, int n, int m) {
        
        N = n;
        M = m;
        _infoLen = info.GetLength(0);
        Finding(0,0,0,info);
        if(Answer == 121) Answer = -1;
        return Answer;
    }
    
    private void Finding(int i, int curA, int curB, int[,] info)
    {
        if(i == _infoLen)
        {
            Answer = Math.Min(Answer, curA);
            return;
        }
        if(info[i,0] + curA < N)
        {
            // A가 먹기
            Data visit = new Data(i, info[i,0] + curA, curB);
            if(Visited.Contains(visit) == false)
            {
                Visited.Add(visit);
                Finding(i+1, visit.CurA, curB, info);
            }
        }
        
        if(info[i,1] + curB < M)
        {
            // B가 먹기
            Data visit = new Data(i, curA, info[i,1] + curB);
            if(Visited.Contains(visit) == false)
            {
                Visited.Add(visit);
                Finding(i+1, curA, visit.CurB, info);
            }
        }
    }
}