#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <unistd.h>
#include <mmsystem.h>
#include "oikosdef.h"

using namespace std;

void Oikos::clearLine() {
    int count = 0;
    int clearBlocks[700];
    int cc = 0;
    BOOLEAN keepon = TRUE;

    do {

        for(int i=0; i<700; i++) {
            clearBlocks[i] = 0;
        }

        for(int j=0; j<=700 && keepon; j++) {

            int clearThisLine = 0;

            for(int i=0; i<740; i++) {
                if(1 == b[i][j]) {
                    clearThisLine++;
                }
            }

            if(clearThisLine == 10) {
                clearBlocks[count] = j;
                count++;
                lines++;
                points+=10;
                keepon = FALSE;
            }
        }

        if(count > 0) {

            int cnt;

            cnt = 0;

            for(;cnt < count; cnt++) {
                for(int j=0; j<700; j++) {
                    for(int i=0; i<740; i++) {
                        if(j == clearBlocks[cnt]) {
                            b[i][j] = 0;
                        }
                    }
                }
            }

            cnt = 0;

            for(;cnt < count; cnt++) {
                for(int j=650; j>=0; j-=20) {
                    for(int i=0; i<740; i++) {
                        if(b[i][j] == 1 && j < clearBlocks[cnt]) {
                            b[i][j] = 0;
                            b[i][j+20] = 1;
                        }
                    }
                }
            }
        }

        cc++;

    } while(cc < 35);
}
void Oikos::showNextPiece() {

    if(choicepre == "sq") {
        HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
        RECT rrect5 = {-90+100, 100, -90+100 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+120, 100, -90+120 + 20, 100 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+100, 120, -90+100 + 20, 120 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+120, 120, -90+120 + 20, 120 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "lne") {
        HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
        RECT rrect5 = {-90+100, 100, -90+100 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+100, 120, -90+100 + 20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+100, 140, -90+100 + 20, 140 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+100, 160, -90+100 + 20, 160 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "ht") {
        HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
        RECT rrect5 = {-90+120, 100, -90+120 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+100, 120, -90+100 + 20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+120, 120, -90+120 + 20, 120 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+140, 120, -90+140 + 20, 120 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "larm") {
        HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
        RECT rrect5 = {-90+120, 100, -90+120 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+120, 120, -90+120 + 20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+120, 140, -90+120 + 20, 140 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+100, 140, -90+100 + 20, 140 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "rarm") {
        HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
        RECT rrect5 = {-90+120-20, 100, -90+120 + 20-20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+120-20, 120, -90+120 + 20-20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+120-20, 140, -90+120 + 20-20, 140 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+140-20, 140, -90+140 + 20-20, 140 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "lsh") {
        HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
        RECT rrect5 = {-90+120, 100, -90+120 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+120, 120, -90+120 + 20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+100, 120, -90+100 + 20, 120 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+100, 140, -90+100 + 20, 140 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    } else if(choicepre == "rsh") {
        HBRUSH brush = CreateSolidBrush(RGB(80, 0, 0));
        RECT rrect5 = {-90+100, 100, -90+100 + 20, 100 + 20};
        FillRect(hdc2, &rrect5, brush);
        RECT rrect6 = {-90+100, 120, -90+100 + 20, 120 + 20};
        FillRect(hdc2, &rrect6, brush);
        RECT rrect7 = {-90+120, 120, -90+120 + 20, 120 + 20};
        FillRect(hdc2, &rrect7, brush);
        RECT rrect8 = {-90+120, 140, -90+120 + 20, 140 + 20};
        FillRect(hdc2, &rrect8, brush);
        DeleteObject(brush);
    }
}
void Oikos::erasePreview() {

    HBRUSH brush11 = CreateSolidBrush(RGB(255, 255, 0));
    RECT rrect11 = {0, 12, 143, 233};
    FillRect(hdc2, &rrect11, brush11);
    DeleteObject(brush11);

    HBRUSH brush = CreateSolidBrush(RGB(0, 210, 0));
    RECT rrect5 = {0, 20, 129, 220};
    FillRect(hdc2, &rrect5, brush);
    DeleteObject(brush);
}
void Oikos::Pyramid::rotate() {
  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);

  if(mm->choice == "ht") {

      int htx0, hty0, htx1, hty1, htx2, hty2, htx3, hty3, htdir;

      htdir = dir;
      htx0 = x0;
      hty0 = y0;
      htx1 = x1;
      hty1 = y1;
      htx2 = x2;
      hty2 = y2;
      htx3 = x3;
      hty3 = y3;

      if(dir == 0) {
          dir = 1;
          x0 += 20* 0;
          y0 += 20* 0;
          x1 += 20* 0;
          y1 -= 20* 2;
          x2 -= 20* 1;
          y2 -= 20* 1;
          x3 -= 20* 2;
          y3 -= 20* 0;
      }
      else if(dir == 1) {
          dir = 2;
          x0 -= 20* 0;
          y0 += 20* 0;
          x1 += 20* 2;
          y1 += 20* 0;
          x2 += 20* 1;
          y2 -= 20* 1;
          x3 -= 20* 0;
          y3 -= 20* 2;
      }
      else if(dir == 2) {
          dir = 3;
          x0 -= 20* 0;
          y0 -= 20* 0;
          x1 -= 20* 0;
          y1 += 20* 2;
          x2 += 20* 1;
          y2 += 20* 1;
          x3 += 20* 2;
          y3 += 20* 0;
      }
      else if(dir == 3) {
          dir = 0;
          x0 += 20* 0;
          y0 -= 20* 0;
          x1 -= 20* 2;
          y1 -= 20* 0;
          x2 -= 20* 1;
          y2 += 20* 1;
          x3 -= 20* 0;
          y3 += 20* 2;
      }

      if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
         x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
          dir = htdir;
          x0 = htx0;
          y0 = hty0;
          x1 = htx1;
          y1 = hty1;
          x2 = htx2;
          y2 = hty2;
          x3 = htx3;
          y3 = hty3;
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);
  }
}
void Oikos::Pyramid::goLeft() {

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);

  if(mm->choice == "ht" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      if(x0 > 220 &&
         x1 > 220 &&
         x2 > 220 &&
         x3 > 220) {
          if(mm->b[x0-20][y0] == 0 &&
             mm->b[x1-20][y1] == 0 &&
             mm->b[x2-20][y2] == 0 &&
             mm->b[x3-20][y3] == 0) {
              x0 -= 20;
              x1 -= 20;
              x2 -= 20;
              x3 -= 20;
          }
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);

      DeleteObject(brush);

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }
      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
  }
}
void Oikos::Pyramid::goRight() {

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);

  if(mm->choice == "ht" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      if(mm->b[x0+20][y0] == 0 &&
         mm->b[x1+20][y1] == 0 &&
         mm->b[x2+20][y2] == 0 &&
         mm->b[x3+20][y3] == 0 &&

         x0 < 400 &&
         x1 < 400 &&
         x2 < 400 &&
         x3 < 400
         ) {
          x0 += 20;
          x1 += 20;
          x2 += 20;
          x3 += 20;
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }
      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
  }
}
BOOL Oikos::Pyramid::goDown() {

  BOOL canGoDown = FALSE;

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "ht" && (y0 <= 630 && y1 <= 630 && y2 <= 630 && y3 <= 630)) {
      if(mm->b[x0][y0+20] == 0 &&
         mm->b[x1][y1+20] == 0 &&
         mm->b[x2][y2+20] == 0 &&
         mm->b[x3][y3+20] == 0) {
          y0 += 20;
          y1 += 20;
          y2 += 20;
          y3 += 20;
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          canGoDown = TRUE;
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      } else
          canGoDown = FALSE;

      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
  }

  return canGoDown;
}
void Oikos::Rect::rotate() {

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);
    DeleteObject(brush);

    if(mm->choice == "sq") {

        y0 += 0;
        y1 += 0;
        y2 += 0;
        y3 += 0;

        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

        RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
        FillRect(mm->hdc2, &rrect3, brush);

        RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
        FillRect(mm->hdc2, &rrect4, brush);

        RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
        FillRect(mm->hdc2, &rrect5, brush);

        RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
        FillRect(mm->hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
}
void Oikos::Rect::goLeft() {

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);

    if(mm->choice == "sq" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
        if(x0 > 220 &&
           x1 > 220 &&
           x2 > 220 &&
           x3 > 220) {
            if(mm->b[x0-20][y0] == 0 &&
               mm->b[x1-20][y1] == 0 &&
               mm->b[x2-20][y2] == 0 &&
               mm->b[x3-20][y3] == 0) {
                x0 -= 20;
                x1 -= 20;
                x2 -= 20;
                x3 -= 20;
            }
        }

        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
        RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
        FillRect(mm->hdc2, &rrect3, brush);

        RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
        FillRect(mm->hdc2, &rrect4, brush);

        RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
        FillRect(mm->hdc2, &rrect5, brush);

        RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
        FillRect(mm->hdc2, &rrect6, brush);

        DeleteObject(brush);
    }
}
void Oikos::Rect::goRight() {

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);

    if(mm->choice == "sq" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
        if(mm->b[x0+20][y0] == 0 &&
           mm->b[x1+20][y1] == 0 &&
           mm->b[x2+20][y2] == 0 &&
           mm->b[x3+20][y3] == 0 &&

           x0 < 400 &&
           x1 < 400 &&
           x2 < 400 &&
           x3 < 400
           ) {
            x0 += 20;
            x1 += 20;
            x2 += 20;
            x3 += 20;
        }

        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

        RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
        FillRect(mm->hdc2, &rrect3, brush);

        RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
        FillRect(mm->hdc2, &rrect4, brush);

        RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
        FillRect(mm->hdc2, &rrect5, brush);

        RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
        FillRect(mm->hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
}
BOOL Oikos::Rect::goDown() {

    BOOL canGoDown = FALSE;

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);
    DeleteObject(brush);

    if(mm->choice == "sq" && (y0 <= 630 && y1 <= 630 && y2 <= 630 && y3 <= 630)) {
        y0 += 20;
        y1 += 20;
        y2 += 20;
        y3 += 20;

        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

        RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
        FillRect(mm->hdc2, &rrect3, brush);

        RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
        FillRect(mm->hdc2, &rrect4, brush);

        RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
        FillRect(mm->hdc2, &rrect5, brush);

        RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
        FillRect(mm->hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
            mm->b[x0][y0] = 1;
            mm->b[x1][y1] = 1;
            mm->b[x2][y2] = 1;
            mm->b[x3][y3] = 1;
            mm->blocks++;
            mm->prep();
        } else {
        }

        BOOLEAN flag = FALSE;
        if(mm->b[x0][y0+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x1][y1+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x2][y2+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x3][y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            canGoDown = TRUE;
            mm->b[x0][y0] = 1;
            mm->b[x1][y1] = 1;
            mm->b[x2][y2] = 1;
            mm->b[x3][y3] = 1;
            mm->blocks++;
            mm->prep();
        } else
            canGoDown = FALSE;

        if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
    }
}
void Oikos::Beam::rotate() {

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);
    DeleteObject(brush);

    if(mm->choice == "lne") {

        int lnex0, lney0, lnex1, lney1, lnex2, lney2, lnex3, lney3, lnedir;

        lnedir = dir;
        lnex0 = x0;
        lney0 = y0;
        lnex1 = x1;
        lney1 = y1;
        lnex2 = x2;
        lney2 = y2;
        lnex3 = x3;
        lney3 = y3;

        if(dir == 0) {
            dir = 1;
            x0 += 20* 3;
            y0 += 20* 3;
            x1 += 20* 2;
            y1 += 20* 2;
            x2 += 20* 1;
            y2 += 20* 1;
            x3 += 20* 0;
            y3 += 20* 0;
        }
        else if(dir == 1) {
            dir = 2;
            x0 -= 20* 3;
            y0 += 20* 3;
            x1 -= 20* 2;
            y1 += 20* 2;
            x2 -= 20* 1;
            y2 += 20* 1;
            x3 -= 20* 0;
            y3 += 20* 0;
        }
        else if(dir == 2) {
            dir = 3;
            x0 -= 20* 3;
            y0 -= 20* 3;
            x1 -= 20* 2;
            y1 -= 20* 2;
            x2 -= 20* 1;
            y2 -= 20* 1;
            x3 -= 20* 0;
            y3 -= 20* 0;
        }
        else if(dir == 3) {
            dir = 0;
            x0 += 20* 3;
            y0 -= 20* 3;
            x1 += 20* 2;
            y1 -= 20* 2;
            x2 += 20* 1;
            y2 -= 20* 1;
            x3 += 20* 0;
            y3 -= 20* 0;
        }

        if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
           x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
            dir = lnedir;
            x0 = lnex0;
            y0 = lney0;
            x1 = lnex1;
            y1 = lney1;
            x2 = lnex2;
            y2 = lney2;
            x3 = lnex3;
            y3 = lney3;
        }

        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

        RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
        FillRect(mm->hdc2, &rrect3, brush);

        RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
        FillRect(mm->hdc2, &rrect4, brush);

        RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
        FillRect(mm->hdc2, &rrect5, brush);

        RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
        FillRect(mm->hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
}
void Oikos::Beam::goLeft() {

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);
    DeleteObject(brush);

    if(mm->choice == "lne" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
        if(x0 > 220 &&
           x1 > 220 &&
           x2 > 220 &&
           x3 > 220) {
            if(mm->b[x0-20][y0] == 0 &&
               mm->b[x1-20][y1] == 0 &&
               mm->b[x2-20][y2] == 0 &&
               mm->b[x3-20][y3] == 0) {
                x0 -= 20;
                x1 -= 20;
                x2 -= 20;
                x3 -= 20;
            }
        }

        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

        RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
        FillRect(mm->hdc2, &rrect3, brush);

        RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
        FillRect(mm->hdc2, &rrect4, brush);

        RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
        FillRect(mm->hdc2, &rrect5, brush);

        RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
        FillRect(mm->hdc2, &rrect6, brush);

        DeleteObject(brush);
    }
}
void Oikos::Beam::goRight() {

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);
    DeleteObject(brush);

    if(mm->choice == "lne" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      if(mm->b[x0+20][y0] == 0 &&
         mm->b[x1+20][y1] == 0 &&
         mm->b[x2+20][y2] == 0 &&
         mm->b[x3+20][y3] == 0 &&

         x0 < 400 &&
         x1 < 400 &&
         x2 < 400 &&
         x3 < 400
         ) {
          x0 += 20;
          x1 += 20;
          x2 += 20;
          x3 += 20;
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);
  }
}
BOOL Oikos::Beam::goDown() {

    BOOL canGoDown = FALSE;

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);
    DeleteObject(brush);

    if(mm->choice == "lne" && (y0 <= 630 || y1 <= 630 || y2 <= 630 || y3 <= 630)) {
        y0 += 20;
        y1 += 20;
        y2 += 20;
        y3 += 20;

        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

        RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
        FillRect(mm->hdc2, &rrect3, brush);

        RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
        FillRect(mm->hdc2, &rrect4, brush);

        RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
        FillRect(mm->hdc2, &rrect5, brush);

        RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
        FillRect(mm->hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
            mm->b[x0][y0] = 1;
            mm->b[x1][y1] = 1;
            mm->b[x2][y2] = 1;
            mm->b[x3][y3] = 1;
            mm->blocks++;
            mm->prep();
        } else {
        }

        BOOLEAN flag = FALSE;
        if(mm->b[x0][y0+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x1][y1+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x2][y2+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x3][y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            canGoDown = TRUE;
            mm->b[x0][y0] = 1;
            mm->b[x1][y1] = 1;
            mm->b[x2][y2] = 1;
            mm->b[x3][y3] = 1;
            mm->blocks++;
            mm->prep();
        } else
            canGoDown = FALSE;

        if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
    }

    return canGoDown;
}
void Oikos::Lsho::rotate() {

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);
    DeleteObject(brush);

    if(mm->choice == "lsh") {

        int lshx0, lshy0, lshx1, lshy1, lshx2, lshy2, lshx3, lshy3, lshdir;

        lshdir = dir;
        lshx0 = x0;
        lshy0 = y0;
        lshx1 = x1;
        lshy1 = y1;
        lshx2 = x2;
        lshy2 = y2;
        lshx3 = x3;
        lshy3 = y3;

        if(dir == 0) {
            dir = 1;
            x0 += 20* 1;
            y0 += 20* 1;
            x1 += 20* 1;
            y1 -= 20* 1;
            x2 += 20* 0;
            y2 += 20* 0;
            x3 += 20* 0;
            y3 -= 20* 2;
        }
        else if(dir == 1) {
            dir = 2;
            x0 -= 20* 1;
            y0 += 20* 1;
            x1 += 20* 1;
            y1 += 20* 1;
            x2 -= 20* 0;
            y2 += 20* 0;
            x3 += 20* 2;
            y3 -= 20* 0;
        }
        else if(dir == 2) {
            dir = 3;
            x0 -= 20* 1;
            y0 -= 20* 1;
            x1 -= 20* 1;
            y1 += 20* 1;
            x2 -= 20* 0;
            y2 -= 20* 0;
            x3 -= 20* 0;
            y3 += 20* 2;
        }
        else if(dir == 3) {
            dir = 0;
            x0 += 20* 1;
            y0 -= 20* 1;
            x1 -= 20* 1;
            y1 -= 20* 1;
            x2 += 20* 0;
            y2 -= 20* 0;
            x3 -= 20* 2;
            y3 += 20* 0;
        }

        if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
           x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
            dir = lshdir;
            x0 = lshx0;
            y0 = lshy0;
            x1 = lshx1;
            y1 = lshy1;
            x2 = lshx2;
            y2 = lshy2;
            x3 = lshx3;
            y3 = lshy3;
        }

        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

        RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
        FillRect(mm->hdc2, &rrect3, brush);

        RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
        FillRect(mm->hdc2, &rrect4, brush);

        RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
        FillRect(mm->hdc2, &rrect5, brush);

        RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
        FillRect(mm->hdc2, &rrect6, brush);
        DeleteObject(brush);
    }
}
void Oikos::Lsho::goLeft() {

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);
    DeleteObject(brush);

    if(mm->choice == "lsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
        if(x0 > 220 &&
           x1 > 220 &&
           x2 > 220 &&
           x3 > 220) {
            if(mm->b[x0-20][y0] == 0 &&
               mm->b[x1-20][y1] == 0 &&
               mm->b[x2-20][y2] == 0 &&
               mm->b[x3-20][y3] == 0) {
                x0 -= 20;
                x1 -= 20;
                x2 -= 20;
                x3 -= 20;
            }
        }

        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

        RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
        FillRect(mm->hdc2, &rrect3, brush);

        RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
        FillRect(mm->hdc2, &rrect4, brush);

        RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
        FillRect(mm->hdc2, &rrect5, brush);

        RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
        FillRect(mm->hdc2, &rrect6, brush);

        DeleteObject(brush);

        if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
            mm->b[x0][y0] = 1;
            mm->b[x1][y1] = 1;
            mm->b[x2][y2] = 1;
            mm->b[x3][y3] = 1;
            mm->blocks++;
            mm->prep();
        }

        BOOLEAN flag = FALSE;
        if(mm->b[x0][y0+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x1][y1+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x2][y2+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x3][y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            mm->b[x0][y0] = 1;
            mm->b[x1][y1] = 1;
            mm->b[x2][y2] = 1;
            mm->b[x3][y3] = 1;
            mm->blocks++;
            mm->prep();
        }
        if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(mm->b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(mm->hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                    Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(mm->hdc2, hOldPen));
                    SelectObject(mm->hdc2, hOldBsh);
                }
            }
        }
    }
}
void Oikos::Lsho::goRight() {

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);
    DeleteObject(brush);

    if(mm->choice == "lsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
        if(mm->b[x0+20][y0] == 0 &&
           mm->b[x1+20][y1] == 0 &&
           mm->b[x2+20][y2] == 0 &&
           mm->b[x3+20][y3] == 0 &&

           x0 < 400 &&
           x1 < 400 &&
           x2 < 400 &&
           x3 < 400
           ) {
            x0 += 20;
            x1 += 20;
            x2 += 20;
            x3 += 20;
        }

        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

        RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
        FillRect(mm->hdc2, &rrect3, brush);

        RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
        FillRect(mm->hdc2, &rrect4, brush);

        RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
        FillRect(mm->hdc2, &rrect5, brush);

        RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
        FillRect(mm->hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
            mm->b[x0][y0] = 1;
            mm->b[x1][y1] = 1;
            mm->b[x2][y2] = 1;
            mm->b[x3][y3] = 1;
            mm->blocks++;
            mm->prep();
        }

        BOOLEAN flag = FALSE;
        if(mm->b[x0][y0+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x1][y1+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x2][y2+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x3][y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            mm->b[x0][y0] = 1;
            mm->b[x1][y1] = 1;
            mm->b[x2][y2] = 1;
            mm->b[x3][y3] = 1;
            mm->blocks++;
            mm->prep();
        }
        if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(mm->b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(mm->hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                    Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(mm->hdc2, hOldPen));
                    SelectObject(mm->hdc2, hOldBsh);
                }
            }
        }
    }
}
BOOL Oikos::Lsho::goDown() {

    BOOL canGoDown = FALSE;

    HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
    RECT rrect3 = {219, 20, 420, 690};
    FillRect(mm->hdc2, &rrect3, brush);
    DeleteObject(brush);

    if(mm->choice == "lsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
        y0 += 20;
        y1 += 20;
        y2 += 20;
        y3 += 20;

        HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

        RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
        FillRect(mm->hdc2, &rrect3, brush);

        RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
        FillRect(mm->hdc2, &rrect4, brush);

        RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
        FillRect(mm->hdc2, &rrect5, brush);

        RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
        FillRect(mm->hdc2, &rrect6, brush);
        DeleteObject(brush);

        if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
            mm->b[x0][y0] = 1;
            mm->b[x1][y1] = 1;
            mm->b[x2][y2] = 1;
            mm->b[x3][y3] = 1;
            mm->blocks++;
            mm->prep();
        } else {
        }

        BOOLEAN flag = FALSE;
        if(mm->b[x0][y0+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x1][y1+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x2][y2+20] == 1) {
            flag = TRUE;
        }
        else if(mm->b[x3][y3+20] == 1) {
            flag = TRUE;
        }
        if(flag) {
            canGoDown = TRUE;
            mm->b[x0][y0] = 1;
            mm->b[x1][y1] = 1;
            mm->b[x2][y2] = 1;
            mm->b[x3][y3] = 1;
            mm->blocks++;
            mm->prep();
        } else
            canGoDown = FALSE;

        if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
        for(int i=0; i<700; i++) {
            for(int j=0; j<700; j++) {
                if(mm->b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(mm->hdc2, &rrect6, brush);
                    DeleteObject(brush);

                    HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                    HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                    Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                    DeleteObject(SelectObject(mm->hdc2, hOldPen));
                    SelectObject(mm->hdc2, hOldBsh);
                }
            }
        }

        return canGoDown;
    }
}
void Oikos::Rsho::rotate() {

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "rsh") {

      int rshx0, rshy0, rshx1, rshy1, rshx2, rshy2, rshx3, rshy3, rshdir;

      rshdir = dir;
      rshx0 = x0;
      rshy0 = y0;
      rshx1 = x1;
      rshy1 = y1;
      rshx2 = x2;
      rshy2 = y2;
      rshx3 = x3;
      rshy3 = y3;

      if(dir == 0) {
          dir = 1;
          x0 += 20* 1;
          y0 += 20* 1;
          x1 += 20* 0;
          y1 += 20* 0;
          x2 -= 20* 1;
          y2 += 20* 1;
          x3 -= 20* 2;
          y3 += 20* 0;
      }
      else if(dir == 1) {
          dir = 2;
          x0 -= 20* 1;
          y0 += 20* 1;
          x1 += 20* 0;
          y1 += 20* 0;
          x2 -= 20* 1;
          y2 -= 20* 1;
          x3 -= 20* 0;
          y3 -= 20* 2;
      }
      else if(dir == 2) {
          dir = 3;
          x0 -= 20* 1;
          y0 -= 20* 1;
          x1 -= 20* 0;
          y1 -= 20* 0;
          x2 += 20* 1;
          y2 -= 20* 1;
          x3 += 20* 2;
          y3 -= 20* 0;
      }
      else if(dir == 3) {
          dir = 0;
          x0 += 20* 1;
          y0 -= 20* 1;
          x1 += 20* 0;
          y1 -= 20* 0;
          x2 += 20* 1;
          y2 += 20* 1;
          x3 += 20* 0;
          y3 += 20* 2;
      }

      if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
         x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
          dir = rshdir;
          x0 = rshx0;
          y0 = rshy0;
          x1 = rshx1;
          y1 = rshy1;
          x2 = rshx2;
          y2 = rshy2;
          x3 = rshx3;
          y3 = rshy3;
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);
  }
}
void Oikos::Rsho::goLeft() {

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "rsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      if(x0 > 220 &&
         x1 > 220 &&
         x2 > 220 &&
         x3 > 220) {
          if(mm->b[x0-20][y0] == 0 &&
             mm->b[x1-20][y1] == 0 &&
             mm->b[x2-20][y2] == 0 &&
             mm->b[x3-20][y3] == 0) {
              x0 -= 20;
              x1 -= 20;
              x2 -= 20;
              x3 -= 20;
          }
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);

      if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }
      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
      for(int i=0; i<700; i++) {
          for(int j=0; j<700; j++) {
              if(mm->b[i][j] == 1) {
                  HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                  RECT rrect6 = {i, j, i + 20, j + 20};
                  FillRect(mm->hdc2, &rrect6, brush);
                  DeleteObject(brush);

                  HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                  HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                  Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                  DeleteObject(SelectObject(mm->hdc2, hOldPen));
                  SelectObject(mm->hdc2, hOldBsh);
              }
          }
      }
  }
}
void Oikos::Rsho::goRight() {

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "rsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      if(mm->b[x0+20][y0] == 0 &&
         mm->b[x1+20][y1] == 0 &&
         mm->b[x2+20][y2] == 0 &&
         mm->b[x3+20][y3] == 0 &&

         x0 < 400 &&
         x1 < 400 &&
         x2 < 400 &&
         x3 < 400
         ) {
          x0 += 20;
          x1 += 20;
          x2 += 20;
          x3 += 20;
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);

      if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }
      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
      for(int i=0; i<700; i++) {
          for(int j=0; j<700; j++) {
              if(mm->b[i][j] == 1) {
                  HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                  RECT rrect6 = {i, j, i + 20, j + 20};
                  FillRect(mm->hdc2, &rrect6, brush);
                  DeleteObject(brush);

                  HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                  HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                  Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                  DeleteObject(SelectObject(mm->hdc2, hOldPen));
                  SelectObject(mm->hdc2, hOldBsh);
              }
          }
      }
  }
}
BOOL Oikos::Rsho::goDown() {

  BOOL canGoDown = FALSE;

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "rsh" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      y0 += 20;
      y1 += 20;
      y2 += 20;
      y3 += 20;

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);

      if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      } else {
      }

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          canGoDown = TRUE;
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      } else
          canGoDown = FALSE;

      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
      for(int i=0; i<700; i++) {
          for(int j=0; j<700; j++) {
              if(mm->b[i][j] == 1) {
                  HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                  RECT rrect6 = {i, j, i + 20, j + 20};
                  FillRect(mm->hdc2, &rrect6, brush);
                  DeleteObject(brush);

                  HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                  HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                  Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                  DeleteObject(SelectObject(mm->hdc2, hOldPen));
                  SelectObject(mm->hdc2, hOldBsh);
              }
          }
      }
  }

  return canGoDown;
}
void Oikos::Larm::rotate() {

      HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
      RECT rrect3 = {219, 20, 420, 690};
      FillRect(mm->hdc2, &rrect3, brush);
      DeleteObject(brush);

      if(mm->choice == "larm") {

          int larmx0, larmy0, larmx1, larmy1, larmx2, larmy2, larmx3, larmy3, larmdir;

          larmdir = dir;
          larmx0 = x0;
          larmy0 = y0;
          larmx1 = x1;
          larmy1 = y1;
          larmx2 = x2;
          larmy2 = y2;
          larmx3 = x3;
          larmy3 = y3;

          if(dir == 0) {
              dir = 1;
              x0 += 20* 2;
              y0 += 20* 2;
              x1 += 20* 1;
              y1 += 20* 1;
              x2 += 20* 0;
              y2 += 20* 0;
              x3 += 20* 1;
              y3 -= 20* 1;
          }
          else if(dir == 1) {
              dir = 2;
              x0 -= 20* 2;
              y0 += 20* 2;
              x1 -= 20* 1;
              y1 += 20* 1;
              x2 -= 20* 0;
              y2 += 20* 0;
              x3 += 20* 1;
              y3 += 20* 1;
          }
          else if(dir == 2) {
              dir = 3;
              x0 -= 20* 2;
              y0 -= 20* 2;
              x1 -= 20* 1;
              y1 -= 20* 1;
              x2 -= 20* 0;
              y2 -= 20* 0;
              x3 -= 20* 1;
              y3 += 20* 1;
          }
          else if(dir == 3) {
              dir = 0;
              x0 += 20* 2;
              y0 -= 20* 2;
              x1 += 20* 1;
              y1 -= 20* 1;
              x2 += 20* 0;
              y2 -= 20* 0;
              x3 -= 20* 1;
              y3 -= 20* 1;
          }

          if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
             x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
              dir = larmdir;
              x0 = larmx0;
              y0 = larmy0;
              x1 = larmx1;
              y1 = larmy1;
              x2 = larmx2;
              y2 = larmy2;
              x3 = larmx3;
              y3 = larmy3;
          }

          HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

          RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
          FillRect(mm->hdc2, &rrect3, brush);

          RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
          FillRect(mm->hdc2, &rrect4, brush);

          RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
          FillRect(mm->hdc2, &rrect5, brush);

          RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
          FillRect(mm->hdc2, &rrect6, brush);
          DeleteObject(brush);
      }
}
void Oikos::Larm::goLeft() {

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "larm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      if(x0 > 220 &&
         x1 > 220 &&
         x2 > 220 &&
         x3 > 220) {
          if(mm->b[x0-20][y0] == 0 &&
             mm->b[x1-20][y1] == 0 &&
             mm->b[x2-20][y2] == 0 &&
             mm->b[x3-20][y3] == 0) {
              x0 -= 20;
              x1 -= 20;
              x2 -= 20;
              x3 -= 20;
          }
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);

      DeleteObject(brush);

      if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }
      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
      for(int i=0; i<700; i++) {
          for(int j=0; j<700; j++) {
              if(mm->b[i][j] == 1) {
                  HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                  RECT rrect6 = {i, j, i + 20, j + 20};
                  FillRect(mm->hdc2, &rrect6, brush);
                  DeleteObject(brush);

                  HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                  HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                  Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                  DeleteObject(SelectObject(mm->hdc2, hOldPen));
                  SelectObject(mm->hdc2, hOldBsh);
              }
          }
      }
  }
}
void Oikos::Larm::goRight() {

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "larm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      if(mm->b[x0+20][y0] == 0 &&
         mm->b[x1+20][y1] == 0 &&
         mm->b[x2+20][y2] == 0 &&
         mm->b[x3+20][y3] == 0 &&

         x0 < 400 &&
         x1 < 400 &&
         x2 < 400 &&
         x3 < 400
         ) {
          x0 += 20;
          x1 += 20;
          x2 += 20;
          x3 += 20;
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);

      if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }
      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
      for(int i=0; i<700; i++) {
          for(int j=0; j<700; j++) {
              if(mm->b[i][j] == 1) {
                  HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                  RECT rrect6 = {i, j, i + 20, j + 20};
                  FillRect(mm->hdc2, &rrect6, brush);
                  DeleteObject(brush);

                  HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                  HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                  Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                  DeleteObject(SelectObject(mm->hdc2, hOldPen));
                  SelectObject(mm->hdc2, hOldBsh);
              }
          }
      }
  }
}
BOOL Oikos::Larm::goDown() {

  BOOL canGoDown = FALSE;

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "larm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      y0 += 20;
      y1 += 20;
      y2 += 20;
      y3 += 20;

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);

      if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      } else {
      }

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          canGoDown = TRUE;
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      } else
          canGoDown = FALSE;

      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
      for(int i=0; i<700; i++) {
          for(int j=0; j<700; j++) {
              if(mm->b[i][j] == 1) {
                  HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                  RECT rrect6 = {i, j, i + 20, j + 20};
                  FillRect(mm->hdc2, &rrect6, brush);
                  DeleteObject(brush);

                  HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                  HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                  Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                  DeleteObject(SelectObject(mm->hdc2, hOldPen));
                  SelectObject(mm->hdc2, hOldBsh);
              }
          }
      }
  }

  return canGoDown;
}
void Oikos::Rarm::rotate() {

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "rarm") {

      int rarmx0, rarmy0, rarmx1, rarmy1, rarmx2, rarmy2, rarmx3, rarmy3, rarmdir;

      rarmdir = dir;
      rarmx0 = x0;
      rarmy0 = y0;
      rarmx1 = x1;
      rarmy1 = y1;
      rarmx2 = x2;
      rarmy2 = y2;
      rarmx3 = x3;
      rarmy3 = y3;

      if(dir == 0) {
          dir = 1;
          x0 += 20* 2;
          y0 += 20* 2;
          x1 += 20* 1;
          y1 += 20* 1;
          x2 += 20* 0;
          y2 += 20* 0;
          x3 -= 20* 1;
          y3 += 20* 1;
      }
      else if(dir == 1) {
          dir = 2;
          x0 -= 20* 2;
          y0 += 20* 2;
          x1 -= 20* 1;
          y1 += 20* 1;
          x2 -= 20* 0;
          y2 += 20* 0;
          x3 -= 20* 1;
          y3 -= 20* 1;
      }
      else if(dir == 2) {
          dir = 3;
          x0 -= 20* 2;
          y0 -= 20* 2;
          x1 -= 20* 1;
          y1 -= 20* 1;
          x2 -= 20* 0;
          y2 -= 20* 0;
          x3 += 20* 1;
          y3 -= 20* 1;
      }
      else if(dir == 3) {
          dir = 0;
          x0 += 20* 2;
          y0 -= 20* 2;
          x1 += 20* 1;
          y1 -= 20* 1;
          x2 += 20* 0;
          y2 -= 20* 0;
          x3 += 20* 1;
          y3 += 20* 1;
      }

      if(x0 > 400 || x1 > 400 || x2 > 400 || x3 > 400 ||
         x0 < 220 || x1 < 220 || x2 < 220 || x3 < 220) {
          dir = rarmdir;
          x0 = rarmx0;
          y0 = rarmy0;
          x1 = rarmx1;
          y1 = rarmy1;
          x2 = rarmx2;
          y2 = rarmy2;
          x3 = rarmx3;
          y3 = rarmy3;
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);
  }
}
void Oikos::Rarm::goLeft() {

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "rarm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      if(x0 > 220 &&
         x1 > 220 &&
         x2 > 220 &&
         x3 > 220) {
          if(mm->b[x0-20][y0] == 0 &&
             mm->b[x1-20][y1] == 0 &&
             mm->b[x2-20][y2] == 0 &&
             mm->b[x3-20][y3] == 0) {
              x0 -= 20;
              x1 -= 20;
              x2 -= 20;
              x3 -= 20;
          }
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);

      DeleteObject(brush);

      if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }
      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
      for(int i=0; i<700; i++) {
          for(int j=0; j<700; j++) {
              if(mm->b[i][j] == 1) {
                  HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                  RECT rrect6 = {i, j, i + 20, j + 20};
                  FillRect(mm->hdc2, &rrect6, brush);
                  DeleteObject(brush);

                  HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                  HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                  Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                  DeleteObject(SelectObject(mm->hdc2, hOldPen));
                  SelectObject(mm->hdc2, hOldBsh);
              }
          }
      }
  }
}
void Oikos::Rarm::goRight() {

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "rarm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      if(mm->b[x0+20][y0] == 0 &&
         mm->b[x1+20][y1] == 0 &&
         mm->b[x2+20][y2] == 0 &&
         mm->b[x3+20][y3] == 0 &&

         x0 < 400 &&
         x1 < 400 &&
         x2 < 400 &&
         x3 < 400
         ) {
          x0 += 20;
          x1 += 20;
          x2 += 20;
          x3 += 20;
      }

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);

      if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      }
      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
      for(int i=0; i<700; i++) {
          for(int j=0; j<700; j++) {
              if(mm->b[i][j] == 1) {
                  HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                  RECT rrect6 = {i, j, i + 20, j + 20};
                  FillRect(mm->hdc2, &rrect6, brush);
                  DeleteObject(brush);

                  HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                  HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                  Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                  DeleteObject(SelectObject(mm->hdc2, hOldPen));
                  SelectObject(mm->hdc2, hOldBsh);
              }
          }
      }
  }
}
BOOL Oikos::Rarm::goDown() {

  BOOL canGoDown = FALSE;

  HBRUSH brush = CreateSolidBrush(RGB(58, 205, 130));
  RECT rrect3 = {219, 20, 420, 690};
  FillRect(mm->hdc2, &rrect3, brush);
  DeleteObject(brush);

  if(mm->choice == "rarm" && (y0 <= 650 && y1 <= 650 && y2 <= 650 && y3 <= 650)) {
      y0 += 20;
      y1 += 20;
      y2 += 20;
      y3 += 20;

      HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));

      RECT rrect3 = {x0, y0, x0 + 20, y0 + 20};
      FillRect(mm->hdc2, &rrect3, brush);

      RECT rrect4 = {x1, y1, x1 + 20, y1 + 20};
      FillRect(mm->hdc2, &rrect4, brush);

      RECT rrect5 = {x2, y2, x2 + 20, y2 + 20};
      FillRect(mm->hdc2, &rrect5, brush);

      RECT rrect6 = {x3, y3, x3 + 20, y3 + 20};
      FillRect(mm->hdc2, &rrect6, brush);
      DeleteObject(brush);

      if(y0 > 650 || y1 > 650 || y2 > 650 || y3 > 650) {
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      } else {
      }

      BOOLEAN flag = FALSE;
      if(mm->b[x0][y0+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x1][y1+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x2][y2+20] == 1) {
          flag = TRUE;
      }
      else if(mm->b[x3][y3+20] == 1) {
          flag = TRUE;
      }
      if(flag) {
          canGoDown = TRUE;
          mm->b[x0][y0] = 1;
          mm->b[x1][y1] = 1;
          mm->b[x2][y2] = 1;
          mm->b[x3][y3] = 1;
          mm->blocks++;
          mm->prep();
      } else
          canGoDown = FALSE;

      if(mm->level < 40 && mm->lines >= mm->linenext) {mm->level++;mm->linenext+=10;mm->sleeptime-=15;}
      for(int i=0; i<700; i++) {
          for(int j=0; j<700; j++) {
              if(mm->b[i][j] == 1) {
                  HBRUSH brush = CreateSolidBrush(RGB(80, 80, 80));
                  RECT rrect6 = {i, j, i + 20, j + 20};
                  FillRect(mm->hdc2, &rrect6, brush);
                  DeleteObject(brush);

                  HGDIOBJ hOldBsh = SelectObject(mm->hdc2, GetStockObject(NULL_BRUSH));
                  HGDIOBJ hOldPen = SelectObject(mm->hdc2, CreatePen(PS_SOLID, 1, RGB(80, 80, 80)));
                  Rectangle(mm->hdc2, i, j, i + 20, j + 20);
                  DeleteObject(SelectObject(mm->hdc2, hOldPen));
                  SelectObject(mm->hdc2, hOldBsh);
              }
          }
      }
  }

  return canGoDown;
}
void Oikos::prep() {

    choice = choicepre;
    if(fist) {
        int r = rand() % 7;
        if(r == 1)
          choicepre = "sq";
        else if(r == 2)
          choicepre = "lne";
        else if(r == 3)
          choicepre = "ht";
        else if(r == 4)
          choicepre = "larm";
        else if(r == 5)
          choicepre = "rarm";
        else if(r == 6)
          choicepre = "lsh";
        else
          choicepre = "rsh";
        choice = choicepre;
    }
    fist = FALSE;
    //cout << choice;
    //cout << "\n";
    int r = rand() % 7;
    if(r == 1)
      choicepre = "sq";
    else if(r == 2)
      choicepre = "lne";
    else if(r == 3)
      choicepre = "ht";
    else if(r == 4)
      choicepre = "larm";
    else if(r == 5)
      choicepre = "rarm";
    else if(r == 6)
      choicepre = "lsh";
    else
      choicepre = "rsh";
    lsh->x0 = 300;
    lsh->y0 = 50;
    lsh->x1 = 280;
    lsh->y1 = 70;
    lsh->x2 = 300;
    lsh->y2 = 70;
    lsh->x3 = 280;
    lsh->y3 = 90;
    lsh->dir = 0;
    rsh->x0 = 300;
    rsh->y0 = 50;
    rsh->x1 = 300;
    rsh->y1 = 70;
    rsh->x2 = 320;
    rsh->y2 = 70;
    rsh->x3 = 320;
    rsh->y3 = 90;
    rsh->dir = 0;
    larm->x0 = 300;
    larm->y0 = 50;
    larm->x1 = 300;
    larm->y1 = 70;
    larm->x2 = 300;
    larm->y2 = 90;
    larm->x3 = 280;
    larm->y3 = 90;
    larm->dir = 0;
    rarm->x0 = 300;
    rarm->y0 = 50;
    rarm->x1 = 300;
    rarm->y1 = 70;
    rarm->x2 = 300;
    rarm->y2 = 90;
    rarm->x3 = 320;
    rarm->y3 = 90;
    rarm->dir = 0;
    ht->x0 = 300;
    ht->y0 = 50;
    ht->x1 = 280;
    ht->y1 = 70;
    ht->x2 = 300;
    ht->y2 = 70;
    ht->x3 = 320;
    ht->y3 = 70;
    ht->dir = 0;
    sq->x0 = 300;
    sq->y0 = 50;
    sq->x1 = 320;
    sq->y1 = 50;
    sq->x2 = 300;
    sq->y2 = 70;
    sq->x3 = 320;
    sq->y3 = 70;
    lne->x0 = 300;
    lne->y0 = 50;
    lne->x1 = 300;
    lne->y1 = 70;
    lne->x2 = 300;
    lne->y2 = 90;
    lne->x3 = 300;
    lne->y3 = 110;
    lne->dir = 0;
}