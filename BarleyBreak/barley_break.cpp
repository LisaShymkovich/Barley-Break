#include "barley_break.h"
#include <QRandomGenerator>
#include <Qvector>


Barley_Break::Barley_Break()
{
    startGame();
}

void Barley_Break ::startGame()
{
    QRandomGenerator *rnd = QRandomGenerator::global();
    do
    {
        unsigned limit = 16;
        QVector <int> temp ;
        for (unsigned i = 1; i < limit; i++)
            temp.push_back(i);
        int value;
        for (unsigned i = 0; i < 4; i++)
        {
            for (unsigned j = 0; j < 4; j++)
            {
                if(i == 3 && j == 3)
                {
                    break;
                }
                value = rnd->bounded(--limit);
                table[i][j] = temp[value];
                temp.erase(temp.begin() + value);
                copytable[i][j]= table[i][j];
            }
        }
        emptyR = 3;
        emptyC = 3;
        movesNumber = 0;
        table[3][3] = 0;
        copytable[3][3] = 0;
    } while(isFinished() || !checkGame());
}

void Barley_Break::restartGame()
{
    for (auto i=0; i<4; i++)
        for(auto j=0; j<4; j++)
        {
            table[i][j]= copytable[i][j];
        }
    emptyR = 3;
    emptyC = 3;
    movesNumber = 0;
}

void Barley_Break::setItem(int r, int c, int val)
{
    table[r][c] = val;
}

void Barley_Break::setEmptyItem(int r, int c)
{
    table[r][c] = 16;
    emptyR = r;
    emptyC = c;
}


void Barley_Break::setMovesNumber(int num)
{
    movesNumber = num;
}

int Barley_Break::getItem(int i, int j) const
{
    return table[i][j];
}


int Barley_Break::getEmptyR() const
{
    return emptyR;
}


int Barley_Break::getEmptyC() const
{
    return emptyC;
}

int Barley_Break::getMovesNumber() const
{
    return movesNumber;
}


void Barley_Break::reCalc(int r, int c)
{
    int moveDistance = abs(r - emptyR) + abs(c - emptyC);
    if(r < 4 && r >= 0 && c < 4 && c >= 0)
    {
        if(moveDistance == 1)
        {
            setItem(emptyR,emptyC,getItem(r,c));
            setEmptyItem(r,c);
            int n=getMovesNumber();
            n++;
            setMovesNumber(n);
        }
    }
}

bool Barley_Break::checkGame()
{
    int sum=0;
    QVector <int> mas ;
    for (auto i=0; i<4; i++)
        for(auto j=0; j<4; j++)
        {
            mas.push_back(table[i][j]);
        }
    for (int i = 0; i < 15; i++)
    {
        for (int j=0; j< 15 - i; j++)
        {
            if (mas[j] > mas[j + 1])
            {
                sum++;
            }
        }
    }
    int emptyR=getEmptyR();
    sum+=emptyR;
    if (sum%2==0) return true;
    else return false;
}

bool Barley_Break::isFinished()
{
    int k=1;
    for (int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if (table[i][j]==0 && k==16)
            {
                return true;
            }

            if (table[i][j]!=k)
            {
                return false;
            }
            k++;
        }
    }
    return true;
}
