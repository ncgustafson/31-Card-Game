#include <iostream>
#include "deck.cpp"
#include "player.cpp"


using namespace std;


int main(){
    cout << "Welcome to 31!" << endl << "Would you like to play a game? (y/n)" << endl;
    string newGame;
    cin >> newGame;
    if(newGame != "y"){
        cout << "Thank you, come again another time!" << endl;
        return 0;
    }

    cout << "How many computers do you want to play against?" << endl;
    int numComputers;
    cin >> numComputers;
    vector<computerPlayer> computers;

    for(int i = 0; i < numComputers; ++i){
        computerPlayer tempComp;
        computers.push_back(tempComp);
    }
    deck gameDeck;
    gameDeck.shuffleDeck();

    player newPlayer;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < numComputers; ++j){
            computers[j].hand.push_back(gameDeck.drawCard());
        }
        newPlayer.hand.push_back(gameDeck.drawCard());
    }
    gameDeck.playedCards.push_back(gameDeck.drawCard());
    int round = 1;
    bool knocked = false;
    while(true){
        cout << endl << "*************************" << endl;
        cout << "ROUND " << round << endl; 
        cout << "Your score: " << newPlayer.updateScore() << endl;
        cout << endl << "*************************" << endl;

        for(int i = 0; i < numComputers; ++i){
            //computers[i].displayHand();
            //cout << "Score: " << computers[i].updateScore() << endl;
            //cout << computers[i].move(gameDeck.playedCards.back()) << endl;
            if(computers[i].move(gameDeck.playedCards.back()) != -1){
                cout << endl << "----------------------------------" << endl;
                cout <<"Card Available: " << gameDeck.playedCards.back() << endl;
                card tempCard = computers[i].hand[computers[i].move(gameDeck.playedCards.back())];
                computers[i].hand[computers[i].move(gameDeck.playedCards.back())] = gameDeck.playedCards.back();
                gameDeck.playedCards.pop_back();
                gameDeck.playedCards.push_back(tempCard);
                cout << "Computer " << i << " picks up card" << endl;
                cout << "----------------------------------" << endl;
            }
            else{
                card drawedCard = gameDeck.drawCard();
                cout << endl << "----------------------------------" << endl;
                cout << "Card Available: " << gameDeck.playedCards.back() << endl;
                if(computers[i].move(drawedCard) != -1){
                    card tempCard = computers[i].hand[computers[i].move(drawedCard)];
                    computers[i].hand[computers[i].move(drawedCard)] = drawedCard;
                    gameDeck.playedCards.push_back(tempCard);
                     cout << "Computer " << i << " draws and keep drawed card" << endl;
                     cout << "----------------------------------" << endl;
                }
                else{
                    gameDeck.playedCards.push_back(drawedCard);
                    cout << "Computer " << i << " draws and places down drawed card" << endl;
                    cout << "----------------------------------" << endl;
                }
            }
            //computers[i].displayHand();
            //cout << endl;
        }
        if(knocked){
            cout << "----------------------------------" << endl;
            cout << "END OF GAME" << endl;
            for(unsigned int i = 0; i < computers.size(); ++i){
                cout << endl << "Computer " << i << " score: " << computers[i].updateScore() << endl;
                computers[i].displayHand();
            }
            cout << endl << "Your score: " << newPlayer.updateScore() << endl;
            newPlayer.displayHand();
            cout << "----------------------------------" << endl;
            return 0;
        }
        cout << endl << "----------------------------------" << endl;
        cout << "Card Available: " << gameDeck.playedCards.back() << endl;
        cout << endl << '\t' << "Your hand: (score: " << newPlayer.updateScore() << ")" << endl;
        newPlayer.displayHand();
        
        
        cout << endl << "Would you like to knock, draw card, or pick up card? (k/d/p)" << endl;
        string move;
        cin >> move;
        cout << "----------------------------------" << endl;
        if(move == "d"){
            card drawedCard = gameDeck.drawCard();
            cout << "Drawed Card: " << drawedCard << endl;
            cout << "Would you like to keep card (y/n)" << endl;
            string keepCard;
            cin >> keepCard;
            if(keepCard == "y"){
                cout << '\t' << "Which card would you like to discard? (0/1/2)" << endl;
                newPlayer.displayHand();
                int whichCard;
                cin >> whichCard;
                gameDeck.playedCards.push_back(newPlayer.hand[whichCard]);
                newPlayer.hand[whichCard] = drawedCard;
            }
            else{
                gameDeck.playedCards.push_back(drawedCard);
            }
        }
        else if(move == "p"){
            cout << "Which card would you like to discard? (0/1/2)" << endl;
                newPlayer.displayHand();
                int whichCard;
                cin >> whichCard;
                card tempCard = newPlayer.hand[whichCard];
                newPlayer.hand[whichCard] = gameDeck.playedCards.back();
                gameDeck.playedCards.pop_back();
                gameDeck.playedCards.push_back(tempCard);
        }
        else if(move == "k"){
            knocked = true;
        }
        newPlayer.updateScore();
        ++round;        
    }
    return 0;
}