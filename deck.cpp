#include "card.cpp"
#include <deque>

using namespace std;

class deck{
    public:

        deck(){
            for(int i = 1; i < 14; ++i){
                for(int j = 0; j < 4; ++j){
                    card tempCard = card(i,j);
                    cardDeck.push_back(tempCard);
                    //cout << tempCard.cardRank << " " << tempCard.cardSuit << " " << tempCard.val <<  endl;
                }
            }
        }

        void showDeck(){
            for(unsigned int i = 0; i < cardDeck.size(); ++i){
                cout << cardDeck[i].cardRank << " " << cardDeck[i].cardSuit << endl;
            }
        }

        void shuffleDeck(){
            srand(time(0));
            for (unsigned int i = 0; i < cardDeck.size(); ++i)
            {                
                int r = i + (rand() % (52 -i));        
                swap(cardDeck[i], cardDeck[r]);
            }
        }

        card drawCard(){
            card tempCard = cardDeck.back();
            cardDeck.pop_back();
            return tempCard;
        }

        deque<card> cardDeck;

        deque<card> playedCards;
};