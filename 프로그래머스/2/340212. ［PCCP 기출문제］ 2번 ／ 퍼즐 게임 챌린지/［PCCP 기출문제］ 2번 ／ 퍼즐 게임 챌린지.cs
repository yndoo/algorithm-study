using System;

public class Solution {
    public long CalcMyTime(int mylevel, int[] diffs, int[] times, long limit) // mylevel에 따라 시간 계산
        {
            long myTime = 0;
            for(int i = 0; i < diffs.Length; i++)
            {
                if(diffs[i] <= mylevel)
                {
                    myTime += (long)times[i];
                }
                else
                {
                    myTime += (long)(diffs[i] - mylevel) * (long)(times[i] + times[i-1]) + (long)times[i];
                }
                if(myTime > limit) return -1;
            }
            
            if(myTime <= limit)
            {
                return myTime;
            }
            return -1;
        }
        
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = int.MaxValue;
        int maxDiff = 0;
        foreach(int diff in diffs)
        {
            maxDiff = Math.Max(maxDiff, diff);
        }
        
        int start = 1;
        int end = maxDiff;
        int mid = (start + end) / 2;
        while(start <= end)
        {
            long myTime = CalcMyTime(mid, diffs, times, limit);
            
            if(myTime < 0)
            {
                start = mid + 1;
            }
            else
            {
                answer = Math.Min(answer, mid);
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
        return answer;
    }
}