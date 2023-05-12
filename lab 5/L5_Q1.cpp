#include <iostream> 
using namespace std; 
int main ()
{
    const int FLOOR1 = 15;
    const int FLOOR2 = 15;
    const int STAIRS = 5;
    int building[FLOOR1 + FLOOR2][STAIRS];
    for (int i = 0; i < FLOOR1; i++)
    {
        for (int j = 0; j < STAIRS; j++)
        {
            building[i][j] = i * STAIRS + j + 1;
        }
    }
    for (int i=FLOOR1; i<FLOOR1+FLOOR2; i++)
    {
        for (int j = 0; j < STAIRS; j++)
        {
            building[i][j] = (i - FLOOR1) * STAIRS + j + FLOOR1 + 1;
        }
    }
    int start, end;
    cout << "Enter starting CR number: ";
    cin >> start;
    cout << "Enter ending CR number: ";
    cin >> end;
    int current = start;
    bool takeStairs = (start <= STAIRS && end > STAIRS) || (start > STAIRS && end <= STAIRS);
    cout << "Path: " << current;
    while (current != end)
    {
        if (takeStairs)
        {
            if (current <= STAIRS)
            {
                cout << " -> Take stairs to second floor -> " << building[FLOOR1][0];
                current = building[FLOOR1][0];
            }
            else
            {
                cout << " -> Take stairs to first floor -> " << building[0][0];
                current = building[0][0];
            }
            takeStairs = false;
        }
        else if (current < end)
        {
            if (current == STAIRS)
            {
                takeStairs = true;
            }
            else
            {
                int row = (current - 1) / STAIRS;
                int col = (current - 1) % STAIRS;
                if (col == STAIRS - 1)
                {
                    row++;
                    col = 0;
                }
                else
                {
                    col++;
                }
                current = building[row][col];
                cout << " -> " << current;
            }
        }
        else
        {
            if (current == STAIRS + 1)
            {
                takeStairs = true;
            }
            else
            {
                int row = (current - 1) / STAIRS;
                int col = (current - 1) % STAIRS;
                if (col == 0) {
                    row--;
                    col = STAIRS - 1;
                }
                else {
                    col--;
                }
                current = building[row][col];
                cout << " -> " << current;
            }
        }
    }
    cout << endl;
    return 0;
}
