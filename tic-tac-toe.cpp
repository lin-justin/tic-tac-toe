// Tic-Tac-Toe AI

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Global constants
const char X      = 'X';
const char O      = 'O';
const char EMPTY  = ' ';
const char TIE    = 'T';
const char NO_ONE = 'N';

// Function prototypes
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);

// Since the board itself does not change, a constant pointer
// is used so its value will not be changed.
void displayBoard(const vector<char>* const pBoard);
char winner(const vector<char>* const pBoard);
bool isLegal(const vector<char>* const pBoard, int move);
int humanMove(const vector<char>* const pBoard, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

// Main function
int main()
{
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);

    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(&board);

    while (winner(&board) == NO_ONE)
    {
        if (turn == human)
        {
            move = humanMove(&board, human);
            board[move] = human;
        }
        else
        {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(&board);
        turn = opponent(turn);
    }

    announceWinner(winner(&board), computer, human);

    return 0;
}

// Displays the game instructions
void instructions()
{
    cout << "Welcome to Tic-Tac-Toe: Human vs AI.\n\n";

    cout << "Make your move known by entering a number, 0 - 8. The number\n";
    cout << "corresponds to the desired board position, as illustrated:\n\n";
    
    cout << "       0 | 1 | 2\n";
    cout << "       ---------\n";
    cout << "       3 | 4 | 5\n";
    cout << "       ---------\n";
    cout << "       6 | 7 | 8\n\n";
}

// Asks a yes or no question.
// Parameter is a question of type string.
// Returns either the character 'y' or 'n'.
char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << " (y/n): ";
        cin >> response;
    } while (response != 'y' && response != 'n');

    return response;
}

// Asks for a number within a range.
// Parameter is a question of type string and two numbers (high and low) of type int.
// Returns a number in the range from low to high.
int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);

    return number;
}

// Determines the user's piece.
// Returns either 'X' or 'O'.
char humanPiece()
{
    char go_first = askYesNo("Do you require the first move?");
    if (go_first == 'y')
    {
        cout << "\nUser has taken the first move.\n";
        return X;
    }
    else
    {
        cout << "\nAI has taken the first move.\n";
        return O;
    }
}

// Calculates the opposing piece given a piece.
// Parameters are either an 'X' or an 'O'.
// Returns either an 'X' or an 'O'.
char opponent(char piece)
{
    if (piece == X)
	{
        return O;
	}
    else
	{
        return X;
	}
}

// Displays the board in the terminal.
// Parameter is a board.
void displayBoard(const vector<char>* const pBoard)
{
    cout << "\n\t" << (*pBoard)[0] << " | " << (*pBoard)[1] << " | " << (*pBoard)[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << (*pBoard)[3] << " | " << (*pBoard)[4] << " | " << (*pBoard)[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << (*pBoard)[6] << " | " << (*pBoard)[7] << " | " << (*pBoard)[8];
    cout << "\n\n";
}

// Determines the game winner.
// Parameter is a board.
// Returns an 'X', 'O', 'T' (tie), or 'N' (no one has won yet).
char winner(const vector<char>* const pBoard)
{
    // All possible winning rows
    const int WINNING_ROWS[8][3] = { {0, 1, 2},
                                     {3, 4, 5},
                                     {6, 7, 8},
                                     {0, 3, 6},
                                     {1, 4, 7},
                                     {2, 5, 8},
                                     {0, 4, 8},
                                     {2, 4, 6} };
    const int TOTAL_ROWS = 8;

    // If any winning row has three values that are the same (and not EMPTY),
    // then we have a winner
    for(int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ( ((*pBoard)[WINNING_ROWS[row][0]] != EMPTY) &&
             ((*pBoard)[WINNING_ROWS[row][0]] == (*pBoard)[WINNING_ROWS[row][1]]) &&
             ((*pBoard)[WINNING_ROWS[row][1]] == (*pBoard)[WINNING_ROWS[row][2]]) )
        {
            return (*pBoard)[WINNING_ROWS[row][0]];
        }
    }

    // Since nobody has won, check for a tie (no empty squares left)
    if (count(pBoard->begin(), pBoard->end(), EMPTY) == 0)
        return TIE;

    // Since nobody has won and it isn't a tie, the game is not over
    return NO_ONE;
}

// Determines whether a move is legal.
// Paramter is a board and a move.
// Returns either true or false.
inline bool isLegal(int move, const vector<char>* pBoard)
{
    return ((*pBoard)[move] == EMPTY);
}

// Gets user's move.
// Parameter is a board and the user's piece.
// Returns the user's move.
int humanMove(const vector<char>* const pBoard, char human)
{
    int move = askNumber("Where will you move?", (pBoard->size() - 1));
    while (!isLegal(move, pBoard))
    {
        cout << "\nThat square is already occupied.\n";
        move = askNumber("Where will you move?", (pBoard->size() - 1));
    }
    return move;
}

// Calculate the AI's move.
// Parameter is a board and the AI's piece.
// Returns the AI's move.
int computerMove(vector<char> board, char computer)
{ 
    unsigned int move = 0;
    bool found = false;

    // If the AI can win on the next move, that's the move to make
    while (!found && move < board.size())
    {
        if (isLegal(move, &board))
        {
			// Try move
            board[move] = computer;
            // Check for winner
            found = winner(&board) == computer;   
			// Undo move
            board[move] = EMPTY;
        }

        if (!found)
        {
            ++move;
        }
    }
  
    // Otherwise, if the opponent can win on the next move, that's the move to make
    if (!found)
    {
        move = 0;
        char human = opponent(computer);

        while (!found && move < board.size())
        {
            if (isLegal(move, &board))
            {
				// Try move
				board[move] = human;  
				// Check for winner
                found = winner(&board) == human;     
			    // Undo move
				board[move] = EMPTY;        
            }

            if (!found)
            {
                ++move;
            }
        }
    }

    // Otherwise, moving to the best open square is the move to make
    if (!found)
    {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        // Pick best open square
        while (!found && i <  board.size())
        {
            move = BEST_MOVES[i];
            if (isLegal(move, &board))
            {
                found = true;
            }

            ++i;
        }
    }

    cout << "The AI has selected square number " << move << endl;
	return move;
}

// Congratulate winner or declare a tie.
// Parameter is the winning side, AI's piece, and user's piece.
void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
    {
        cout << winner << "'s won!\n";
        cout << "The AI has beaten the user.\n";
    }

	else if (winner == human)
    {
        cout << winner << "'s won!\n";
        cout << "The user has beaten the AI.\n";
    }

	else
    {
        cout << "The game has ended in a tie.\n";
	}
}