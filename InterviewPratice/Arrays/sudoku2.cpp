/*
Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with numbers in such a way that each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.

Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout rules described above. Note that the puzzle represented by grid does not have to be solvable.

Example

For

grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
        ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
        ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
        ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
        ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
        ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
        ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
the output should be
sudoku2(grid) = true;

For

grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
        ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
        ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
        ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
        ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
        ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
        ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
        ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
the output should be
sudoku2(grid) = false.

The given grid is not correct because there are two 1s in the second column. Each column, each row, and each 3 × 3 subgrid can only contain the numbers 1 through 9 one time.

Input/Output

[time limit] 500ms (cpp)
[input] array.array.char grid

A 9 × 9 array of characters, in which each character is either a digit from '1' to '9' or a period '.'.

[output] boolean

Return true if grid represents a valid Sudoku puzzle, otherwise return false.
*/
// https://codefights.com/interview-practice/task/SKZ45AF99NpbnvgTn

bool check9num(std::vector<int> arr)
{
    int a[10] ={0};
    for(int i = 0; i < 9; i++)
    {
        if(arr[i] == 0)
            continue;
        a[arr[i]]++;
        if(a[arr[i]] > 1)
            return false;
    }
    return true;
}

bool sudoku2(std::vector<std::vector<char>> grid) {
    
    // check square 3x3

    for(int i = 0; i < 9; i++)
    {
        vector<int> a (9,0);
        vector<int> m (9,0);
        vector<int> n (9,0);
        for(int j = 0; j < 9; j++)
        {
           int c= j /3 + 3 * (i/3);
            int d = j%3 + 3* (i%3);
            if (grid[c][d] == '.')
                a[j] = 0 ;
            else a[j] = grid[c][d]-'1' + 1;
            
            if (grid[i][j] == '.')
                m[j] = 0;
            else m[j] = grid[i][j]-'1' + 1;
           
            if (grid[j][i] == '.')
                n[j] = 0;
            else n[j] = grid[j][i]-'1' + 1;
        }


        if(!check9num(a) || !check9num(n) || !check9num(m))
        {
            return false;
        }
    } 

    return true;

}

