#include "History.h"
#include "globals.h"
#include <iostream>

using namespace std;

History::History(int nRows, int nCols)
{
    m_rows = nRows;
    m_cols = nCols;

    for (int r = 1; r <= m_rows; r++) { //corresponds to the num of valid carrots at each grid spot
        for (int c = 1; c <= m_cols; c++) {
            carrotTracker[r - 1][c - 1] = 0;
        }
    }

}

bool History::record(int r, int c) //should only be called whenever a succesful carrot is placed 
{
    if (c < 1 || r < 1 || c > m_cols || r> m_rows) { //checks bounds
        return false;
    }
    carrotTracker[r - 1][c - 1] += 1; //should track the number of carrots at that spot
    return true;
}

void History::display() const
{
    char Hgrid[MAXROWS][MAXCOLS];
    int r;
    int c;

    //Arena* h_arena = this->m_arena;

    for (r = 1; r <= m_rows; r++) { //dot grid
        for (c = 1; c <= m_cols; c++) {
            if (carrotTracker[r - 1][c - 1] > 0 && carrotTracker[r - 1][c - 1] < 26) { //if (m_arena->getCellStatus(r, c) == EMPTY) //there seems to be a problem w/ accessing m_arena, also remember to add a return in takePlayerTurn
                Hgrid[r - 1][c - 1] = (carrotTracker[r - 1][c - 1]) + '@'; //tracks carrots
            }
            else if (carrotTracker[r - 1][c - 1] >= 26) {
                Hgrid[r - 1][c - 1] = 'Z';
            }
            else {
                Hgrid[r - 1][c - 1] = '.';
            }
        }
    }

    //draws grid

    clearScreen();
    for (r = 1; r <=m_rows; r++)
    {
        for (c = 1; c <= m_cols; c++) {
            cout << Hgrid[r - 1][c - 1];
        }
        cout << endl;
    }
    cout << endl;
}