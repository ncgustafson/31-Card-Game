#include <vector>
#include <iostream>

using namespace std;


vector<string> suits = {"clubs", "spades", "hearts", "diamonds"};

vector<string> ranks = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace"};

class card{
    public:
        card(int rank_in, int suit_in){
            if(rank_in == 13){
                val = 11;
            }
            else if(rank_in >= 9){
                val = 10;
            }
            else{
                val = rank_in + 1;
            }
            
            cardRank = ranks[rank_in];
            cardSuit = suits[suit_in];
        }

        string cardRank;

        string cardSuit;

        int val;

        friend ostream& operator<<(ostream& os, const card& card_in);
        
};

ostream& operator<<(ostream& os, const card& card_in){
            os << card_in.cardRank << " of " << card_in.cardSuit;
            return os;
        }