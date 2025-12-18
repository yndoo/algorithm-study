using System;

using System;

public class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        
        // x를 1부터 r2까지 순회 (y축 위 점들은 제외됨)
        for (int x = 1; x <= r2; x++) {
            long r2Pow = (long)r2 * r2;
            long r1Pow = (long)r1 * r1;
            long xPow = (long)x * x;

            // 큰 원 안에서의 최대 y값 (내림)
            long maxY = (long)Math.Floor(Math.Sqrt(r2Pow - xPow));
            
            // 작은 원 밖에서의 최소 y값 (올림)
            // x가 r1보다 커지면 r1Pow - xPow가 음수가 되므로 0으로 처리
            long minY = 0;
            if (r1Pow > xPow) {
                minY = (long)Math.Ceiling(Math.Sqrt(r1Pow - xPow));
            }
            
            answer += (maxY - minY + 1);
        }
        
        // x=1부터 시작했으므로 y축 위의 점들이 빠져있습니다. 
        // 4사분면을 곱하면 축 위의 점들이 중복 없이 포함됩니다.
        return answer * 4;
    }
}