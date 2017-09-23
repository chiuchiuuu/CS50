/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;
// row and column of "_"
int row, column;

// prototypes
void clear(void);
void greet(void);
void init();
void draw(void);
bool move(int tile);
bool won(void);
void swap(int *a, int*b);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();
    
    //keep track of " _" location
    row = d - 1;
    column = d - 1; 
    
    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init()
{
    int value = d * d - 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++, value--)
        {
            board[i][j] = value;
        }
    }
    // if dimension is even, swap 1 and 2
    if (d % 2 == 0)
    {
        swap(&board[d-1][d-2], &board[d-1][d-3]);
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // blank line stands for 0
            if (board[i][j] == 0)
            {
                printf(" _ ");
            }
            else
            {
                printf("%2i ", board[i][j]);
            }
        }
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // input should be int between [1, d*d-1]
    if ( tile < 1 || tile > d*d -1)
    {
        return false;
    }
    
    // find the location of tail
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if ( tile == board[i][j])
            {
                // check if blank line can be swaped left, right, up or down
                if ((i == row && (j == column - 1 || j == column + 1)) || ((i == row + 1 || i == row - 1) && j == column ))  
                {
                    swap(&board[i][j], &board[row][column]);
                    // keep track of the location of blank line
                    row = i;
                    column = j;
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // compare board with win-value
    for (int i = 0, value = 1; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == value)
            {
                value++;
            }
            else if (value == d*d && board[i][j] == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

void swap(int *a, int*b)
{
    /**
     * swap two variables' value
     */
     int temp = *b;
     *b = *a;
     *a = temp;
}