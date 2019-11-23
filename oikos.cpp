#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <mmsystem.h>
#include <unistd.h>
#include <mmsystem.h>
#include "oikosdef.h"

using namespace std;

Oikos* kingdomOikos = new Oikos();

DWORD WINAPI downs(void* data) {
    BOOLEAN downIt = TRUE;
    do {
        kingdomOikos->hdcMem = CreateCompatibleDC(kingdomOikos->hdc2);

        HBRUSH brush = CreateSolidBrush(RGB(60, 101, 25));

        RECT rrect3 = {219, 20, 420, 690};
        FillRect(kingdomOikos->hdc2, &rrect3, brush);
        DeleteObject(brush);

        if(kingdomOikos->choice == "sq" && (kingdomOikos->sq->y0 <= 630 && kingdomOikos->sq->y1 <= 630 && kingdomOikos->sq->y2 <= 630 && kingdomOikos->sq->y3 <= 630)) {

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
            
            RECT rrect3 = {kingdomOikos->sq->x0, kingdomOikos->sq->y0, kingdomOikos->sq->x0 + 20, kingdomOikos->sq->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->sq->x1, kingdomOikos->sq->y1, kingdomOikos->sq->x1 + 20, kingdomOikos->sq->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->sq->x2, kingdomOikos->sq->y2, kingdomOikos->sq->x2 + 20, kingdomOikos->sq->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->sq->x3, kingdomOikos->sq->y3, kingdomOikos->sq->x3 + 20, kingdomOikos->sq->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->sq->y0 > 650 || kingdomOikos->sq->y1 > 650 || kingdomOikos->sq->y2 > 650 || kingdomOikos->sq->y3 > 650) {
                kingdomOikos->b[kingdomOikos->sq->x0][kingdomOikos->sq->y0] = 1;
                kingdomOikos->b[kingdomOikos->sq->x1][kingdomOikos->sq->y1] = 1;
                kingdomOikos->b[kingdomOikos->sq->x2][kingdomOikos->sq->y2] = 1;
                kingdomOikos->b[kingdomOikos->sq->x3][kingdomOikos->sq->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->sq->x0][kingdomOikos->sq->y0+20] == 1) {
                flag = TRUE;
            } else if(kingdomOikos->b[kingdomOikos->sq->x1][kingdomOikos->sq->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->sq->x2][kingdomOikos->sq->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->sq->x3][kingdomOikos->sq->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->sq->x0][kingdomOikos->sq->y0] = 1;
                kingdomOikos->b[kingdomOikos->sq->x1][kingdomOikos->sq->y1] = 1;
                kingdomOikos->b[kingdomOikos->sq->x2][kingdomOikos->sq->y2] = 1;
                kingdomOikos->b[kingdomOikos->sq->x3][kingdomOikos->sq->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
        }
        else if(kingdomOikos->choice == "lne" && (kingdomOikos->lne->y0 <= 630 || kingdomOikos->lne->y1 <= 630 || kingdomOikos->lne->y2 <= 630 || kingdomOikos->lne->y3 <= 630)) {

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->lne->x0, kingdomOikos->lne->y0, kingdomOikos->lne->x0 + 20, kingdomOikos->lne->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->lne->x1, kingdomOikos->lne->y1, kingdomOikos->lne->x1 + 20, kingdomOikos->lne->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->lne->x2, kingdomOikos->lne->y2, kingdomOikos->lne->x2 + 20, kingdomOikos->lne->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->lne->x3, kingdomOikos->lne->y3, kingdomOikos->lne->x3 + 20, kingdomOikos->lne->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->lne->y0 > 650 || kingdomOikos->lne->y1 > 650 || kingdomOikos->lne->y2 > 650 || kingdomOikos->lne->y3 > 650) {
                kingdomOikos->b[kingdomOikos->lne->x0][kingdomOikos->lne->y0] = 1;
                kingdomOikos->b[kingdomOikos->lne->x1][kingdomOikos->lne->y1] = 1;
                kingdomOikos->b[kingdomOikos->lne->x2][kingdomOikos->lne->y2] = 1;
                kingdomOikos->b[kingdomOikos->lne->x3][kingdomOikos->lne->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->lne->x0][kingdomOikos->lne->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lne->x1][kingdomOikos->lne->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lne->x2][kingdomOikos->lne->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lne->x3][kingdomOikos->lne->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->lne->x0][kingdomOikos->lne->y0] = 1;
                kingdomOikos->b[kingdomOikos->lne->x1][kingdomOikos->lne->y1] = 1;
                kingdomOikos->b[kingdomOikos->lne->x2][kingdomOikos->lne->y2] = 1;
                kingdomOikos->b[kingdomOikos->lne->x3][kingdomOikos->lne->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
        }
        else if(kingdomOikos->choice == "ht" && (kingdomOikos->ht->y0 <= 630 && kingdomOikos->ht->y1 <= 630 && kingdomOikos->ht->y2 <= 630 && kingdomOikos->ht->y3 <= 630)) {

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->ht->x0, kingdomOikos->ht->y0, kingdomOikos->ht->x0 + 20, kingdomOikos->ht->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->ht->x1, kingdomOikos->ht->y1, kingdomOikos->ht->x1 + 20, kingdomOikos->ht->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->ht->x2, kingdomOikos->ht->y2, kingdomOikos->ht->x2 + 20, kingdomOikos->ht->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->ht->x3, kingdomOikos->ht->y3, kingdomOikos->ht->x3 + 20, kingdomOikos->ht->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->ht->y0 > 630 || kingdomOikos->ht->y1 > 630 || kingdomOikos->ht->y2 > 630 || kingdomOikos->ht->y3 > 630) {
                kingdomOikos->b[kingdomOikos->ht->x0][kingdomOikos->ht->y0] = 1;
                kingdomOikos->b[kingdomOikos->ht->x1][kingdomOikos->ht->y1] = 1;
                kingdomOikos->b[kingdomOikos->ht->x2][kingdomOikos->ht->y2] = 1;
                kingdomOikos->b[kingdomOikos->ht->x3][kingdomOikos->ht->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->ht->x0][kingdomOikos->ht->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->ht->x1][kingdomOikos->ht->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->ht->x2][kingdomOikos->ht->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->ht->x3][kingdomOikos->ht->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->ht->x0][kingdomOikos->ht->y0] = 1;
                kingdomOikos->b[kingdomOikos->ht->x1][kingdomOikos->ht->y1] = 1;
                kingdomOikos->b[kingdomOikos->ht->x2][kingdomOikos->ht->y2] = 1;
                kingdomOikos->b[kingdomOikos->ht->x3][kingdomOikos->ht->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
        }
        else if(kingdomOikos->choice == "larm" && (kingdomOikos->larm->y0 <= 650 && kingdomOikos->larm->y1 <= 650 && kingdomOikos->larm->y2 <= 650 && kingdomOikos->larm->y3 <= 650)) {

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->larm->x0, kingdomOikos->larm->y0, kingdomOikos->larm->x0 + 20, kingdomOikos->larm->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->larm->x1, kingdomOikos->larm->y1, kingdomOikos->larm->x1 + 20, kingdomOikos->larm->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->larm->x2, kingdomOikos->larm->y2, kingdomOikos->larm->x2 + 20, kingdomOikos->larm->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->larm->x3, kingdomOikos->larm->y3, kingdomOikos->larm->x3 + 20, kingdomOikos->larm->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->larm->y0 > 650 || kingdomOikos->larm->y1 > 650 || kingdomOikos->larm->y2 > 650 || kingdomOikos->larm->y3 > 650) {
                kingdomOikos->b[kingdomOikos->larm->x0][kingdomOikos->larm->y0] = 1;
                kingdomOikos->b[kingdomOikos->larm->x1][kingdomOikos->larm->y1] = 1;
                kingdomOikos->b[kingdomOikos->larm->x2][kingdomOikos->larm->y2] = 1;
                kingdomOikos->b[kingdomOikos->larm->x3][kingdomOikos->larm->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->larm->x0][kingdomOikos->larm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->larm->x1][kingdomOikos->larm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->larm->x2][kingdomOikos->larm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->larm->x3][kingdomOikos->larm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->larm->x0][kingdomOikos->larm->y0] = 1;
                kingdomOikos->b[kingdomOikos->larm->x1][kingdomOikos->larm->y1] = 1;
                kingdomOikos->b[kingdomOikos->larm->x2][kingdomOikos->larm->y2] = 1;
                kingdomOikos->b[kingdomOikos->larm->x3][kingdomOikos->larm->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(250, 50, 250));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(kingdomOikos->choice == "rarm" && (kingdomOikos->rarm->y0 <= 650 && kingdomOikos->rarm->y1 <= 650 && kingdomOikos->rarm->y2 <= 650 && kingdomOikos->rarm->y3 <= 650)) {

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->rarm->x0, kingdomOikos->rarm->y0, kingdomOikos->rarm->x0 + 20, kingdomOikos->rarm->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->rarm->x1, kingdomOikos->rarm->y1, kingdomOikos->rarm->x1 + 20, kingdomOikos->rarm->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->rarm->x2, kingdomOikos->rarm->y2, kingdomOikos->rarm->x2 + 20, kingdomOikos->rarm->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->rarm->x3, kingdomOikos->rarm->y3, kingdomOikos->rarm->x3 + 20, kingdomOikos->rarm->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->rarm->y0 > 650 || kingdomOikos->rarm->y1 > 650 || kingdomOikos->rarm->y2 > 650 || kingdomOikos->rarm->y3 > 650) {
                kingdomOikos->b[kingdomOikos->rarm->x0][kingdomOikos->rarm->y0] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x1][kingdomOikos->rarm->y1] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x2][kingdomOikos->rarm->y2] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x3][kingdomOikos->rarm->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->rarm->x0][kingdomOikos->rarm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rarm->x1][kingdomOikos->rarm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rarm->x2][kingdomOikos->rarm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rarm->x3][kingdomOikos->rarm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->rarm->x0][kingdomOikos->rarm->y0] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x1][kingdomOikos->rarm->y1] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x2][kingdomOikos->rarm->y2] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x3][kingdomOikos->rarm->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(kingdomOikos->choice == "lsh" && (kingdomOikos->lsh->y0 <= 650 && kingdomOikos->lsh->y1 <= 650 && kingdomOikos->lsh->y2 <= 650 && kingdomOikos->lsh->y3 <= 650)) {

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->lsh->x0, kingdomOikos->lsh->y0, kingdomOikos->lsh->x0 + 20, kingdomOikos->lsh->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->lsh->x1, kingdomOikos->lsh->y1, kingdomOikos->lsh->x1 + 20, kingdomOikos->lsh->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->lsh->x2, kingdomOikos->lsh->y2, kingdomOikos->lsh->x2 + 20, kingdomOikos->lsh->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->lsh->x3, kingdomOikos->lsh->y3, kingdomOikos->lsh->x3 + 20, kingdomOikos->lsh->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->lsh->y0 > 650 || kingdomOikos->lsh->y1 > 650 || kingdomOikos->lsh->y2 > 650 || kingdomOikos->lsh->y3 > 650) {
                kingdomOikos->b[kingdomOikos->lsh->x0][kingdomOikos->lsh->y0] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x1][kingdomOikos->lsh->y1] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x2][kingdomOikos->lsh->y2] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x3][kingdomOikos->lsh->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->lsh->x0][kingdomOikos->lsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lsh->x1][kingdomOikos->lsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lsh->x2][kingdomOikos->lsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lsh->x3][kingdomOikos->lsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->lsh->x0][kingdomOikos->lsh->y0] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x1][kingdomOikos->lsh->y1] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x2][kingdomOikos->lsh->y2] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x3][kingdomOikos->lsh->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(kingdomOikos->choice == "rsh" && (kingdomOikos->rsh->y0 <= 650 && kingdomOikos->rsh->y1 <= 650 && kingdomOikos->rsh->y2 <= 650 && kingdomOikos->rsh->y3 <= 650)) {

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->rsh->x0, kingdomOikos->rsh->y0, kingdomOikos->rsh->x0 + 20, kingdomOikos->rsh->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->rsh->x1, kingdomOikos->rsh->y1, kingdomOikos->rsh->x1 + 20, kingdomOikos->rsh->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->rsh->x2, kingdomOikos->rsh->y2, kingdomOikos->rsh->x2 + 20, kingdomOikos->rsh->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->rsh->x3, kingdomOikos->rsh->y3, kingdomOikos->rsh->x3 + 20, kingdomOikos->rsh->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->rsh->y0 > 650 || kingdomOikos->rsh->y1 > 650 || kingdomOikos->rsh->y2 > 650 || kingdomOikos->rsh->y3 > 650) {
                kingdomOikos->b[kingdomOikos->rsh->x0][kingdomOikos->rsh->y0] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x1][kingdomOikos->rsh->y1] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x2][kingdomOikos->rsh->y2] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x3][kingdomOikos->rsh->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->rsh->x0][kingdomOikos->rsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rsh->x1][kingdomOikos->rsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rsh->x2][kingdomOikos->rsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rsh->x3][kingdomOikos->rsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->rsh->x0][kingdomOikos->rsh->y0] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x1][kingdomOikos->rsh->y1] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x2][kingdomOikos->rsh->y2] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x3][kingdomOikos->rsh->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }
        }

        if(kingdomOikos->fist) {
            kingdomOikos->prep();
        }

        for(int i=0; i<700; i++) {
            for(int j=0; j<720; j++) {
                if(kingdomOikos->b[i][j] == 1) {
                    HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                    RECT rrect6 = {i, j, i + 20, j + 20};
                    FillRect(kingdomOikos->hdc2, &rrect6, brush);
                    DeleteObject(brush);
                }
            }
        }

        kingdomOikos->erasePreview();
        kingdomOikos->showNextPiece();

        for(int x=0; x<4; x++) {
            kingdomOikos->clearLine();
        }

        usleep(1103000);

        if(kingdomOikos->choice == "sq") {

            kingdomOikos->sq->y0 += 20;
            kingdomOikos->sq->y1 += 20;
            kingdomOikos->sq->y2 += 20;
            kingdomOikos->sq->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->sq->x0, kingdomOikos->sq->y0, kingdomOikos->sq->x0 + 20, kingdomOikos->sq->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->sq->x1, kingdomOikos->sq->y1, kingdomOikos->sq->x1 + 20, kingdomOikos->sq->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->sq->x2, kingdomOikos->sq->y2, kingdomOikos->sq->x2 + 20, kingdomOikos->sq->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->sq->x3, kingdomOikos->sq->y3, kingdomOikos->sq->x3 + 20, kingdomOikos->sq->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->sq->y0 > 650 || kingdomOikos->sq->y1 > 650 || kingdomOikos->sq->y2 > 650 || kingdomOikos->sq->y3 > 650) {
                kingdomOikos->b[kingdomOikos->sq->x0][kingdomOikos->sq->y0] = 1;
                kingdomOikos->b[kingdomOikos->sq->x1][kingdomOikos->sq->y1] = 1;
                kingdomOikos->b[kingdomOikos->sq->x2][kingdomOikos->sq->y2] = 1;
                kingdomOikos->b[kingdomOikos->sq->x3][kingdomOikos->sq->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->sq->x0][kingdomOikos->sq->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->sq->x1][kingdomOikos->sq->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->sq->x2][kingdomOikos->sq->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->sq->x3][kingdomOikos->sq->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->sq->x0][kingdomOikos->sq->y0] = 1;
                kingdomOikos->b[kingdomOikos->sq->x1][kingdomOikos->sq->y1] = 1;
                kingdomOikos->b[kingdomOikos->sq->x2][kingdomOikos->sq->y2] = 1;
                kingdomOikos->b[kingdomOikos->sq->x3][kingdomOikos->sq->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(kingdomOikos->choice == "lne") {

            kingdomOikos->lne->y0 += 20;
            kingdomOikos->lne->y1 += 20;
            kingdomOikos->lne->y2 += 20;
            kingdomOikos->lne->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->lne->x0, kingdomOikos->lne->y0, kingdomOikos->lne->x0 + 20, kingdomOikos->lne->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->lne->x1, kingdomOikos->lne->y1, kingdomOikos->lne->x1 + 20, kingdomOikos->lne->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->lne->x2, kingdomOikos->lne->y2, kingdomOikos->lne->x2 + 20, kingdomOikos->lne->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->lne->x3, kingdomOikos->lne->y3, kingdomOikos->lne->x3 + 20, kingdomOikos->lne->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->lne->y0 > 650 || kingdomOikos->lne->y1 > 650 || kingdomOikos->lne->y2 > 650 || kingdomOikos->lne->y3 > 650) {
                kingdomOikos->b[kingdomOikos->lne->x0][kingdomOikos->lne->y0] = 1;
                kingdomOikos->b[kingdomOikos->lne->x1][kingdomOikos->lne->y1] = 1;
                kingdomOikos->b[kingdomOikos->lne->x2][kingdomOikos->lne->y2] = 1;
                kingdomOikos->b[kingdomOikos->lne->x3][kingdomOikos->lne->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->lne->x0][kingdomOikos->lne->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lne->x1][kingdomOikos->lne->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lne->x2][kingdomOikos->lne->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lne->x3][kingdomOikos->lne->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->lne->x0][kingdomOikos->lne->y0] = 1;
                kingdomOikos->b[kingdomOikos->lne->x1][kingdomOikos->lne->y1] = 1;
                kingdomOikos->b[kingdomOikos->lne->x2][kingdomOikos->lne->y2] = 1;
                kingdomOikos->b[kingdomOikos->lne->x3][kingdomOikos->lne->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(kingdomOikos->choice == "ht") {

            kingdomOikos->ht->y0 += 20;
            kingdomOikos->ht->y1 += 20;
            kingdomOikos->ht->y2 += 20;
            kingdomOikos->ht->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->ht->x0, kingdomOikos->ht->y0, kingdomOikos->ht->x0 + 20, kingdomOikos->ht->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->ht->x1, kingdomOikos->ht->y1, kingdomOikos->ht->x1 + 20, kingdomOikos->ht->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->ht->x2, kingdomOikos->ht->y2, kingdomOikos->ht->x2 + 20, kingdomOikos->ht->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->ht->x3, kingdomOikos->ht->y3, kingdomOikos->ht->x3 + 20, kingdomOikos->ht->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->ht->y0 > 650 || kingdomOikos->ht->y1 > 650 || kingdomOikos->ht->y2 > 650 || kingdomOikos->ht->y3 > 650) {
                kingdomOikos->b[kingdomOikos->ht->x0][kingdomOikos->ht->y0] = 1;
                kingdomOikos->b[kingdomOikos->ht->x1][kingdomOikos->ht->y1] = 1;
                kingdomOikos->b[kingdomOikos->ht->x2][kingdomOikos->ht->y2] = 1;
                kingdomOikos->b[kingdomOikos->ht->x3][kingdomOikos->ht->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->ht->x0][kingdomOikos->ht->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->ht->x1][kingdomOikos->ht->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->ht->x2][kingdomOikos->ht->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->ht->x3][kingdomOikos->ht->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->ht->x0][kingdomOikos->ht->y0] = 1;
                kingdomOikos->b[kingdomOikos->ht->x1][kingdomOikos->ht->y1] = 1;
                kingdomOikos->b[kingdomOikos->ht->x2][kingdomOikos->ht->y2] = 1;
                kingdomOikos->b[kingdomOikos->ht->x3][kingdomOikos->ht->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(kingdomOikos->choice == "larm") {

            kingdomOikos->larm->y0 += 20;
            kingdomOikos->larm->y1 += 20;
            kingdomOikos->larm->y2 += 20;
            kingdomOikos->larm->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->larm->x0, kingdomOikos->larm->y0, kingdomOikos->larm->x0 + 20, kingdomOikos->larm->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->larm->x1, kingdomOikos->larm->y1, kingdomOikos->larm->x1 + 20, kingdomOikos->larm->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->larm->x2, kingdomOikos->larm->y2, kingdomOikos->larm->x2 + 20, kingdomOikos->larm->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->larm->x3, kingdomOikos->larm->y3, kingdomOikos->larm->x3 + 20, kingdomOikos->larm->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->larm->y0 > 650 || kingdomOikos->larm->y1 > 650 || kingdomOikos->larm->y2 > 650 || kingdomOikos->larm->y3 > 650) {
                kingdomOikos->b[kingdomOikos->larm->x0][kingdomOikos->larm->y0] = 1;
                kingdomOikos->b[kingdomOikos->larm->x1][kingdomOikos->larm->y1] = 1;
                kingdomOikos->b[kingdomOikos->larm->x2][kingdomOikos->larm->y2] = 1;
                kingdomOikos->b[kingdomOikos->larm->x3][kingdomOikos->larm->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->larm->x0][kingdomOikos->larm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->larm->x1][kingdomOikos->larm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->larm->x2][kingdomOikos->larm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->larm->x3][kingdomOikos->larm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->larm->x0][kingdomOikos->larm->y0] = 1;
                kingdomOikos->b[kingdomOikos->larm->x1][kingdomOikos->larm->y1] = 1;
                kingdomOikos->b[kingdomOikos->larm->x2][kingdomOikos->larm->y2] = 1;
                kingdomOikos->b[kingdomOikos->larm->x3][kingdomOikos->larm->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(kingdomOikos->choice == "rarm") {

            kingdomOikos->rarm->y0 += 20;
            kingdomOikos->rarm->y1 += 20;
            kingdomOikos->rarm->y2 += 20;
            kingdomOikos->rarm->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->rarm->x0, kingdomOikos->rarm->y0, kingdomOikos->rarm->x0 + 20, kingdomOikos->rarm->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->rarm->x1, kingdomOikos->rarm->y1, kingdomOikos->rarm->x1 + 20, kingdomOikos->rarm->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->rarm->x2, kingdomOikos->rarm->y2, kingdomOikos->rarm->x2 + 20, kingdomOikos->rarm->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->rarm->x3, kingdomOikos->rarm->y3, kingdomOikos->rarm->x3 + 20, kingdomOikos->rarm->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->rarm->y0 > 650 || kingdomOikos->rarm->y1 > 650 || kingdomOikos->rarm->y2 > 650 || kingdomOikos->rarm->y3 > 650) {
                kingdomOikos->b[kingdomOikos->rarm->x0][kingdomOikos->rarm->y0] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x1][kingdomOikos->rarm->y1] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x2][kingdomOikos->rarm->y2] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x3][kingdomOikos->rarm->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->rarm->x0][kingdomOikos->rarm->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rarm->x1][kingdomOikos->rarm->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rarm->x2][kingdomOikos->rarm->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rarm->x3][kingdomOikos->rarm->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->rarm->x0][kingdomOikos->rarm->y0] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x1][kingdomOikos->rarm->y1] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x2][kingdomOikos->rarm->y2] = 1;
                kingdomOikos->b[kingdomOikos->rarm->x3][kingdomOikos->rarm->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(kingdomOikos->choice == "lsh") {

            kingdomOikos->lsh->y0 += 20;
            kingdomOikos->lsh->y1 += 20;
            kingdomOikos->lsh->y2 += 20;
            kingdomOikos->lsh->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->lsh->x0, kingdomOikos->lsh->y0, kingdomOikos->lsh->x0 + 20, kingdomOikos->lsh->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->lsh->x1, kingdomOikos->lsh->y1, kingdomOikos->lsh->x1 + 20, kingdomOikos->lsh->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->lsh->x2, kingdomOikos->lsh->y2, kingdomOikos->lsh->x2 + 20, kingdomOikos->lsh->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->lsh->x3, kingdomOikos->lsh->y3, kingdomOikos->lsh->x3 + 20, kingdomOikos->lsh->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->lsh->y0 > 650 || kingdomOikos->lsh->y1 > 650 || kingdomOikos->lsh->y2 > 650 || kingdomOikos->lsh->y3 > 650) {
                kingdomOikos->b[kingdomOikos->lsh->x0][kingdomOikos->lsh->y0] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x1][kingdomOikos->lsh->y1] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x2][kingdomOikos->lsh->y2] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x3][kingdomOikos->lsh->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->lsh->x0][kingdomOikos->lsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lsh->x1][kingdomOikos->lsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lsh->x2][kingdomOikos->lsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->lsh->x3][kingdomOikos->lsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->lsh->x0][kingdomOikos->lsh->y0] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x1][kingdomOikos->lsh->y1] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x2][kingdomOikos->lsh->y2] = 1;
                kingdomOikos->b[kingdomOikos->lsh->x3][kingdomOikos->lsh->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }
        }
        else if(kingdomOikos->choice == "rsh") {

            kingdomOikos->rsh->y0 += 20;
            kingdomOikos->rsh->y1 += 20;
            kingdomOikos->rsh->y2 += 20;
            kingdomOikos->rsh->y3 += 20;

            HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));

            RECT rrect3 = {kingdomOikos->rsh->x0, kingdomOikos->rsh->y0, kingdomOikos->rsh->x0 + 20, kingdomOikos->rsh->y0 + 20};
            FillRect(kingdomOikos->hdc2, &rrect3, brush);

            RECT rrect4 = {kingdomOikos->rsh->x1, kingdomOikos->rsh->y1, kingdomOikos->rsh->x1 + 20, kingdomOikos->rsh->y1 + 20};
            FillRect(kingdomOikos->hdc2, &rrect4, brush);

            RECT rrect5 = {kingdomOikos->rsh->x2, kingdomOikos->rsh->y2, kingdomOikos->rsh->x2 + 20, kingdomOikos->rsh->y2 + 20};
            FillRect(kingdomOikos->hdc2, &rrect5, brush);

            RECT rrect6 = {kingdomOikos->rsh->x3, kingdomOikos->rsh->y3, kingdomOikos->rsh->x3 + 20, kingdomOikos->rsh->y3 + 20};
            FillRect(kingdomOikos->hdc2, &rrect6, brush);
            DeleteObject(brush);

            if(kingdomOikos->rsh->y0 > 650 || kingdomOikos->rsh->y1 > 650 || kingdomOikos->rsh->y2 > 650 || kingdomOikos->rsh->y3 > 650) {
                kingdomOikos->b[kingdomOikos->rsh->x0][kingdomOikos->rsh->y0] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x1][kingdomOikos->rsh->y1] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x2][kingdomOikos->rsh->y2] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x3][kingdomOikos->rsh->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }

            BOOLEAN flag = FALSE;
            if(kingdomOikos->b[kingdomOikos->rsh->x0][kingdomOikos->rsh->y0+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rsh->x1][kingdomOikos->rsh->y1+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rsh->x2][kingdomOikos->rsh->y2+20] == 1) {
                flag = TRUE;
            }
            else if(kingdomOikos->b[kingdomOikos->rsh->x3][kingdomOikos->rsh->y3+20] == 1) {
                flag = TRUE;
            }
            if(flag) {
                kingdomOikos->b[kingdomOikos->rsh->x0][kingdomOikos->rsh->y0] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x1][kingdomOikos->rsh->y1] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x2][kingdomOikos->rsh->y2] = 1;
                kingdomOikos->b[kingdomOikos->rsh->x3][kingdomOikos->rsh->y3] = 1;
                kingdomOikos->blocks++;
                kingdomOikos->prep();
            }
            if(kingdomOikos->level < 40 && kingdomOikos->lines >= kingdomOikos->linenext) {kingdomOikos->level++;kingdomOikos->linenext+=10;kingdomOikos->sleeptime-=15;}
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }
        }
    }
    while(downIt);

    return 0;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    DeleteObject(kingdomOikos->hdc2);
    kingdomOikos->hdc2 = GetDC(hwnd);

    switch(msg) {
        
        case WM_KEYDOWN: 
            switch (wParam) 
            { 

        case VK_LEFT: 
            if(kingdomOikos->choice == "ht")
                kingdomOikos->ht->goLeft();
            else if(kingdomOikos->choice == "lne")
                kingdomOikos->lne->goLeft();
            else if(kingdomOikos->choice == "sq")
                kingdomOikos->sq->goLeft();
            else if(kingdomOikos->choice == "lsh")
                kingdomOikos->lsh->goLeft();
            else if(kingdomOikos->choice == "rsh")
                kingdomOikos->rsh->goLeft();
            else if(kingdomOikos->choice == "larm")
                kingdomOikos->larm->goLeft();
            else if(kingdomOikos->choice == "rarm")
                kingdomOikos->rarm->goLeft();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }

            break;

        case VK_RIGHT:
            if(kingdomOikos->choice == "ht")
                kingdomOikos->ht->goRight();
            else if(kingdomOikos->choice == "lne")
                kingdomOikos->lne->goRight();
            else if(kingdomOikos->choice == "sq")
                kingdomOikos->sq->goRight();
            else if(kingdomOikos->choice == "lsh")
                kingdomOikos->lsh->goRight();
            else if(kingdomOikos->choice == "rsh")
                kingdomOikos->rsh->goRight();
            else if(kingdomOikos->choice == "larm")
                kingdomOikos->larm->goRight();
            else if(kingdomOikos->choice == "rarm")
                kingdomOikos->rarm->goRight();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }

            break; 

        case VK_UP:
            if(kingdomOikos->choice == "sq")
                kingdomOikos->sq->rotate();
            else if(kingdomOikos->choice == "lne")
                kingdomOikos->lne->rotate();
            else if(kingdomOikos->choice == "ht")
                kingdomOikos->ht->rotate();
            else if(kingdomOikos->choice == "lsh")
                kingdomOikos->lsh->rotate();
            else if(kingdomOikos->choice == "rsh")
                kingdomOikos->rsh->rotate();
            else if(kingdomOikos->choice == "larm")
                kingdomOikos->larm->rotate();
            else if(kingdomOikos->choice == "rarm")
                kingdomOikos->rarm->rotate();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }

            break;

        case VK_DOWN:
            if(kingdomOikos->choice == "sq")
                kingdomOikos->sq->goDown();
            else if(kingdomOikos->choice == "ht")
                kingdomOikos->ht->goDown();
            else if(kingdomOikos->choice == "lne")
                kingdomOikos->lne->goDown();
            else if(kingdomOikos->choice == "lsh")
                kingdomOikos->lsh->goDown();
            else if(kingdomOikos->choice == "rsh")
                kingdomOikos->rsh->goDown();
            else if(kingdomOikos->choice == "larm")
                kingdomOikos->larm->goDown();
            else if(kingdomOikos->choice == "rarm")
                kingdomOikos->rarm->goDown();
            for(int i=0; i<700; i++) {
                for(int j=0; j<700; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);

                        HGDIOBJ hOldBsh = SelectObject(kingdomOikos->hdc2, GetStockObject(NULL_BRUSH));
                        HGDIOBJ hOldPen = SelectObject(kingdomOikos->hdc2, CreatePen(PS_SOLID, 1, RGB(200, 10, 5)));
                        Rectangle(kingdomOikos->hdc2, i, j, i + 20, j + 20);
                        DeleteObject(SelectObject(kingdomOikos->hdc2, hOldPen));
                        SelectObject(kingdomOikos->hdc2, hOldBsh);
                    }
                }
            }

            HPEN hPenOld;
            HPEN hLinePen;
            COLORREF qLineColor;
            qLineColor = RGB(248, 0, 79);
            hLinePen = CreatePen(PS_SOLID, 6, qLineColor);
            hPenOld = (HPEN)SelectObject(kingdomOikos->hdc2, hLinePen);
            if(kingdomOikos->choice == "sq") {
                if (kingdomOikos->sq->y0 >= kingdomOikos->sq->y1 &&
                        kingdomOikos->sq->y0 >= kingdomOikos->sq->y2 &&
                        kingdomOikos->sq->y0 >= kingdomOikos->sq->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->sq->y0+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->sq->y0+20);
                }
                else if (kingdomOikos->sq->y1 >= kingdomOikos->sq->y0 &&
                        kingdomOikos->sq->y1 >= kingdomOikos->sq->y1 &&
                        kingdomOikos->sq->y1 >= kingdomOikos->sq->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->sq->y1+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->sq->y1+20);
                }
                else if (kingdomOikos->sq->y2 >= kingdomOikos->sq->y0 &&
                        kingdomOikos->sq->y2 >= kingdomOikos->sq->y1 &&
                        kingdomOikos->sq->y2 >= kingdomOikos->sq->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->sq->y2+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->sq->y2+20);
                }
                else if (kingdomOikos->sq->y3 >= kingdomOikos->sq->y0 &&
                        kingdomOikos->sq->y3 >= kingdomOikos->sq->y1 &&
                        kingdomOikos->sq->y3 >= kingdomOikos->sq->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->sq->y3+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->sq->y3+20);
                }

                if (kingdomOikos->sq->y0 <= kingdomOikos->sq->y1 &&
                        kingdomOikos->sq->y0 <= kingdomOikos->sq->y2 &&
                        kingdomOikos->sq->y0 <= kingdomOikos->sq->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->sq->y0, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->sq->y0);
                }
                else if (kingdomOikos->sq->y1 <= kingdomOikos->sq->y0 &&
                        kingdomOikos->sq->y1 <= kingdomOikos->sq->y1 &&
                        kingdomOikos->sq->y1 <= kingdomOikos->sq->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->sq->y1, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->sq->y1);
                }
                else if (kingdomOikos->sq->y2 <= kingdomOikos->sq->y0 &&
                        kingdomOikos->sq->y2 <= kingdomOikos->sq->y1 &&
                        kingdomOikos->sq->y2 <= kingdomOikos->sq->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->sq->y2, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->sq->y2);
                }
                else if (kingdomOikos->sq->y3 <= kingdomOikos->sq->y0 &&
                        kingdomOikos->sq->y3 <= kingdomOikos->sq->y1 &&
                        kingdomOikos->sq->y3 <= kingdomOikos->sq->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->sq->y3, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->sq->y3);
                }
            }

            if(kingdomOikos->choice == "lne") {
                if (kingdomOikos->lne->y0 >= kingdomOikos->lne->y1 &&
                        kingdomOikos->lne->y0 >= kingdomOikos->lne->y2 &&
                        kingdomOikos->lne->y0 >= kingdomOikos->lne->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lne->y0+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lne->y0+20);
                }
                else if (kingdomOikos->lne->y1 >= kingdomOikos->lne->y0 &&
                        kingdomOikos->lne->y1 >= kingdomOikos->lne->y1 &&
                        kingdomOikos->lne->y1 >= kingdomOikos->lne->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lne->y1+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lne->y1+20);
                }
                else if (kingdomOikos->lne->y2 >= kingdomOikos->lne->y0 &&
                        kingdomOikos->lne->y2 >= kingdomOikos->lne->y1 &&
                        kingdomOikos->lne->y2 >= kingdomOikos->lne->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lne->y2+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lne->y2+20);
                }
                else if (kingdomOikos->lne->y3 >= kingdomOikos->lne->y0 &&
                        kingdomOikos->lne->y3 >= kingdomOikos->lne->y1 &&
                        kingdomOikos->lne->y3 >= kingdomOikos->lne->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lne->y3+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lne->y3+20);
                }

                if (kingdomOikos->lne->y0 <= kingdomOikos->lne->y1 &&
                        kingdomOikos->lne->y0 <= kingdomOikos->lne->y2 &&
                        kingdomOikos->lne->y0 <= kingdomOikos->lne->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lne->y0, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lne->y0);
                }
                else if (kingdomOikos->lne->y1 <= kingdomOikos->lne->y0 &&
                        kingdomOikos->lne->y1 <= kingdomOikos->lne->y1 &&
                        kingdomOikos->lne->y1 <= kingdomOikos->lne->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lne->y1, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lne->y1);
                }
                else if (kingdomOikos->lne->y2 <= kingdomOikos->lne->y0 &&
                        kingdomOikos->lne->y2 <= kingdomOikos->lne->y1 &&
                        kingdomOikos->lne->y2 <= kingdomOikos->lne->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lne->y2, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lne->y2);
                }
                else if (kingdomOikos->lne->y3 <= kingdomOikos->lne->y0 &&
                        kingdomOikos->lne->y3 <= kingdomOikos->lne->y1 &&
                        kingdomOikos->lne->y3 <= kingdomOikos->lne->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lne->y3, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lne->y3);
                }
            }

            if(kingdomOikos->choice == "rarm") {
                if(kingdomOikos->rarm->dir == 1) {
                    if (kingdomOikos->rarm->y0 >= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y0 >= kingdomOikos->rarm->y2 &&
                            kingdomOikos->rarm->y0 >= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y0+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y0+40);
                    }
                    else if (kingdomOikos->rarm->y1 >= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y1 >= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y1 >= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y1+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y1+40);
                    }
                    else if (kingdomOikos->rarm->y2 >= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y2 >= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y2 >= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y2+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y2+40);
                    }
                    else if (kingdomOikos->rarm->y3 >= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y3 >= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y3 >= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y3+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y3+40);
                    }
                } else {
                    if (kingdomOikos->rarm->y0 >= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y0 >= kingdomOikos->rarm->y2 &&
                            kingdomOikos->rarm->y0 >= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y0+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y0+20);
                    }
                    else if (kingdomOikos->rarm->y1 >= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y1 >= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y1 >= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y1+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y1+20);
                    }
                    else if (kingdomOikos->rarm->y2 >= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y2 >= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y2 >= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y2+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y2+20);
                    }
                    else if (kingdomOikos->rarm->y3 >= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y3 >= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y3 >= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y3+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y3+20);
                    }
                }

                if(kingdomOikos->rarm->dir == 0) {
                    if (kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y2 &&
                            kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y0);
                    }
                    else if (kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y1-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y1-0);
                    }
                    else if (kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y2, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y2);
                    }
                    else if (kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y3, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y3);
                    }
                } else if(kingdomOikos->rarm->dir == 1) {
                    if (kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y2 &&
                            kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y0+0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y0+0);
                    }
                    else if (kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y1, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y1);
                    }
                    else if (kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y2+0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y2+0);
                    }
                    else if (kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y3, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y3);
                    }
                } else if(kingdomOikos->rarm->dir == 2) {
                    if (kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y2 &&
                            kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y0-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y0-0);
                    }
                    else if (kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y1-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y1-0);
                    }
                    else if (kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y2-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y2-0);
                    }
                    else if (kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y3-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y3-0);
                    }
                } else {
                    if (kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y2 &&
                            kingdomOikos->rarm->y0 <= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y0-20+0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y0-20+0);
                    }
                    else if (kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y1 <= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y1-20+0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y1-20+0);
                    }
                    else if (kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y2 <= kingdomOikos->rarm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y2+0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y2+0);
                    }
                    else if (kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y0 &&
                            kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y1 &&
                            kingdomOikos->rarm->y3 <= kingdomOikos->rarm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rarm->y3+0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rarm->y3+0);
                    }
                }
            }

            if(kingdomOikos->choice == "larm") {
                if(kingdomOikos->larm->dir == 3) {
                    if (kingdomOikos->larm->y0 >= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y0 >= kingdomOikos->larm->y2 &&
                            kingdomOikos->larm->y0 >= kingdomOikos->larm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y0+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y0+40);
                    }
                    else if (kingdomOikos->larm->y1 >= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y1 >= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y1 >= kingdomOikos->larm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y1+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y1+40);
                    }
                    else if (kingdomOikos->larm->y2 >= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y2 >= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y2 >= kingdomOikos->larm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y2+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y2+40);
                    }
                    else if (kingdomOikos->larm->y3 >= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y3 >= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y3 >= kingdomOikos->larm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y3+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y3+40);
                    }
                } else {
                    if (kingdomOikos->larm->y0 >= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y0 >= kingdomOikos->larm->y2 &&
                            kingdomOikos->larm->y0 >= kingdomOikos->larm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y0+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y0+20);
                    }
                    else if (kingdomOikos->larm->y1 >= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y1 >= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y1 >= kingdomOikos->larm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y1+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y1+20);
                    }
                    else if (kingdomOikos->larm->y2 >= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y2 >= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y2 >= kingdomOikos->larm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y2+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y2+20);
                    }
                    else if (kingdomOikos->larm->y3 >= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y3 >= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y3 >= kingdomOikos->larm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y3+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y3+20);
                    }
                }

                if(kingdomOikos->larm->dir == 0) {
                    if (kingdomOikos->larm->y0 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y0 <= kingdomOikos->larm->y2 &&
                            kingdomOikos->larm->y0 <= kingdomOikos->larm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y0);
                    }
                    else if (kingdomOikos->larm->y1 <= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y1 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y1 <= kingdomOikos->larm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y1-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y1-0);
                    }
                    else if (kingdomOikos->larm->y2 <= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y2 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y2 <= kingdomOikos->larm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y2, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y2);
                    }
                    else if (kingdomOikos->larm->y3 <= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y3 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y3 <= kingdomOikos->larm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y3, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y3);
                    }
                } else if(kingdomOikos->larm->dir == 3) {
                    if (kingdomOikos->larm->y0 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y0 <= kingdomOikos->larm->y2 &&
                            kingdomOikos->larm->y0 <= kingdomOikos->larm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y0);
                    }
                    else if (kingdomOikos->larm->y1 <= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y1 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y1 <= kingdomOikos->larm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y1, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y1);
                    }
                    else if (kingdomOikos->larm->y2 <= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y2 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y2 <= kingdomOikos->larm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y2, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y2);
                    }
                    else if (kingdomOikos->larm->y3 <= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y3 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y3 <= kingdomOikos->larm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y3, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y3);
                    }
                } else {
                    if (kingdomOikos->larm->y0 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y0 <= kingdomOikos->larm->y2 &&
                            kingdomOikos->larm->y0 <= kingdomOikos->larm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y0-20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y0-20);
                    }
                    else if (kingdomOikos->larm->y1 <= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y1 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y1 <= kingdomOikos->larm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y1-20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y1-20);
                    }
                    else if (kingdomOikos->larm->y2 <= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y2 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y2 <= kingdomOikos->larm->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y2, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y2);
                    }
                    else if (kingdomOikos->larm->y3 <= kingdomOikos->larm->y0 &&
                            kingdomOikos->larm->y3 <= kingdomOikos->larm->y1 &&
                            kingdomOikos->larm->y3 <= kingdomOikos->larm->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->larm->y3, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->larm->y3);
                    }
                }
            }

            if(kingdomOikos->choice == "ht") {
                if (kingdomOikos->ht->y0 >= kingdomOikos->ht->y1 &&
                        kingdomOikos->ht->y0 >= kingdomOikos->ht->y2 &&
                        kingdomOikos->ht->y0 >= kingdomOikos->ht->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->ht->y0+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->ht->y0+20);
                }
                else if (kingdomOikos->ht->y1 >= kingdomOikos->ht->y0 &&
                        kingdomOikos->ht->y1 >= kingdomOikos->ht->y1 &&
                        kingdomOikos->ht->y1 >= kingdomOikos->ht->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->ht->y1+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->ht->y1+20);
                }
                else if (kingdomOikos->ht->y2 >= kingdomOikos->ht->y0 &&
                        kingdomOikos->ht->y2 >= kingdomOikos->ht->y1 &&
                        kingdomOikos->ht->y2 >= kingdomOikos->ht->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->ht->y2+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->ht->y2+20);
                }
                else if (kingdomOikos->ht->y3 >= kingdomOikos->ht->y0 &&
                        kingdomOikos->ht->y3 >= kingdomOikos->ht->y1 &&
                        kingdomOikos->ht->y3 >= kingdomOikos->ht->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->ht->y3+20, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->ht->y3+20);
                }

                if (kingdomOikos->ht->y0 <= kingdomOikos->ht->y1 &&
                        kingdomOikos->ht->y0 <= kingdomOikos->ht->y2 &&
                        kingdomOikos->ht->y0 <= kingdomOikos->ht->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->ht->y0, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->ht->y0);
                }
                else if (kingdomOikos->ht->y1 <= kingdomOikos->ht->y0 &&
                        kingdomOikos->ht->y1 <= kingdomOikos->ht->y1 &&
                        kingdomOikos->ht->y1 <= kingdomOikos->ht->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->ht->y1, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->ht->y1);
                }
                else if (kingdomOikos->ht->y2 <= kingdomOikos->ht->y0 &&
                        kingdomOikos->ht->y2 <= kingdomOikos->ht->y1 &&
                        kingdomOikos->ht->y2 <= kingdomOikos->ht->y3) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->ht->y2, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->ht->y2);
                }
                else if (kingdomOikos->ht->y3 <= kingdomOikos->ht->y0 &&
                        kingdomOikos->ht->y3 <= kingdomOikos->ht->y1 &&
                        kingdomOikos->ht->y3 <= kingdomOikos->ht->y2) {
                    MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->ht->y3, NULL);
                    LineTo(kingdomOikos->hdc2, 415, kingdomOikos->ht->y3);
                }
            }

            if(kingdomOikos->choice == "lsh") {
                if(kingdomOikos->lsh->dir == 0) {
                    if (kingdomOikos->lsh->y0 >= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y0 >= kingdomOikos->lsh->y2 &&
                            kingdomOikos->lsh->y0 >= kingdomOikos->lsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y0+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y0+40);
                    }
                    else if (kingdomOikos->lsh->y1 >= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y1 >= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y1 >= kingdomOikos->lsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y1+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y1+40);
                    }
                    else if (kingdomOikos->lsh->y2 >= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y2 >= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y2 >= kingdomOikos->lsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y2+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y2+40);
                    }
                    else if (kingdomOikos->lsh->y3 >= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y3 >= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y3 >= kingdomOikos->lsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y3+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y3+40);
                    }
                } else {
                    if (kingdomOikos->lsh->y0 >= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y0 >= kingdomOikos->lsh->y2 &&
                            kingdomOikos->lsh->y0 >= kingdomOikos->lsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y0+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y0+20);
                    }
                    else if (kingdomOikos->lsh->y1 >= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y1 >= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y1 >= kingdomOikos->lsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y1+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y1+20);
                    }
                    else if (kingdomOikos->lsh->y2 >= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y2 >= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y2 >= kingdomOikos->lsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y2+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y2+20);
                    }
                    else if (kingdomOikos->lsh->y3 >= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y3 >= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y3 >= kingdomOikos->lsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y3+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y3+20);
                    }
                }

                if(kingdomOikos->lsh->dir == 3) {
                    if (kingdomOikos->lsh->y0 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y0 <= kingdomOikos->lsh->y2 &&
                            kingdomOikos->lsh->y0 <= kingdomOikos->lsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y0-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y0-0);
                    }
                    else if (kingdomOikos->lsh->y1 <= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y1 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y1 <= kingdomOikos->lsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y1-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y1-0);
                    }
                    else if (kingdomOikos->lsh->y2 <= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y2 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y2 <= kingdomOikos->lsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y2-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y2-0);
                    }
                    else if (kingdomOikos->lsh->y3 <= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y3 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y3 <= kingdomOikos->lsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y3-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y3-0);
                    }
                } else if(kingdomOikos->lsh->dir == 2) {
                    if (kingdomOikos->lsh->y0 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y0 <= kingdomOikos->lsh->y2 &&
                            kingdomOikos->lsh->y0 <= kingdomOikos->lsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y0-20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y0-20);
                    }
                    else if (kingdomOikos->lsh->y1 <= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y1 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y1 <= kingdomOikos->lsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y1-20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y1-20);
                    }
                    else if (kingdomOikos->lsh->y2 <= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y2 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y2 <= kingdomOikos->lsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y2-20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y2-20);
                    }
                    else if (kingdomOikos->lsh->y3 <= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y3 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y3 <= kingdomOikos->lsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y3-20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y3-20);
                    }
                } else {
                    if (kingdomOikos->lsh->y0 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y0 <= kingdomOikos->lsh->y2 &&
                            kingdomOikos->lsh->y0 <= kingdomOikos->lsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y0);
                    }
                    else if (kingdomOikos->lsh->y1 <= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y1 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y1 <= kingdomOikos->lsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y1, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y1);
                    }
                    else if (kingdomOikos->lsh->y2 <= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y2 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y2 <= kingdomOikos->lsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y2, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y2);
                    }
                    else if (kingdomOikos->lsh->y3 <= kingdomOikos->lsh->y0 &&
                            kingdomOikos->lsh->y3 <= kingdomOikos->lsh->y1 &&
                            kingdomOikos->lsh->y3 <= kingdomOikos->lsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->lsh->y3, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->lsh->y3);
                    }
                }
            }

            if(kingdomOikos->choice == "rsh") {
                if(kingdomOikos->rsh->dir == 0) {
                    if (kingdomOikos->rsh->y0 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y0 >= kingdomOikos->rsh->y2 &&
                            kingdomOikos->rsh->y0 >= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y0+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y0+40);
                    }
                    else if (kingdomOikos->rsh->y1 >= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y1 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y1 >= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y1+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y1+40);
                    }
                    else if (kingdomOikos->rsh->y2 >= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y2 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y2 >= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y2+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y2+40);
                    }
                    else if (kingdomOikos->rsh->y3 >= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y3 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y3 >= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y3+40, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y3+40);
                    }
                } else if(kingdomOikos->rsh->dir == 2) {
                    if (kingdomOikos->rsh->y0 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y0 >= kingdomOikos->rsh->y2 &&
                            kingdomOikos->rsh->y0 >= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y0+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y0+20);
                    }
                    else if (kingdomOikos->rsh->y1 >= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y1 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y1 >= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y1+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y1+20);
                    }
                    else if (kingdomOikos->rsh->y2 >= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y2 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y2 >= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y2+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y2+20);
                    }
                    else if (kingdomOikos->rsh->y3 >= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y3 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y3 >= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y3+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y3+20);
                    }
                } else {
                    if (kingdomOikos->rsh->y0 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y0 >= kingdomOikos->rsh->y2 &&
                            kingdomOikos->rsh->y0 >= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y0+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y0+20);
                    }
                    else if (kingdomOikos->rsh->y1 >= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y1 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y1 >= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y1+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y1+20);
                    }
                    else if (kingdomOikos->rsh->y2 >= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y2 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y2 >= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y2+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y2+20);
                    }
                    else if (kingdomOikos->rsh->y3 >= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y3 >= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y3 >= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y3+20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y3+20);
                    }
                }

                if(kingdomOikos->rsh->dir == 0) {
                    if (kingdomOikos->rsh->y0 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y0 <= kingdomOikos->rsh->y2 &&
                            kingdomOikos->rsh->y0 <= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y0-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y0-0);
                    }
                    else if (kingdomOikos->rsh->y1 <= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y1 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y1 <= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y1-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y1-0);
                    }
                    else if (kingdomOikos->rsh->y2 <= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y2 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y2 <= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y2-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y2-0);
                    }
                    else if (kingdomOikos->rsh->y3 <= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y3 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y3 <= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y3-0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y3-0);
                    }
                } else if(kingdomOikos->rsh->dir == 2) {
                    if (kingdomOikos->rsh->y0 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y0 <= kingdomOikos->rsh->y2 &&
                            kingdomOikos->rsh->y0 <= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y0-20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y0-20);
                    }
                    else if (kingdomOikos->rsh->y1 <= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y1 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y1 <= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y1-20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y1-20);
                    }
                    else if (kingdomOikos->rsh->y2 <= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y2 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y2 <= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y2-20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y2-20);
                    }
                    else if (kingdomOikos->rsh->y3 <= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y3 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y3 <= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y3-20, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y3-20);
                    }
                } else {
                    if (kingdomOikos->rsh->y0 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y0 <= kingdomOikos->rsh->y2 &&
                            kingdomOikos->rsh->y0 <= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y0, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y0);
                    }
                    else if (kingdomOikos->rsh->y1 <= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y1 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y1 <= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y1, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y1);
                    }
                    else if (kingdomOikos->rsh->y2 <= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y2 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y2 <= kingdomOikos->rsh->y3) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y2, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y2);
                    }
                    else if (kingdomOikos->rsh->y3 <= kingdomOikos->rsh->y0 &&
                            kingdomOikos->rsh->y3 <= kingdomOikos->rsh->y1 &&
                            kingdomOikos->rsh->y3 <= kingdomOikos->rsh->y2) {
                        MoveToEx(kingdomOikos->hdc2, 224, kingdomOikos->rsh->y3, NULL);
                        LineTo(kingdomOikos->hdc2, 415, kingdomOikos->rsh->y3);
                    }
                }
            }

            SelectObject(kingdomOikos->hdc2, hPenOld);
            DeleteObject(hLinePen);
            break;
        }
        case WM_PAINT:
        {
            if(kingdomOikos->fist) {

                HBRUSH brush79 = CreateSolidBrush(RGB(106, 140, 191));
                RECT rrect79 = {0, 0, 22640, 22750};
                FillRect(kingdomOikos->hdc2, &rrect79, brush79);
                DeleteObject(brush79);
                HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
                RECT rrect = {0, 0, 640, 750};
                FillRect(kingdomOikos->hdc2, &rrect, brush);
                DeleteObject(brush);
                HBRUSH brush0 = CreateSolidBrush(RGB(0, 244, 30));
                RECT rrect9 = {199, 0, 440, 710};
                FillRect(kingdomOikos->hdc2, &rrect9, brush0);
                DeleteObject(brush0);
                HBRUSH brush2 = CreateSolidBrush(RGB(255, 200, 112));
                RECT rrect3 = {209, 10, 430, 700};
                FillRect(kingdomOikos->hdc2, &rrect3, brush2);
                DeleteObject(brush2);

                kingdomOikos->threa = CreateThread(0, 0, downs, 0, 0, NULL);
                srand(time(NULL));
                kingdomOikos->prep();
            }

            for(int i=0; i<700; i++) {
                for(int j=0; j<720; j++) {
                    if(kingdomOikos->b[i][j] == 1) {
                        HBRUSH brush = CreateSolidBrush(RGB(200, 10, 5));
                        RECT rrect6 = {i, j, i + 20, j + 20};
                        FillRect(kingdomOikos->hdc2, &rrect6, brush);
                        DeleteObject(brush);
                    }
                }
            }

            PAINTSTRUCT ps;
            HDC hdc = BeginPaint (hwnd, &ps);

            HFONT font;

            font = CreateFont(16, 0, 0, 0,
                              FW_BOLD, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            char aa[16];sprintf(aa,"LEbEL: %d of 40",kingdomOikos->level);

            SelectObject(kingdomOikos->hdc2, font);
            TextOut(kingdomOikos->hdc2, 450, 20, aa, 15);
            TextOut(kingdomOikos->hdc2, 0, 240, "PREVIEW", 7);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            HBRUSH brush1 = CreateSolidBrush(RGB(2, 249, 0));
            RECT rrect1 = {40, 310, 150, 420};
            FillRect(kingdomOikos->hdc2, &rrect1, brush1);
            DeleteObject(brush1);

            char dd[16];sprintf(dd,"LeBel: %d", kingdomOikos->level);

            SelectObject(kingdomOikos->hdc2, font);
            TextOut(kingdomOikos->hdc2, 50, 320, dd, 9);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            char cc[16];sprintf(cc,"Blocks: %d", kingdomOikos->blocks);

            SelectObject(kingdomOikos->hdc2, font);
            if(kingdomOikos->blocks < 10)
                TextOut(kingdomOikos->hdc2, 50, 340, cc, 9);
            else if(kingdomOikos->blocks > 9 && kingdomOikos->blocks < 100)
                TextOut(kingdomOikos->hdc2, 50, 340, cc, 10);
            else if(kingdomOikos->blocks > 99 && kingdomOikos->blocks < 1000)
                TextOut(kingdomOikos->hdc2, 50, 340, cc, 11);
            else if(kingdomOikos->blocks > 999 && kingdomOikos->blocks < 10000)
                TextOut(kingdomOikos->hdc2, 50, 340, cc, 12);
            else
                TextOut(kingdomOikos->hdc2, 50, 340, cc, 13);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            char bb[16];sprintf(bb,"Lines: %d", kingdomOikos->lines);

            SelectObject(kingdomOikos->hdc2, font);
            if(kingdomOikos->lines < 10)
                TextOut(kingdomOikos->hdc2, 50, 360, bb, 8);
            else if(kingdomOikos->lines > 9 && kingdomOikos->lines < 100)
                TextOut(kingdomOikos->hdc2, 50, 360, bb, 9);
            else if(kingdomOikos->lines > 99 && kingdomOikos->lines < 1000)
                TextOut(kingdomOikos->hdc2, 50, 360, bb, 10);
            else if(kingdomOikos->lines > 999 && kingdomOikos->lines < 10000)
                TextOut(kingdomOikos->hdc2, 50, 360, bb, 11);
            else
                TextOut(kingdomOikos->hdc2, 50, 360, bb, 12);
            DeleteObject(font);

            font = CreateFont(26, 0, 0, 0,
                              FW_NORMAL, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Helvetica");

            SelectObject(kingdomOikos->hdc2, font);
            TextOut(kingdomOikos->hdc2, 450, 480, "SaeNooRi", 8);
            DeleteObject(font);

            font = CreateFont(16, 0, 0, 0,
                              FW_BOLD, FALSE, FALSE, FALSE,
                              ANSI_CHARSET, OUT_DEFAULT_PRECIS,
                            CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                            DEFAULT_PITCH | FF_ROMAN,
                           "Verdana");

            SelectObject(kingdomOikos->hdc2, font);
            TextOut(kingdomOikos->hdc2, 10, 640, "By OkelyKodely", 14);
            SelectObject(kingdomOikos->hdc2, font);
            TextOut(kingdomOikos->hdc2, 10, 680, "PASTOR MADE THIS!!", 12);
            DeleteObject(font);
            
            EndPaint (hwnd, &ps);
        }
        break;
        case WM_CREATE:
        {
            int y = 600; int h = 48;
            int x = 443; int w = 124;
  	    kingdomOikos->hwnd_new_game = CreateWindowEx(0, "BUTTON", "Turn Music On", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
								x, y, w, h, hwnd, (HMENU) PLAY_AGAIN_BUTTON, GetModuleHandle(NULL), NULL);
        }
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case PLAY_AGAIN_BUTTON:
                    if (HIWORD(wParam) == BN_CLICKED) {
                        if(!kingdomOikos->dontplay) {
                            SetWindowText(kingdomOikos->hwnd_new_game, "Turn Music On");
                            PlaySound(NULL,NULL,0);
                        } else {
                            SetWindowText(kingdomOikos->hwnd_new_game, "Turn Music Off");
                            PlaySound(TEXT("mario.wav"), NULL, SND_LOOP | SND_ASYNC);
                        }
                        kingdomOikos->dontplay = !kingdomOikos->dontplay;
                    }
                    SetFocus(hwnd);
                break;
            }
        break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        
        return 0;
    }

    hwnd = CreateWindow(g_szClassName, NULL, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), NULL, NULL, hInstance, NULL);

    if(hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        
        return 0;
    }

    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    
    SetWindowText(hwnd, "SaeNooRi Baptist Church = Oikos EM Group");

    while(GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    
    return Msg.wParam;
}