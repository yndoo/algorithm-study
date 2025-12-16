using System;
using System.Collections.Generic;

public struct Try
{
    public int Ans; // 일치하는 개수
    public HashSet<int> Set;
}

public class Solution {
    public List<Try> Qs = new List<Try>();
    public int N = 0;
    private int result = 0;
    
    public int solution(int n, int[,] q, int[] ans) {
        N = n;
        for(int i = 0; i < q.GetLength(0); i++)
        {
            Try data = new Try();
            data.Set = new HashSet<int>();
            data.Ans = ans[i];
            for(int j = 0; j < 5; j++)
            {
                data.Set.Add(q[i,j]);
            }
            Qs.Add(data);
        }
        
        NewTry(0, new int[5]);
        return result;
    }
    
    private void NewTry(int idx, int[] nums)
    {
        if(idx == 5)
        {
            // Qs 돌면서 정답인지 확인, answer ++;
            foreach(Try data in Qs)
            {
                int curAns = 0;
                foreach(int num in nums)
                {
                    if(data.Set.Contains(num) == true)
                    {
                        curAns+=1;
                    }
                }
                if(data.Ans != curAns) return;
            }
            result += 1; // 모두 만족해야 여기 들어오는데....
            return;
        }
        int next = idx == 0 ? 1 : nums[idx - 1] + 1; // 처음이면 1부터, 아니면 이전 숫자 + 1부터
        for(int i = next; i <= N; i++)
        {
            nums[idx] = i;
            NewTry(idx + 1, nums);
            nums[idx] = 0;
        }
        
    }
}