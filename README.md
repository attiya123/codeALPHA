//sudoku game code
#include <iostream>
using namespace std;

const int GRID_SIZE = 9;

class SudokuSolver 
{
private:
    int grid[GRID_SIZE][GRID_SIZE];

public:
                                             // Constructor to initialize the Sudoku grid
    SudokuSolver(int inputGrid[GRID_SIZE][GRID_SIZE]) 
    {
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                grid[i][j] = inputGrid[i][j];
            }
        }
    }

                                            // Function to print the Sudoku board
    void printGrid() {
        for (int row = 0; row < GRID_SIZE; row++)
        {
            for (int col = 0; col < GRID_SIZE; col++) 
            {
                cout << grid[row][col] << " ";
            }
            cout << endl;
        }
    }

                                           // Function to check if a number can be placed in the given row, column
    bool isSafe(int row, int col, int num) 
    {
                                         // Check if 'num' is not in the current row or column
        for (int x = 0; x < GRID_SIZE; x++)
        {
            if (grid[row][x] == num || grid[x][col] == num) 
            {
                return false;
            }
        }

                                         // Check if 'num' is not in the current 3x3 subgrid
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) 
            {
                if (grid[i + startRow][j + startCol] == num)
                {
                    return false;
                }
            }
        }

        return true;
    }

                                          // Function to solve Sudoku using backtracking
    bool solve()
    {
        int row, col;
        bool isEmpty = false;

                                          // Find an empty cell
        for (row = 0; row < GRID_SIZE; row++)
        {
            for (col = 0; col < GRID_SIZE; col++) 
            {
                if (grid[row][col] == 0) 
                {
                    isEmpty = true;
                    break;
                }
            }
            if (isEmpty) break;
        }

        // If there are no empty cells left, we’re done
        if (!isEmpty) return true;

                                 // Try all numbers from 1 to 9 in the empty cell
        for (int num = 1; num <= 9; num++) 
        {
            if (isSafe(row, col, num)) 
            {
                grid[row][col] = num;

                                   // Recursive call to solve the rest of the grid
                if (solve()) return true;

                                      // Reset if the number doesn't lead to a solution
                grid[row][col] = 0;
            }
        }
        return false;
    }
};

int main() {
                                     // Example Sudoku puzzle (0 represents empty cells)
    int inputGrid[GRID_SIZE][GRID_SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

                                   // Create an instance of SudokuSolver and solve the puzzle
    SudokuSolver solver(inputGrid);

    if (solver.solve()) 
    {
        cout << "Solved Sudoku:" << endl;
        solver.printGrid();
    } else 
    {
        cout << "No solution exists for this Sudoku puzzle." << endl;
    }

    return 0;
}
