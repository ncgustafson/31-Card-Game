#include <unordered_map>

using namespace std;

class player{
    public:
    player(){

    }

    void displayHand(){
        for(int i = 0; i < 3; ++i){
            cout << '\t' << "Card: " << i << " " << hand[i].cardRank << " of " << hand[i].cardSuit << endl;
        }
    }

    int checkScore(){
        int max = 0;
        for(unsigned int i = 0; i < hand.size(); ++i){
            scores[hand[i].cardSuit] += hand[i].val;
            if(scores[hand[i].cardSuit] > max){
                max = scores[hand[i].cardSuit];
            }
        }
        for(auto it = scores.begin(); it != scores.end(); ++it){
            it->second = 0;
        }
        return max;
    }

    int updateScore(){ 
        score = checkScore();     
        return score;
    }

    

    

    int score;

    vector<card> hand;

    unordered_map<string,int> scores;
};

class computerPlayer: public player{
    public:

    int move(card card_in){
        updateScore();
        int maxScore = score;
        int discardIndex = -1;
        for(unsigned int i = 0; i < hand.size(); ++i){
            card tempCard = hand[i];
            hand[i] = card_in;
            //displayHand();
            //cout << checkScore() << " " << maxScore << endl;
            if(checkScore() > maxScore){
                maxScore = checkScore();
                discardIndex = i;
            }
            hand[i] = tempCard;
        }
        /*if(maxScore > score){
            hand[discardIndex] = card_in;
        }*/
        return discardIndex;
    }

    bool knock(){
        if(score >= 24){
            return true;
        }
        return false;
    }
};