using System;
using System.Linq;
using System.Collections.Generic;

public struct Node
{
    public int X;
    public int Y;
    public Node(int x, int y)
    {
        X = x;
        Y = y;
    }
}
public class Solution {
    bool[,] visited;
    int row;
    int col;
    int[] dx = new int[4] {1, -1, 0, 0};
    int[] dy = new int[4] {0, 0, 1, -1};
    
    public int[] solution(string[] maps) {
        List<int> answer = new List<int>();
        row = maps.Length;
        col = maps[0].Length;
        visited = new bool[row,col];
        Queue<Node> q = new Queue<Node>();
        
        int food = 0;
        for(int i = 0; i < row; i ++)
        {
            for(int j = 0; j < col; j++)
            {
                if(maps[i][j] == 'X' || visited[i,j] == true) continue;
                food = 0;
                q.Enqueue(new Node(i,j));
                while(q.Count > 0)
                {
                    Node cur = q.Dequeue();
                    visited[cur.X, cur.Y] = true;
                    food += maps[cur.X][cur.Y] - '0';
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if(nx < 0 || ny < 0 || nx >= row || ny >= col || visited[nx,ny] == true) continue;
                        if(maps[nx][ny] != 'X')
                        {
                            visited[nx,ny] = true;
                            q.Enqueue(new Node(nx, ny));
                        }
                    }
                }
                answer.Add(food);
            }
        }
        if(answer.Count == 0) answer.Add(-1);
        answer.Sort();
        return answer.ToArray();
    }
}