#include <iostream>
#include <array>
using namespace std;

void printLine() {
        cout << "---+---+---" << endl;
}
void printTop() {
        cout << "   |   |   " << endl;
}
void printGrid(char Positions[9]) {
        printTop();
        cout << " " << Positions[0] << " | " << Positions[1] << " | " << Positions[2] << " " << endl;
        printTop();
        printLine();
        printTop();
        cout << " " << Positions[3] << " | " << Positions[4] << " | " << Positions[5] << " " << endl;
        printTop();
        printLine();
        printTop();
        cout << " " << Positions[6] << " | " << Positions[7] << " | " << Positions[8] << " " << endl;
        printTop();


}

void ChooseMarks(char &mark1, char &mark2) {
        string m1, m2;

        do{
        cout << "Please select the character marking for Player 1" << endl;
        cin >> m1;
        }while(m1 == " " || m1 == "\t" || m1 == m2 || m1 == "\n" || m1 == "\0"|| m1.length() > 1);

        do{
        cout << "Please select the character marking for Player 2" << endl;
        cin >> m2;
        }while(m2 == m1 || m2 == " " || m2 == "\t" || m2 == "\n" || m2 == "\0"|| m2.length() >1);
        mark1 = m1[0];
        mark2 = m2[0];


}
bool P1Wins(string P1) {
        cout << P1 << " has won!" << endl;
        return true;
}

bool P2Wins(string P2) {
        cout << P2 <<" has won!" << endl;
        return true;
}
bool Winner(char Positions[9], char mark1, char mark2, string P1, string P2) {
        if(Positions[0] == mark1 && Positions[1] == mark1 && Positions[2] == mark1) {
                return P1Wins(P1);
        }
        else if(Positions[3] == mark1 && Positions[4] == mark1 && Positions[5] == mark1) {
                return P1Wins(P1);
        }
        else if(Positions[6] == mark1 && Positions[7] == mark1 && Positions[8] == mark1) {
                return P1Wins(P1);
        }
        else if(Positions[0] == mark1 && Positions[3] == mark1 && Positions[6] == mark1) {
                return P1Wins(P1);
        }
        else if(Positions[1] == mark1 && Positions[4] == mark1 && Positions[7] == mark1) {
                return P1Wins(P1);
        }
        else if(Positions[2] == mark1 && Positions[5] == mark1 && Positions[8] == mark1) {
                return P1Wins(P1);
        }
        else if(Positions[0] == mark1 && Positions[4] == mark1 && Positions[8] == mark1) {
                return P1Wins(P1);
        }
        else if(Positions[2] == mark1 && Positions[4] == mark1 && Positions[6] == mark1) {
                return P1Wins(P1);
        }
        else if(Positions[0] == mark2 && Positions[1] == mark2 && Positions[2] == mark2) {
                return P2Wins(P2);
        }
        else if(Positions[3] == mark2 && Positions[4] == mark2 && Positions[5] == mark2) {
                return P2Wins(P2);
        }
        else if(Positions[6] == mark2 && Positions[7] == mark2 && Positions[8] == mark2) {
                return P2Wins(P2);
        }
        else if(Positions[0] == mark2 && Positions[3] == mark2 && Positions[6] == mark2) {
                return P2Wins(P2);
        }
        else if(Positions[1] == mark2 && Positions[4] == mark2 && Positions[7] == mark2) {
                return P2Wins(P2);
        }
        else if(Positions[2] == mark2 && Positions[5] == mark2 && Positions[8] == mark2) {
                return P2Wins(P2);
        }
        else if(Positions[0] == mark2 && Positions[4] == mark2 && Positions[8] == mark2) {
                return P2Wins(P2);
        }
        else if(Positions[2] == mark2 && Positions[4] == mark2 && Positions[6] == mark2) {
                return P2Wins(P2);
        }
        return false;
}

void ChooseNames(string &P1, string &P2) {
        cout << "Enter Player 1's name: ";
        cin >> P1;
        cout << "Enter Player 2's name: ";
        cin >> P2;
}


int main() {
        char Positions[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char mark1;
        char mark2;
        int turns = 0;
        int choice1 = 0;
        int choice2 = 0;
        string P1 = "Player 1";
        string P2 = "Player 2";
        ChooseNames(P1, P2);
        ChooseMarks(mark1, mark2);
        printGrid(Positions);

        do{
                do{
                cout << P1 << ", choose a valid position between 1 and 9." << endl;
                cin >> choice1;
                }while(choice1 <=0 || choice1 >=10 || Positions[choice1 -1] == mark1 || Positions[choice1 -1] == mark2);
                Positions[choice1 - 1] = mark1;
                printGrid(Positions);

                if(Winner(Positions, mark1, mark2, P1, P2) == true) {
                        break;
                }

                turns++;
                if(turns == 9) {
                        cout << "The game is a tie!" << endl;
                        break;
                }

                do{
                cout << P2 << ", choose a valid position between 1 and 9." << endl;
                cin >> choice2;
                }while(choice2 <=0 || choice2 >=10 || Positions[choice2 -1] == mark1 || Positions[choice1 -1] == mark2);

                Positions[choice2 - 1] = mark2;
                printGrid(Positions);
                turns++;
                if(turns == 9 && Winner(Positions, mark1, mark2, P1, P2) == false){
                        cout << "The game is a tie!" << endl;;
                        break;
                }
        }while(!Winner(Positions, mark1, mark2, P1, P2));
        return 0;
}
