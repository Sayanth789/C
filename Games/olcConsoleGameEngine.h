#pragma once

#include <ncursesw/ncurses.h>

#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <cstring>
#include <cmath>
#include <cwchar>

enum COLOUR
{
    FG_BLACK = 1,
    FG_RED,
    FG_GREEN,
    FG_YELLOW,
    FG_BLUE,
    FG_MAGENTA,
    FG_CYAN,
    FG_WHITE
};

enum PIXEL_TYPE
{
    PIXEL_SOLID = L'\u2588',
    PIXEL_THREEQUARTERS = L'\u2593',
    PIXEL_HALF = L'\u2592',
    PIXEL_QUARTER = L'\u2591',
};

class olcSprite
{
public:
    olcSprite() {}

    olcSprite(int w, int h)
    {
        Create(w, h);
    }

    int nWidth = 0;
    int nHeight = 0;

private:
    wchar_t* m_Glyphs = nullptr;
    short* m_Colours = nullptr;

public:
    void Create(int w, int h)
    {
        nWidth = w;
        nHeight = h;

        m_Glyphs = new wchar_t[w * h];
        m_Colours = new short[w * h];

        for (int i = 0; i < w * h; i++)
        {
            m_Glyphs[i] = L' ';
            m_Colours[i] = FG_WHITE;
        }
    }

    void SetGlyph(int x, int y, wchar_t c)
    {
        if (x >= 0 && x < nWidth &&
            y >= 0 && y < nHeight)
        {
            m_Glyphs[y * nWidth + x] = c;
        }
    }

    void SetColour(int x, int y, short c)
    {
        if (x >= 0 && x < nWidth &&
            y >= 0 && y < nHeight)
        {
            m_Colours[y * nWidth + x] = c;
        }
    }

    wchar_t GetGlyph(int x, int y)
    {
        if (x >= 0 && x < nWidth &&
            y >= 0 && y < nHeight)
        {
            return m_Glyphs[y * nWidth + x];
        }

        return L' ';
    }

    short GetColour(int x, int y)
    {
        if (x >= 0 && x < nWidth &&
            y >= 0 && y < nHeight)
        {
            return m_Colours[y * nWidth + x];
        }

        return FG_WHITE;
    }
};

class olcConsoleGameEngine
{
public:
    olcConsoleGameEngine()
    {
        m_nScreenWidth = 80;
        m_nScreenHeight = 30;

        std::memset(m_keys, 0, sizeof(m_keys));
    }

    virtual ~olcConsoleGameEngine()
    {
        endwin();
    }

public:
    struct sKeyState
    {
        bool bPressed;
        bool bReleased;
        bool bHeld;
    };

protected:
    int m_nScreenWidth;
    int m_nScreenHeight;

    struct Cell
    {
        wchar_t glyph;
        short colour;
    };

    std::vector<Cell> m_bufScreen;

    sKeyState m_keys[512];

public:
    int ScreenWidth()
    {
        return m_nScreenWidth;
    }

    int ScreenHeight()
    {
        return m_nScreenHeight;
    }

    bool ConstructConsole(int width, int height, int fontw, int fonth)
    {
        m_nScreenWidth = width;
        m_nScreenHeight = height;

        m_bufScreen.resize(width * height);

        setlocale(LC_ALL, "");

        initscr();

        noecho();
        cbreak();
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        curs_set(0);

        start_color();

        init_pair(FG_BLACK, COLOR_BLACK, COLOR_BLACK);
        init_pair(FG_RED, COLOR_RED, COLOR_BLACK);
        init_pair(FG_GREEN, COLOR_GREEN, COLOR_BLACK);
        init_pair(FG_YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(FG_BLUE, COLOR_BLUE, COLOR_BLACK);
        init_pair(FG_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(FG_CYAN, COLOR_CYAN, COLOR_BLACK);
        init_pair(FG_WHITE, COLOR_WHITE, COLOR_BLACK);

        return true;
    }

    virtual bool OnUserCreate() = 0;
    virtual bool OnUserUpdate(float fElapsedTime) = 0;

public:
    void Draw(int x, int y,
              wchar_t c = PIXEL_SOLID,
              short col = FG_WHITE)
    {
        if (x >= 0 && x < m_nScreenWidth &&
            y >= 0 && y < m_nScreenHeight)
        {
            m_bufScreen[y * m_nScreenWidth + x].glyph = c;
            m_bufScreen[y * m_nScreenWidth + x].colour = col;
        }
    }

    void Fill(int x1, int y1,
              int x2, int y2,
              wchar_t c = PIXEL_SOLID,
              short col = FG_WHITE)
    {
        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
            {
                Draw(x, y, c, col);
            }
        }
    }

    void DrawString(int x, int y,
                    const std::wstring& s,
                    short col = FG_WHITE)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            Draw(x + i, y, s[i], col);
        }
    }

    void DrawLine(int x1, int y1,
                  int x2, int y2,
                  wchar_t c = PIXEL_SOLID,
                  short col = FG_WHITE)
    {
        int dx = abs(x2 - x1);
        int dy = -abs(y2 - y1);

        int sx = x1 < x2 ? 1 : -1;
        int sy = y1 < y2 ? 1 : -1;

        int err = dx + dy;

        while (true)
        {
            Draw(x1, y1, c, col);

            if (x1 == x2 && y1 == y2)
                break;

            int e2 = 2 * err;

            if (e2 >= dy)
            {
                err += dy;
                x1 += sx;
            }

            if (e2 <= dx)
            {
                err += dx;
                y1 += sy;
            }
        }
    }

    void DrawCircle(int xc, int yc,
                    int r,
                    wchar_t c = PIXEL_SOLID,
                    short col = FG_WHITE)
    {
        int x = 0;
        int y = r;
        int d = 3 - 2 * r;

        while (y >= x)
        {
            Draw(xc - x, yc - y, c, col);
            Draw(xc - y, yc - x, c, col);
            Draw(xc + y, yc - x, c, col);
            Draw(xc + x, yc - y, c, col);

            Draw(xc - x, yc + y, c, col);
            Draw(xc - y, yc + x, c, col);
            Draw(xc + y, yc + x, c, col);
            Draw(xc + x, yc + y, c, col);

            x++;

            if (d > 0)
            {
                y--;
                d += 4 * (x - y) + 10;
            }
            else
            {
                d += 4 * x + 6;
            }
        }
    }

    void Clear()
    {
        for (auto& c : m_bufScreen)
        {
            c.glyph = L' ';
            c.colour = FG_WHITE;
        }
    }

    void Present()
    {
        for (int y = 0; y < m_nScreenHeight; y++)
        {
            for (int x = 0; x < m_nScreenWidth; x++)
            {
                auto& p = m_bufScreen[y * m_nScreenWidth + x];

                attron(COLOR_PAIR(p.colour));

                mvaddnwstr(y, x, &p.glyph, 1);

                attroff(COLOR_PAIR(p.colour));
            }
        }

        refresh();
    }

    void Start()
    {
        if (!OnUserCreate())
            return;

        auto tp1 = std::chrono::high_resolution_clock::now();
        auto tp2 = tp1;

        bool bRunning = true;

        while (bRunning)
        {
            tp2 = std::chrono::high_resolution_clock::now();

            std::chrono::duration<float> elapsed =
                tp2 - tp1;

            tp1 = tp2;

            float fElapsedTime = elapsed.count();

            Clear();

            int key = getch();

            if (key != ERR)
            {
                m_keys[key].bPressed = true;
                m_keys[key].bHeld = true;
            }

            bRunning = OnUserUpdate(fElapsedTime);

            Present();

            std::this_thread::sleep_for(
                std::chrono::milliseconds(16));
        }
    }

    sKeyState GetKey(int k)
    {
        return m_keys[k];
    }
};