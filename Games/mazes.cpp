#include <iostream>
#include <stack>
#include <vector>
#include <thread>
#include <chrono>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "olcConsoleGameEngine.h"

class OneLoneCoder_Maze : public olcConsoleGameEngine
{
public:
    OneLoneCoder_Maze()
    {
        // m_sAppName = L"MAZE";
    }

private:
    int m_nMazeWidth;
    int m_nMazeHeight;

    int* m_maze;

    enum
    {
        CELL_PATH_N = 0x01,
        CELL_PATH_E = 0x02,
        CELL_PATH_S = 0x04,
        CELL_PATH_W = 0x08,
        CELL_VISITED = 0x10
    };

    int m_nVisitedCells;

    stack<pair<int, int>> m_stack;

    int m_nPathWidth;

protected:
    virtual bool OnUserCreate()
    {
        m_nMazeWidth = 40;
        m_nMazeHeight = 25;

        m_maze = new int[m_nMazeWidth * m_nMazeHeight];

        memset(m_maze, 0,
               m_nMazeWidth * m_nMazeHeight * sizeof(int));

        m_nPathWidth = 3;

        // Starting cell

        int x = rand() % m_nMazeWidth;
        int y = rand() % m_nMazeHeight;

        m_stack.push(make_pair(x, y));

        m_maze[y * m_nMazeWidth + x] = CELL_VISITED;

        m_nVisitedCells = 1;

        return true;
    }

    virtual bool OnUserUpdate(float fElapsedTime)
    {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(10));

        auto offset = [&](int x, int y)
        {
            return (m_stack.top().second + y)
                * m_nMazeWidth
                + (m_stack.top().first + x);
        };

        // Maze generation

        if (m_nVisitedCells <
            m_nMazeWidth * m_nMazeHeight)
        {
            vector<int> neighbours;

            // North

            if (m_stack.top().second > 0 &&
                (m_maze[offset(0, -1)] &
                 CELL_VISITED) == 0)
            {
                neighbours.push_back(0);
            }

            // East

            if (m_stack.top().first <
                m_nMazeWidth - 1 &&
                (m_maze[offset(1, 0)] &
                 CELL_VISITED) == 0)
            {
                neighbours.push_back(1);
            }

            // South

            if (m_stack.top().second <
                m_nMazeHeight - 1 &&
                (m_maze[offset(0, 1)] &
                 CELL_VISITED) == 0)
            {
                neighbours.push_back(2);
            }

            // West

            if (m_stack.top().first > 0 &&
                (m_maze[offset(-1, 0)] &
                 CELL_VISITED) == 0)
            {
                neighbours.push_back(3);
            }

            // Choose neighbour

            if (!neighbours.empty())
            {
                int next_cell_dir =
                    neighbours[rand() % neighbours.size()];

                switch (next_cell_dir)
                {
                case 0: // North

                    m_maze[offset(0, -1)] |=
                        CELL_VISITED | CELL_PATH_S;

                    m_maze[offset(0, 0)] |=
                        CELL_PATH_N;

                    m_stack.push(make_pair(
                        m_stack.top().first,
                        m_stack.top().second - 1));

                    break;

                case 1: // East

                    m_maze[offset(1, 0)] |=
                        CELL_VISITED | CELL_PATH_W;

                    m_maze[offset(0, 0)] |=
                        CELL_PATH_E;

                    m_stack.push(make_pair(
                        m_stack.top().first + 1,
                        m_stack.top().second));

                    break;

                case 2: // South

                    m_maze[offset(0, 1)] |=
                        CELL_VISITED | CELL_PATH_N;

                    m_maze[offset(0, 0)] |=
                        CELL_PATH_S;

                    m_stack.push(make_pair(
                        m_stack.top().first,
                        m_stack.top().second + 1));

                    break;

                case 3: // West

                    m_maze[offset(-1, 0)] |=
                        CELL_VISITED | CELL_PATH_E;

                    m_maze[offset(0, 0)] |=
                        CELL_PATH_W;

                    m_stack.push(make_pair(
                        m_stack.top().first - 1,
                        m_stack.top().second));

                    break;
                }

                m_nVisitedCells++;
            }
            else
            {
                m_stack.pop();
            }
        }

        // Drawing

        Fill(0, 0,
             ScreenWidth(),
             ScreenHeight(),
             L' ');

        for (int x = 0; x < m_nMazeWidth; x++)
        {
            for (int y = 0; y < m_nMazeHeight; y++)
            {
                // Draw cells

                for (int py = 0;
                     py < m_nPathWidth;
                     py++)
                {
                    for (int px = 0;
                         px < m_nPathWidth;
                         px++)
                    {
                        if (m_maze[
                            y * m_nMazeWidth + x]
                            & CELL_VISITED)
                        {
                            Draw(
                                x * (m_nPathWidth + 1) + px,
                                y * (m_nPathWidth + 1) + py,
                                PIXEL_SOLID,
                                FG_WHITE);
                        }
                        else
                        {
                            Draw(
                                x * (m_nPathWidth + 1) + px,
                                y * (m_nPathWidth + 1) + py,
                                PIXEL_SOLID,
                                FG_BLUE);
                        }
                    }
                }

                // Draw passages

                for (int p = 0;
                     p < m_nPathWidth;
                     p++)
                {
                    if (m_maze[
                        y * m_nMazeWidth + x]
                        & CELL_PATH_S)
                    {
                        Draw(
                            x * (m_nPathWidth + 1) + p,
                            y * (m_nPathWidth + 1)
                                + m_nPathWidth,
                            PIXEL_SOLID,
                            FG_WHITE);
                    }

                    if (m_maze[
                        y * m_nMazeWidth + x]
                        & CELL_PATH_E)
                    {
                        Draw(
                            x * (m_nPathWidth + 1)
                                + m_nPathWidth,
                            y * (m_nPathWidth + 1) + p,
                            PIXEL_SOLID,
                            FG_WHITE);
                    }
                }
            }
        }

        // Draw current position

        if (!m_stack.empty())
        {
            for (int py = 0;
                 py < m_nPathWidth;
                 py++)
            {
                for (int px = 0;
                     px < m_nPathWidth;
                     px++)
                {
                    Draw(
                        m_stack.top().first
                            * (m_nPathWidth + 1)
                            + px,

                        m_stack.top().second
                            * (m_nPathWidth + 1)
                            + py,

                        PIXEL_SOLID,
                        FG_GREEN);
                }
            }
        }

        return true;
    }
};

int main()
{
    srand(time(nullptr));

    OneLoneCoder_Maze game;

    game.ConstructConsole(120, 50, 8, 8);

    game.Start();

    return 0;
}