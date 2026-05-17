#include <list>
#include <iostream>
#include <string>

using namespace std;

#include "olcConsoleGameEngine.h"

class OneLoneCoder_Matrix : public olcConsoleGameEngine {
public:
    OneLoneCoder_Matrix() {

    }
private:
    struct sStreamer {
        int nColumn = 0;
        float fPosition = 0;
        float fSpeed = 0;
        wstring sText;

    };
    
    list<sStreamer> listStreamers;

    int nMaxStreamers = 300;
    wchar_t Randomcharacter() {
        return (wchar_t)(rand() % 0x1EF + 0x00C0);
        return (wchar_t)(rand() % 93 + 33);  // Random ASCII
    }

    void PrepareStreamer(sStreamer *s) 
    {
        s->nColumn = rand() % ScreenWidth();
        s->fPosition = 0;
        s->fSpeed = rand() % 40 + 5;
        s->sText.clear();

        int nStreamerLength = rand() % 80 + 10;
        for (int i = 0; i < nStreamerLength; i++) {
            s->sText.append(1, Randomcharacter());
        }

        // s->sText = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
protected:
    // called by oConsoleGameEngine 
    virtual bool OnUserCreate() {
        for (int n = 0; n < nMaxStreamers; n++) {
            sStreamer s;
            PrepareStreamer(&s);
            listStreamers.push_back(s);
        }
        return true;
    }   
    // called by olcConsoleGameEngine

    virtual bool OnUserUpdate(float fElapsedTime)
{
    Fill(0, 0,
         ScreenWidth(),
         ScreenHeight(),
         PIXEL_SOLID,
         FG_BLACK);

    for (auto& s : listStreamers)
    {
        s.fPosition += fElapsedTime * s.fSpeed;

        for (int i = 0; i < s.sText.size(); i++)
        {
            short col = FG_GREEN;

            if (i == 0)
                col = FG_WHITE;
            else if (i <= 3)
                col = FG_CYAN;

            int nCharIndex =
                abs(i - (int)s.fPosition)
                % s.sText.size();

            Draw(
                s.nColumn,
                (int)s.fPosition - i,
                s.sText[nCharIndex],
                col
            );

            if (rand() % 1000 < 5)
            {
                s.sText[i] = Randomcharacter();
            }
        }

        if (s.fPosition - s.sText.size()
            >= ScreenHeight())
        {
            PrepareStreamer(&s);
        }
    }

    return true;
}

};

int main() {

    OneLoneCoder_Matrix game;
    game.ConstructConsole(128, 80, 12, 12);
    game.Start();
    return 0;
}