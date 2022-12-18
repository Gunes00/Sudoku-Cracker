#include <stdio.h>
#include <stdbool.h>

// 9x9'luk bir tahta oluşturur
int tahta[9][9];

//Satır ve sütunda, verilen rakam zaten var mı kontrol eder
bool satirsutunkontrol(int satir, int sutun, int sayi)
{
    for (int i = 0; i < 9; i++)
        if (tahta[satir][i] == sayi || tahta[i][sutun] == sayi)
            return true;
    return false;
}

//3x3'lük kutuları kontrol eder
bool kutukontrol(int satirbas, int sutunbas, int sayi)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tahta[i + satirbas][j + sutunbas] == sayi)
                return true;
    return false;
}

//rakamı yerleştirebilir miyiz kontrol eder
bool kontrol(int satir, int sutun, int sayi)
{
    return !satirsutunkontrol(satir, sutun, sayi) && !kutukontrol(satir - satir % 3, sutun - sutun % 3, sayi);
}

//Boş bir hücre var mı kontrol eder
bool bosvarmi(int *satir, int *sutun)
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (tahta[i][j] == 0)
            {
                *satir = i;
                *sutun = j;
                return true;
            }
    return false;
}

// Çözümü var mı kontrol eder
bool cozum()
{
    int satir, sutun;

       if (!bosvarmi(&satir, &sutun))
        return true;

    for (int sayi = 1; sayi <= 9; sayi++)
    {
        if (kontrol(satir, sutun, sayi))
        {
            tahta[satir][sutun] = sayi;

            if (cozum())
                return true;

            tahta[satir][sutun] = 0;
        }
    }
    return false;
}

//Rakamları yazdırır
void tahtayazdir()
{
    for (int satir = 0; satir < 9; satir++)
    {
        for (int sutun = 0; sutun < 9; sutun++)
            printf("%2d", tahta[satir][sutun]);
        printf("\n");
    }
}

int main()
{
    // Yerleştirin 
    int ornek[9][9] = {{0, 8, 0, 1, 0, 0, 0, 2, 0},
                         {0, 0, 0, 9, 0, 0, 0, 5, 0},
                         {9, 7, 2, 0, 0, 0, 0, 6, 0},
                         {4, 0, 0, 0, 2, 6, 0, 0, 0},
                         {0, 0, 0, 0, 5, 0, 7, 0, 0},
                         {8, 0, 1, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 6, 9, 5, 0, 0, 0},
                         {0, 2, 5, 0, 0, 0, 0, 0, 9},
                         {0, 0, 0, 0, 4, 0, 0, 0, 1}};

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            tahta[i][j] = ornek[i][j];

    if (cozum())
        tahtayazdir();
    else
        printf("Çözüm bulunamadı.\n");

    return 0;
}
