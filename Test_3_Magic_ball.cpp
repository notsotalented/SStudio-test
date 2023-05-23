#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int NUM_TUBES = 4;
const int WIN = 1;
const int LOSE = -1;
const int PLAY = 0;

class gameManager {
    public: 
        vector<list<string>> layout;
        int gameState;
        int magicTube;

        gameManager(int initState[][4], int magicTube) {
            for (int i = 0; i < NUM_TUBES; i++) {
                list<string> array;
                for (int j = 0; j < 4; j++) {
                    array.push_back(to_string(initState[i][j]) + "|0");
                }
                layout.push_back(array);
            }
            this->gameState = PLAY;
            this->magicTube = magicTube;
        }

        void printState() {
            cout << "CURRENT STATE: " << endl;
            for (const auto& list : layout) {
                for (const auto& index : list) {
                    //cout << index << " "; //With moves count
                    cout << ballValue(index) << " "; //Without moves count
                }
                cout << endl;
            }
            cout << endl;
        }

        void printTube(list<string> inputlist) {

            list<string> verticalTube;

            for (const auto& index : inputlist) {
                verticalTube.push_front(index);
            }

            for (const auto& index2 : verticalTube) {
                cout << index2 << endl;
            }
        }

        int ballValue(string ball) {
            int value = 0;
            int bracket = ball.find('|');

            string output = ball.substr(0, bracket);

            return value = stoi(output);
        }

        int ballCount(string ball) {
            int value = 0;
            int bracket = ball.find('|');

            string output = ball.substr(bracket+1);

            return value = stoi(output);
        }

        string updateCount(string ball) {
            string value;
            value = to_string(ballValue(ball)) + "|" + to_string(ballCount(ball)+1);

            return value;
        }

        bool isLose() {
            if (this->gameState == LOSE) return true;

            return false;
        }

        bool isWin() {
            //Check elements from each tubes
            for (const auto& list : layout) {
                int value = ballValue(*list.begin());
                for (const auto& index : list) {
                    if(value != ballValue(index)) {
                        return false;
                    }
                }
            }
            this->gameState = WIN;
            cout << "THE GAME IS WON!" << endl;
            return true;
        }

        void move(int from, int to) {
            list<string> arrFrom, arrTo;
            arrFrom = this->layout[from];
            arrTo = this->layout[to];

            string moveTo = arrTo.back(); 

            string moveFrom = "0|0";
            string dummy = "0|0";


            //printTube(arrFrom); cout << endl;
            //printTube(arrTo);

            //Condition top is occupied
            if (ballValue(moveTo) > 0) {
                cout << "FAILED TO MOVE DUE TO NO SPACES!" << endl;
                return;
            }

            //FRONT = BOT; BACK = TOP
            if (from == this->magicTube) {
                //Get bottom
                moveFrom = arrFrom.front();

                //Clean the departure
                arrFrom.pop_front(); 
                arrFrom.push_back(dummy);
            }
            else {
                //Get top
                //moveFrom = arrFrom.back();
                for (const auto& index : arrFrom) {
                    if(ballValue(index) == 0) {
                }
                else {
                    moveFrom = index;
                }
            }

                //Clean the departure
                int addition = 0;
                while (arrFrom.back() != moveFrom) {
                    addition+=1;
                    arrFrom.pop_back();
                }
                arrFrom.pop_back();
                while (addition >= 0) {
                    arrFrom.push_back(dummy);
                    addition-=1;
                }

            }
            //Update count
            moveFrom = updateCount(moveFrom);
            if (ballCount(moveFrom) > 5) {
                this->gameState = LOSE;
                cout << "MAXIMUM ALLOWED STEPS REACHED! THE GAME IS LOST!" << endl;
                return;
            }
            //Move to destination
            arrTo.pop_back(); arrTo.push_back(moveFrom);
            //Check if there is any blank spaces: i.e 1-0-0-2
            list<string> handle_spaces;
            int addition = 0;
            for (const auto& index : arrTo) {
                if(ballValue(index) == 0) {
                    addition+=1;
                }
                else {
                    handle_spaces.push_back(index);
                }
            }
            while (addition > 0) {
                handle_spaces.push_back(dummy);
                addition-=1;
            }

            //Update to layout
            layout[from] = arrFrom;
            layout[to] = handle_spaces;

            cout << "MOVE: " << moveFrom << " TO: " << moveTo << endl;
        }
};

int main()
{
    //PLEASE ADJUST THE NUM_TUBES VARIABLE AT THE TOP
    int initState[NUM_TUBES][4] = {
        {1,1,1,1},
        {2,2,2,0},
        {3,3,3,3},
        {2,0,0,0}
    };

    int initMagic = 1;

    gameManager newGame(initState, initMagic);
    newGame.printState();

    while(!newGame.isWin() && !newGame.isLose()) {
        int from, to;
        cout << "MOVING FROM TUBE: ";
        cin >> from;
        cout << "MOVING TO TUBE: ";
        cin >> to;
        newGame.move(from,to);
        newGame.printState();
    }

    return 0;
}