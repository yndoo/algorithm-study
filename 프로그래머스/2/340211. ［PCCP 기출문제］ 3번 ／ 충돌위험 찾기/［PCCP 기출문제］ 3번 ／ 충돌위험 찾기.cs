using System;
using System.Collections.Generic;

public struct Node
{
    public int X; // 행
    public int Y;
    public Node(int x, int y)
    {
        X = x;
        Y = y;
    }
}

public class Robot
{
    public int RobotNum = 0; // 몇번째로봇
    public Node Cur;
    public Node Goal; // 목표지점
    public int CurRouteIdx = 1; // 현재 Idx+1번째 경로 가는 중.
    
    public Robot(Node start, Node goal)
    {
        Cur.X = start.X;
        Cur.Y = start.Y;
        Goal.X = goal.X;
        Goal.Y = goal.Y;
    }
    
    public void Move()
    {
        if(Cur.X == Goal.X)
        {
            Cur.Y = Cur.Y > Goal.Y ? Cur.Y - 1 : Cur.Y + 1; // 같은 경우는 들어왔으면안됨
        }
        else
        {
            Cur.X = Cur.X > Goal.X ? Cur.X - 1 : Cur.X + 1;
        }
    }
    
    public bool IsGoal()
    {
        return Cur.X==Goal.X && Cur.Y==Goal.Y;
    }
}

public class Solution {
    public int solution(int[,] points, int[,] routes) {
        int answer = 0;
        int lastIdx = routes.GetLength(1) - 1;
        List<Robot> robots = new List<Robot>();
        HashSet<Robot> trashcan = new HashSet<Robot>();
        Dictionary<(int, int), int> CurRobot = new Dictionary<(int, int), int>();
        
        for(int i = 0; i < routes.GetLength(0); i++) // 로봇 객체 생성
        {
            int startIdx = routes[i,0] - 1;
            int next = routes[i,1] - 1;
            Robot rb = new Robot(
                            new Node(points[startIdx, 0], points[startIdx, 1]),
                            new Node(points[next, 0], points[next, 1])
                        );
            rb.RobotNum = i;
            robots.Add(rb);
            
            if(CurRobot.ContainsKey((rb.Cur.X, rb.Cur.Y)))
            {
                CurRobot[(rb.Cur.X, rb.Cur.Y)] += 1;
            }
            else
            {
                CurRobot[(rb.Cur.X, rb.Cur.Y)] = 1;
            }
        }
        // 시작 충돌 지점 계산 필요
        foreach(int val in CurRobot.Values)
        {
            if(val >= 2)
                answer += 1;
        }
        CurRobot.Clear();
        
        while(robots.Count > 0)
        {
            foreach(Robot rb in robots)
            {
                if(rb.IsGoal()) // 목적지 도착했으면
                {
                    if(rb.CurRouteIdx == lastIdx)
                    {
                        trashcan.Add(rb); // 제거
                        continue;
                    }
                    else
                    {
                        rb.CurRouteIdx += 1; //다음 목적지 타겟
                        rb.Goal.X = points[routes[rb.RobotNum,rb.CurRouteIdx] -1, 0];
                        rb.Goal.Y = points[routes[rb.RobotNum,rb.CurRouteIdx] - 1, 1];
                    }
                }
                // 목적지로 가는 중
                rb.Move();
                if(CurRobot.ContainsKey((rb.Cur.X, rb.Cur.Y)))
                {
                    CurRobot[(rb.Cur.X, rb.Cur.Y)] += 1;
                    //Console.WriteLine($"rb.Cur.X:{rb.Cur.X}, rb.Cur.Y:{rb.Cur.Y}");
                }
                else
                {
                    CurRobot[(rb.Cur.X, rb.Cur.Y)] = 1;
                }
            }
            // 충돌 지점 계산 필요
            foreach(int val in CurRobot.Values)
            {
                if(val >= 2)
                    answer += 1;
            }
            CurRobot.Clear();
            // 탈출로봇 제거
            foreach(Robot rb in trashcan)
            {
                robots.Remove(rb);
            }
            trashcan.Clear();
        }
        return answer;
    }
}