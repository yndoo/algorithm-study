using System;
using System.Linq;

public class Solution {
    public string solution(string video_len, string pos, string op_start, string op_end, string[] commands) {
        string answer = "";
        int[] videoMS = video_len.Split(':').Select(int.Parse).ToArray();
        int videoLenSec = videoMS[0] * 60 + videoMS[1];
        int[] posMS = pos.Split(':').Select(int.Parse).ToArray();
        int posSec = posMS[0] * 60 + posMS[1];
        int[] opStartMS = op_start.Split(':').Select(int.Parse).ToArray();
        int opStartSec = opStartMS[0] * 60 + opStartMS[1];
        int[] opEndMS = op_end.Split(':').Select(int.Parse).ToArray();
        int opEndSec = opEndMS[0] * 60 + opEndMS[1];
        
        if(posSec >= opStartSec && posSec <= opEndSec)
        {
            posSec = opEndSec;
        }
        foreach(string command in commands)
        {
            if(command == "next")
            {
                posSec = Math.Min(posSec + 10, videoLenSec);
            }
            else
            {
                posSec = Math.Max(posSec - 10, 0);
            }
            if(posSec >= opStartSec && posSec <= opEndSec)
            {
                posSec = opEndSec;
            }
        }
        answer = $"{(posSec / 60).ToString("00")}:{(posSec%60).ToString("00")}";
        return answer;
    }
}