#ifndef BARLEY_BREAK_H
#define BARLEY_BREAK_H


class Barley_Break
{
public:
    Barley_Break();
    void startGame();
    void restartGame();
    bool isFinished();
    bool checkGame();
    void reCalc(int i, int j);// строка r столбец c
    void setItem(int i, int j, int val);
    void setEmptyItem(int r, int c);
    void setMovesNumber(int num);
    int getItem(int i, int j) const;
    int getEmptyR() const;
    int getEmptyC() const;
    int getMovesNumber() const;
private:
    int table [4][4];
    int copytable [4][4];
    int emptyR;
    int emptyC;
    int movesNumber;
};

#endif // BARLEY_BREAK_H
