#include <bits/stdc++.h>

using namespace std;

pair<int, int> dir[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // 방향 벡터 (하, 좌, 상, 우)

struct Boom
{
    bool active;
    int timer;
};

class BoomBoard
{
public:
    BoomBoard(int R, int C) : r(R), c(C), grid(R, vector<Boom>(C, {false, 0})) {}

    void Make()
    {
        char ch;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> ch;
                grid[i][j] = {ch == 'O', ch == 'O' ? 1 : 0}; // 'O'면 active, 아니면 inactive, 타이머 초기화
            }
        }
    }

    void Print()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j].active)
                    cout << 'O';
                else
                    cout << '.';
            }
            cout << '\n';
        }
    }

    void Update(int time)
    {
        if (time % 2 == 0)
        {
            // 짝수 시간일 때 모든 빈 칸에 폭탄 설치
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (!grid[i][j].active)
                    {
                        grid[i][j].active = true;
                        grid[i][j].timer = time;
                    }
                }
            }
        }
        else
        {
            // 홀수 시간일 때 3초 전에 설치된 폭탄 폭발
            vector<pair<int, int>> toExplode;
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (grid[i][j].active && (time - grid[i][j].timer) >= 3)
                    {
                        toExplode.push_back({i, j});
                    }
                }
            }
            for (auto &cell : toExplode)
            {
                BoomActive(cell.first, cell.second);
            }
        }
    }

private:
    vector<vector<Boom>> grid;
    int r;
    int c;

    void BoomActive(int i, int j)
    {
        grid[i][j].active = false;
        grid[i][j].timer = 0;

        for (int k = 0; k < 4; k++)
        {
            int ny = i + dir[k].second;
            int nx = j + dir[k].first;

            if (nx >= 0 && nx < c && ny >= 0 && ny < r)
            {
                grid[ny][nx].active = false;
                grid[ny][nx].timer = 0;
            }
        }
    }
};

int main()
{
    int r, c, n;

    cin >> r >> c >> n;
    BoomBoard boomBoard(r, c);
    boomBoard.Make();

    for (int time = 2; time <= n; time++)
    {
        boomBoard.Update(time);
    }
    
    boomBoard.Print();
}
