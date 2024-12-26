// https://www.acmicpc.net/problem/3197
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int R, C;
vector<string> lake;
queue<pair<int, int> > water, nextWater;
queue<pair<int, int> > swanQueue, nextSwanQueue;
pair<int, int> swans[2];
bool visited[1500][1500];

bool canMeet()
{

    while (!swanQueue.empty())
    {
        int x = swanQueue.front().first;
        int y = swanQueue.front().second;
        swanQueue.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny])
                continue;
            
            visited[nx][ny] = true;
            if(nx == swans[1].first && ny == swans[1].second){
                return true;
            }

            if (lake[nx][ny] == '.') {
                swanQueue.push(make_pair(nx,ny));
            } else {
                nextSwanQueue.push(make_pair(nx,ny));
            }
        }   
        
    }
    return false;
}

void meltIce()
{   
    while (!water.empty())
    {
        int x = water.front().first;
        int y = water.front().second;
        water.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C || lake[nx][ny] != 'X')
                continue;

            lake[nx][ny] = '.';
            nextWater.push(make_pair(nx,ny));
        }
    }
}

int main()
{
    cin >> R >> C;

    lake.resize(R);
    memset(visited, false, sizeof(visited));
    int swanCount = 0;
    for (int i = 0; i < R; i++)
    {
        cin >> lake[i];
        for (int j = 0; j < C; j++)
        {
            if (lake[i][j] == 'L')
            {
                lake[i][j] = '.';
                swans[swanCount++] = make_pair(i,j);
                water.push(make_pair(i,j));
            }
            else if (lake[i][j] == '.')
            {
                water.push(make_pair(i,j));
            }
        }
    }

    swanQueue.push(swans[0]);
    visited[swans[0].first][swans[0].second] = true;

    int days = 0;
    
    while(true){
        if(canMeet()){
            cout << days << endl;
            break;
        }
        meltIce();
        days++;
        water = nextWater;
        nextWater = queue<pair<int,int> >();

        swanQueue = nextSwanQueue;
        nextSwanQueue = queue<pair<int,int> >();
    }

    return 0;
}