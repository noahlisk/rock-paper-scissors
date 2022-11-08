#include <iostream>
#include <string>

using namespace std;
unsigned int rounds;
string choices[3] = {"Rock", "Paper", "Scissors"};

class Player
{
private:
    string Name;
    string Hand;
    unsigned int winCount = 0;

public:
    void setName()
    {
        string tmp;
        getline(cin, tmp);
        Name = tmp;
    }
    string getName()
    {
        return Name;
    }
    void setHand()
    {
        Hand = choices[(rand() % 3)];
    }
    string getHand()
    {
        return Hand;
    }
    void wonHand()
    {
        winCount++;
    }
    unsigned int getWins()
    {
        return winCount;
    }
};

void getPlayers(Player &player1, Player &player2)
{
    cout << "Player 1 is: " << endl;
    player1.setName();
    cout << "Player 2 is: " << endl;
    player2.setName();
    cout << "Player 1's name is " << player1.getName() << endl;
    cout << "Player 2's name is " << player2.getName() << endl
         << endl;
}

void getRounds()
{
    cout << "How many rounds do you want to play? " << endl;
    cin >> rounds;
    cout << "There are " << rounds << " rounds in this game" << endl
         << endl;
}

void gameLogic(Player &player1, Player &player2)
{
    cout << player1.getName() << " has " << player1.getHand() << endl;
    cout << player2.getName() << " has " << player2.getHand() << endl;
    if (player1.getHand() == "Rock" && player2.getHand() == "Rock")
    {
        cout << "It's a tie!" << endl
             << endl;
    }
    else if (player1.getHand() == "Rock" && player2.getHand() == "Paper")
    {
        cout << player2.getName() << " wins!" << endl
             << endl;
        player2.wonHand();
    }
    else if (player1.getHand() == "Rock" && player2.getHand() == "Scissors")
    {
        cout << player1.getName() << " wins!" << endl
             << endl;
        player1.wonHand();
    }
    else if (player1.getHand() == "Paper" && player2.getHand() == "Rock")
    {
        cout << player1.getName() << " wins!" << endl
             << endl;
        player1.wonHand();
    }
    else if (player1.getHand() == "Paper" && player2.getHand() == "Paper")
    {
        cout << "It's a tie!" << endl
             << endl;
    }
    else if (player1.getHand() == "Paper" && player2.getHand() == "Scissors")
    {
        cout << player2.getName() << " wins!" << endl
             << endl;
        player2.wonHand();
    }
    else if (player1.getHand() == "Scissors" && player2.getHand() == "Rock")
    {
        cout << player2.getName() << " wins!" << endl
             << endl;
        player2.wonHand();
    }
    else if (player1.getHand() == "Scissors" && player2.getHand() == "Paper")
    {
        cout << player1.getName() << " wins!" << endl
             << endl;
        player1.wonHand();
    }
    else if (player1.getHand() == "Scissors" && player2.getHand() == "Scissors")
    {
        cout << "It's a tie!" << endl
             << endl;
    }
}

void getWinner(Player &player1, Player &player2)
{
    if ((player1.getWins() < player2.getWins()) && (player1.getWins() != player2.getWins()))
    {
        cout << player2.getName() << " wins with " << player2.getWins() << " hands won!" << endl;
    }
    else if ((player2.getWins() < player1.getWins()) && (player1.getWins() != player2.getWins()))
    {
        cout << player1.getName() << " wins with " << player1.getWins() << " hands won!" << endl;
    }
    else
    {
        cout << "There was a tie this game!" << endl;
    }
}

int main()
{
    Player player1;
    Player player2;
    getPlayers(player1, player2);
    // input
    getRounds();
    // output
    while (rounds > 0)
    {
        player1.setHand();
        player2.setHand();
        gameLogic(player1, player2);
        rounds--;
    }

    getWinner(player1, player2);

    cout << "Game Over!" << endl;
    // game logic
    // random number generator
}
