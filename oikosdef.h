#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <unistd.h>
#include <mmsystem.h>

using namespace std;

#define PLAY_AGAIN_BUTTON 100
#define ID_TRACKBAR 210
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#include <wingdi.h>
#include <commctrl.h>
#define GetCurrentDir getcwd
#endif
const char g_szClassName[] = "Oikos";
class Oikos {
 public:
    BOOL dontplay = TRUE;
    HANDLE threa, thread, thrad;
    char filename[FILENAME_MAX];
    char buff[FILENAME_MAX];    
    string choice;
    string choicepre = "sq";
    int sleeptime = 8000;
    int points=0;
    int level = 1;
    int blocks=0;
    int lines=0;
    int linenext = 10;
    int b[740][720];
    int showNextBg = 1;
    HWND hwnd;
    HWND hwnd_title;
    HWND hwnd_new_game;
    HWND hwnd_stage;
    HWND hwnd_next;
    HWND hwnd_lines;
    HWND hwnd_points;
    HWND hwnd_blocks;
    HWND hwnd_level;
    HINSTANCE hInst;
    BITMAP bitmap;
    WNDCLASSEX wc;
    HDC hdcMem;
    HGDIOBJ oldBitmap;
    HBITMAP hBitmap, hb1,hb2,hb3,hb4,hb5;
    HFONT font;
    MSG Msg;
    BOOLEAN fist = TRUE;
    HDC hdc;
    HDC hdc2;
    PAINTSTRUCT ps;
    BITMAP bitmaps;
    HDC hdcMems;
    HGDIOBJ oldBitmaps;
    HBITMAP hbitmap, hhbbs;
    void prep();
    void erasePreview();
    void showNextPiece();
    void clearLine();
    class Pyramid {
     public:
      Oikos *mm;
      Pyramid(Oikos *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      void rotate();
      void goLeft();
      void goRight();
      BOOL goDown();
    };
    Pyramid* ht = new Pyramid(this);
    class Rect {
     public:
        Oikos *mm;
        Rect(Oikos *m) { mm = m; }
        int x0;
        int y0;
        int x1;
        int y1;
        int x2;
        int y2;
        int x3;
        int y3;
        void rotate();
        void goLeft();
        void goRight();
        BOOL goDown();
    };
    Rect* sq = new Rect(this);
    class Beam {
     public:
        Oikos *mm;
        Beam(Oikos *m) { mm = m; }
        int x0;
        int y0;
        int x1;
        int y1;
        int x2;
        int y2;
        int x3;
        int y3;
        int dir;
        void rotate();
        void goLeft();
        void goRight();
        BOOL goDown();
    };
    Beam* lne = new Beam(this);
    class Lsho {
     public:
        Oikos *mm;
        Lsho(Oikos *m) { mm = m; }
        int x0;
        int y0;
        int x1;
        int y1;
        int x2;
        int y2;
        int x3;
        int y3;
        int dir;
        void rotate();
        void goLeft();
        void goRight();
        BOOL goDown();
    };
    Lsho* lsh = new Lsho(this);
    class Rsho {
     public:
      Oikos *mm;
      Rsho(Oikos *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      void rotate();
      void goLeft();
      void goRight();
      BOOL goDown();
    };
    Rsho* rsh = new Rsho(this);
    class Larm {
     public:
      Oikos *mm;
      Larm(Oikos *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      void rotate();
      void goLeft();
      void goRight();
      BOOL goDown();
    };
    Larm* larm = new Larm(this);
    class Rarm {
     public:
      Oikos *mm;
      Rarm(Oikos *m) { mm = m; }
      int x0;
      int y0;
      int x1;
      int y1;
      int x2;
      int y2;
      int x3;
      int y3;
      int dir;
      void rotate();
      void goLeft();
      void goRight();
      BOOL goDown();
    };    
    Rarm* rarm = new Rarm(this);
};