#include<iostream>
using namespace std;
void map(char** arr, int n) //Tic-Tac-Toe Map
{
	cout << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;
	cout << "---------" << endl;
	cout << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl;
	cout << "---------" << endl;
	cout << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl;
	
}
bool horizontalCheck(char** arr, int n)
{
	int j = 0;
	for (int i = 0;i < n;i++)
	{
		if (arr[i][j] == arr[i][j+1] && arr[i][j] == arr[i][j+2]) 
			return true;
	}
	return false;
}

bool verticalCheck(char** arr, int n) 
{

	int i = 0;
	for (int j = 0;j< n;j++)
	{		
		if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 2][j]) 
			return true;
	}
	return false;
	
}

bool diagonalCheck(char** arr, int n)
{
	if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2])
	{
		return true;
	}
	else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
	{
		return true;
	}
	else
		return false;

}

void initgame(char** arr, int n) //Initilize the game from start
{
	int k = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			arr[i][j] = k + '1';
			k++;
		}
	}
}

bool fill(char** arr, int n, char num, bool flag) //put X or O into the board based on the player turn
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (flag && arr[i][j] == num)
			{
				arr[i][j] = 'X';
				return true;
			}
			else if (!flag && arr[i][j] == num)
			{
				arr[i][j] = 'O';
				return true;
			}
		}
	}
	return false;
}
void game(char** arr, int n)
{
	string player1, player2;
	char num, ch;
	cout << "====== WELCOME TO TIC-TAC-TOE! =======" << endl;
	cout << "Enter the name of player 1: ";
	cin >> player1;
	cout << "Enter the name of player 2: ";
	cin >> player2;
	cout << "Game is starting!" << endl;
	cout << player1 << " vs " << player2 << endl;
	bool flag = true;
	map(arr, n);
	while (true)
	{
		if (flag) //check if the turn is of player 1 or 2
		{
			cout << player1 << "! this is your turn" << endl;
			cout << "Enter your choice (1-9): ";
			cin >> num;
			while(!fill(arr, n, num, flag))
			{
				
				cout << "Already filled!" << endl;
				cout << "Enter again your choice (1-9): ";
				cin >> num;
			}
			if (horizontalCheck(arr, n))
				break;
			if (verticalCheck(arr, n))
				break;
			if (diagonalCheck(arr, n))
				break;
			flag = !flag;
			map(arr, n);
		}
		else
		{
			cout << player2 << "! this is your turn" << endl;
			cout << "Enter your choice (1-9): ";
			cin >> num;
			while (!fill(arr, n, num, flag))
			{

				cout << "Already filled!" << endl;
				cout << "Enter again your choice (1-9): ";
				cin >> num;
			}
			if (horizontalCheck(arr, n))
				break;
			if (verticalCheck(arr, n))
				break;
			if (diagonalCheck(arr, n))
				break;
			flag = !flag;
			map(arr, n);
		}

	}
	map(arr, n);
	if (flag)
	{
		cout << "Congratulations " << player1 << "! you win" << endl;
	}
	else
	{
		cout << "Congratulations " << player2 << "! you win" << endl;
	}
	cout << "Do you want to play again? (y or n)";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		initgame(arr, n);
		game(arr, n);
	}
}
void destruct(char** arr, int n) //destructor for destroying the 2d dynamic char array
{
	for (int i = 0;i < n;i++)
	{
		delete[] arr[i];

	}
	delete[] arr;
}
int main()
{
	int n = 3;
	char** arr = new char*[n];
	for (int i = 0;i < n;i++)
	{
		arr[i] = new char[n];
		
	}
	initgame(arr, n);
	game(arr, n); 
	
	return 0;
}