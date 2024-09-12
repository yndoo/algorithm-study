#include <string>
using namespace std;

bool visited[11][11][4] = {false,}; // U,D,L,R

struct Index
{
    Index(int _X, int _Y)
    {
        X = _X;
        Y = _Y;
    }
    
    int X;
    int Y;
    
    void operator+= (Index _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
    }
};

int solution(string dirs) {
    int answer = 0;
    Index Cur = {5, 5};
    for(char dir : dirs)
    {
        Index Next = {0, 0};
        int dNum = -1, reverseDir = -1;
        switch(dir)
        {
            case 'U':
                dNum = 0;
                reverseDir = 1;
                Next = Index(-1, 0);
                break;
            case 'D':
                dNum = 1;
                reverseDir = 0;
                Next = Index(1, 0);
                break;
            case 'L':
                dNum = 2;
                reverseDir = 3;
                Next = Index(0, -1);
                break;
            case 'R':
                dNum = 3;
                reverseDir = 2;
                Next = Index(0, 1);
                break;
        }
        if(Cur.X + Next.X < 0 || Cur.Y + Next.Y < 0 || Cur.X + Next.X > 10 || Cur.Y + Next.Y > 10) continue;
        if(visited[Cur.X][Cur.Y][dNum] == false && visited[Cur.X + Next.X][Cur.Y + Next.Y][reverseDir] == false)
        {
            visited[Cur.X][Cur.Y][dNum] = true;
            visited[Cur.X + Next.X][Cur.Y + Next.Y][reverseDir] = true;
            ++answer;
        }
        Cur += Next;
    }
    
    return answer;
}