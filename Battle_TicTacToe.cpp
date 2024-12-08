#include <iostream>
#include <array>
#include <cctype>
#include <fstream>
using namespace std;

int totalCount = 0;
int player1Won = 0;
int player2Won = 0;
int tie = 0;

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
        }while(m1 == " " || m1 == "\t" || m1 == m2 || m1 == "\n" || m1 == "\0"|| m1.length() > 1 || isdigit(m1[0]));

        do{
        cout << "Please select the character marking for Player 2" << endl;
        cin >> m2;
        }while(m2 == m1 || m2 == " " || m2 == "\t" || m2 == "\n" || m2 == "\0"|| m2.length() > 1 || isdigit(m2[0]));
        mark1 = m1[0];
        mark2 = m2[0];
}

bool P1Wins(string P1) {
        cout << P1 << " has won!" << endl;
        player1Won++;
        return true;
}
bool P2Wins(string P2) {
        cout << P2 <<" has won!" << endl;
        player2Won++;
        return true;
}

bool Winner(char Positions[], char mark1, char mark2, string P1, string P2) {
        for(int i = 0; i < 3; i++) {
                if(Positions[i*3] == mark1 && Positions[i*3 +1] == mark1 && Positions[i*3 +2] == mark1){
                        return P1Wins(P1);
                }
                else if(Positions[i] == mark1 && Positions[i+3] == mark1 && Positions[i+6] == mark1) {
                        return P1Wins(P1);
                }
        }
        for(int i = 0; i < 3; i++) {
                if(Positions[i*3] == mark2 && Positions[i*3 +1] == mark2 && Positions[i*3 +2] == mark2){
                        return P2Wins(P2);
                }
                else if(Positions[i] == mark2 && Positions[i+3] == mark2 && Positions[i+6] == mark2) {
                        return P2Wins(P2);
                }
        }
        if(Positions[0] == mark1 && Positions[4] == mark1 && Positions[8] == mark1) {
                return P1Wins(P1);
        }
        else if(Positions[2] == mark1 && Positions[4] == mark1 && Positions[6] == mark1) {
                return P1Wins(P1);
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
void GameStart(string &P1, string &P2, char &mark1, char &mark2, char Positions[]) {
        ChooseNames(P1, P2);
        ChooseMarks(mark1, mark2);
        printGrid(Positions);
}
void RegularTTT(string P1, string P2, char mark1, char mark2, char Positions[], string c1, string c2, int choice1, int choice2, int turns) {
        cin.ignore();
        do{
                do{
                cout << P1 << ", choose a valid position between 1 and 9." << endl;
                getline(cin, c1);
                if(c1.length() == 1 && isdigit(c1[0])) {
                        choice1 = stoi(c1);
                }

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
                getline(cin, c2);
                if(c2.length() == 1 && isdigit(c2[0])) {
                        choice2 = stoi(c2);
                }
                }while(choice2 <=0 || choice2 >=10 || Positions[choice2 -1] == mark1 || Positions[choice1 -1] == mark2);
                Positions[choice2 - 1] = mark2;
                printGrid(Positions);
                turns++;
                if(turns == 9 && Winner(Positions, mark1, mark2, P1, P2) == false){
                        cout << "The game is a tie!" << endl;;
                        break;
                }
        }while(!Winner(Positions, mark1, mark2, P1, P2));
}

void swap(char Positions[], char mark1, char mark2) {
        string p1, p2;
        int pos1, pos2;
        do{
        do{
        cout << "Enter the position of the mark you want to swap" << endl;
        getline(cin, p1);
        if(!isdigit(p1[0]) || p1.length() >1) {
                cout << "That is not a valid input!" << endl;
        }
        }while(!isdigit(p1[0]) || p1.length() >1);
        do{
        cout << "Enter the position of the mark you want to swap with" << endl;
        getline(cin, p2);
        if(!isdigit(p2[0]) || p2.length() >1) {
                cout << "That is not a valid input!" << endl;
        }
        }while(!isdigit(p2[0]) || p2.length() > 1);
        pos1 = stoi(p1);
        pos2 = stoi(p2);
        if(isdigit(Positions[pos1-1]) || isdigit(Positions[pos2-1])) {
                cout << "That is not a valid position!" << endl;
        }
        else if(Positions[pos1-1] == mark1 && Positions[pos2-1] == mark1) {
                cout << "You cannot swap the same mark!" << endl;
        }
        else if(Positions[pos1-1] == mark2 && Positions[pos2-1] == mark2) {
                cout << "You cannot swap the same mark!" << endl;
        }

        }while(isdigit(Positions[pos1-1]) || isdigit(Positions[pos2-1]) || (Positions[pos1-1] == mark1 && Positions[pos2-1] == mark1) || (Positions[pos1-1] == mark2 && Positions[pos2-1] == mark2));

        Positions[pos1-1] = mark2;
        Positions[pos2-1] = mark1;

}

void move_adj(char Positions[], char mark1, char mark2) {
        string c1, c2;
        int pos1, pos2;
        label:
        do{
        cout << "Enter the position of the mark you want to move" << endl;
        getline(cin, c1);
        if(!isdigit(c1[0]) || c1.length() > 1){
                cout << "That is not a valid input!"<<endl;
        }
        else if(isdigit(c1[0]) && c1.length() == 1) {
                pos1 = stoi(c1);
                if(pos1 <=0 || pos1 >=10) {
                        cout << "That value is not in range!" << endl;
                }
                else if(Positions[pos1-1] == mark2) {
                        cout << "You cannot move your opponent's mark!" << endl;
                }
                else if(Positions[pos1-1] != mark1) {
                        cout << "You cannot move this mark!" << endl;
                }
        }
        }while(!isdigit(c1[0]) || c1.length() > 1 || pos1 <=0 || pos1 >=10 || Positions[pos1-1] != mark1 || Positions[pos1-1] == mark2);
        switch(pos1) {
                case 1:
                        if(!isdigit(Positions[1]) && !isdigit(Positions[3]) && !isdigit(Positions[4])) {
                                cout << "You cannot move this mark!" << endl;
                                goto label;
                        }
                        else {
                        do {
                        cout << "Enter the position you want to move to:" << endl;
                        getline(cin, c2);
                        if(!isdigit(c2[0]) || c2.length() > 1) {
                                cout << "That is not a valid input!" << endl;
                        }
                        else if(isdigit(c2[0]) && c2.length() == 1) {
                                pos2 = stoi(c2);
                                if(pos2 <= 0 || pos2 >= 10) {
                                        cout << "That value is not in range!" << endl;
                                }
                                else if(pos2 != 2 && pos2 != 4 && pos2 != 5) {
                                        cout << "Invalid move!" << endl;
                                }
                                else if(Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2) {
                                        cout << "You cannot overwrite another mark!" << endl;
                                }
                        }
                        }while(!isdigit(c2[0]) || c2.length() > 1 || pos2 <=0 || pos2 >=10 || (pos2 != 2 && pos2 != 4 && pos2 != 5) || Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2);
                        Positions[0] = '1';
                        Positions[pos2-1] = mark1;
                        }
                        break;
                case 2:
                        if(!isdigit(Positions[0]) && !isdigit(Positions[2]) && !isdigit(Positions[4]) && !isdigit(Positions[3])&& !isdigit(Positions[5])) {
                                cout << "You cannot move this mark!" << endl;
                                goto label;
                        }
                        else {
                        do {
                        cout << "Enter the position you want to move to:" << endl;
                        getline(cin, c2);
                        if(!isdigit(c2[0]) || c2.length() > 1) {
                                cout << "That is not a valid input!" << endl;
                        }
                        else if(isdigit(c2[0]) && c2.length() == 1) {
                                pos2 = stoi(c2);
                                if(pos2 <= 0 || pos2 >= 10) {
                                        cout << "That value is not in range!" << endl;
                                }
                                else if(pos2 != 1 &&  pos2 != 3 &&  pos2 != 5 && pos2 != 4 && pos2 != 6 ) {
                                        cout << "Invalid move!" << endl;
                                }
                                else if(Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2) {
                                        cout << "You cannot overwrite another mark!" << endl;
                                }
                        }
                        }while(!isdigit(c2[0]) || c2.length() > 1 || pos2 <=0 || pos2 >=10 || (pos2 != 1 && pos2 != 3 && pos2 != 4 && pos2 != 5 && pos2 != 6) || Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2);
                        Positions[1] = '2';
                        Positions[pos2-1] = mark1;
                        }
                        break;
                case 3:
                        if(!isdigit(Positions[1]) && !isdigit(Positions[4]) && !isdigit(Positions[5])) {
                                cout << "You cannot move this mark!" << endl;
                                goto label;
                        }
                        else {
                        do {
                        cout << "Enter the position you want to move to:" << endl;
                        getline(cin, c2);
                        if(!isdigit(c2[0]) || c2.length() > 1) {
                                cout << "That is not a valid input!" << endl;
                        }
                        else if(isdigit(c2[0]) && c2.length() == 1) {
                                pos2 = stoi(c2);
                                if(pos2 <= 0 || pos2 >= 10) {
                                        cout << "That value is not in range!" << endl;
                                }
                                else if(pos2 != 2 && pos2 != 5 && pos2 != 6) {
                                        cout << "Invalid move!" << endl;
                                }
                                else if(Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2) {
                                        cout << "You cannot overwrite another mark!" << endl;
                                }
                        }
                        }while(!isdigit(c2[0]) || c2.length() > 1 || pos2 <=0 || pos2 >=10 || (pos2 != 2 && pos2 != 5 && pos2 != 6) || Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2);
                        Positions[2] = '3';
                        Positions[pos2-1] = mark1;
                        }
                        break;
                case 4:
                        if(!isdigit(Positions[0]) && !isdigit(Positions[1]) && !isdigit(Positions[4]) && !isdigit(Positions[6])&& !isdigit(Positions[7])) {
                                cout << "You cannot move this mark!" << endl;
                                goto label;
                        }
                        else {
                        do {
                        cout << "Enter the position you want to move to:" << endl;
                        getline(cin, c2);
                        if(!isdigit(c2[0]) || c2.length() > 1) {
                                cout << "That is not a valid input!" << endl;
                        }
                        else if(isdigit(c2[0]) && c2.length() == 1) {
                                pos2 = stoi(c2);
                                if(pos2 <= 0 || pos2 >= 10) {
                                        cout << "That value is not in range!" << endl;
                                }
                                else if(pos2 != 1 &&  pos2 != 2 &&  pos2 != 5 && pos2 != 7 && pos2 != 8 ) {
                                        cout << "Invalid move!" << endl;
                                }
                                else if(Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2) {
                                        cout << "You cannot overwrite another mark!" << endl;
                                }
                        }
                        }while(!isdigit(c2[0]) || c2.length() > 1 || pos2 <=0 || pos2 >=10 || (pos2 != 1 && pos2 != 2 && pos2 != 5 && pos2 != 7 && pos2 != 8) || Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2);
                        Positions[3] = '4';
                        Positions[pos2-1] = mark1;
                        }
                        break;
                case 5:
                        if(!isdigit(Positions[0]) && !isdigit(Positions[1]) && !isdigit(Positions[2]) && !isdigit(Positions[3])&& !isdigit(Positions[5]) && !isdigit(Positions[6]) && !isdigit(Positions[7]) && !isdigit(Positions[8])) {
                                cout << "You cannot move this mark!" << endl;
                                goto label;
                        }
                        else {
                        do {
                        cout << "Enter the position you want to move to:" << endl;
                        getline(cin, c2);
                        if(!isdigit(c2[0]) || c2.length() > 1) {
                                cout << "That is not a valid input!" << endl;
                        }
                        else if(isdigit(c2[0]) && c2.length() == 1) {
                                pos2 = stoi(c2);
                                if(pos2 <= 0 || pos2 >= 10) {
                                        cout << "That value is not in range!" << endl;
                                }
                                else if(pos2 == 5) {
                                        cout << "Invalid move! You have to move to another position." << endl;
                                }
                                else if(Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2) {
                                        cout << "You cannot overwrite another mark!" << endl;
                                }
                        }
                        }while(!isdigit(c2[0]) || c2.length() > 1 || pos2 <=0 || pos2 >=10 || pos2 == 5 || Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2);
                        Positions[4] = '5';
                        Positions[pos2-1] = mark1;
                        }
                        break;
                case 6:
                        if(!isdigit(Positions[1]) && !isdigit(Positions[2]) && !isdigit(Positions[4]) && !isdigit(Positions[7])&& !isdigit(Positions[8])) {
                                cout << "You cannot move this mark!" << endl;
                                goto label;
                        }
                        else {
                        do {
                        cout << "Enter the position you want to move to:" << endl;
                        getline(cin, c2);
                        if(!isdigit(c2[0]) || c2.length() > 1) {
                                cout << "That is not a valid input!" << endl;
                        }
                        else if(isdigit(c2[0]) && c2.length() == 1) {
                                pos2 = stoi(c2);
                                if(pos2 <= 0 || pos2 >= 10) {
                                        cout << "That value is not in range!" << endl;
                                }
                                else if(pos2 != 2 &&  pos2 != 3 &&  pos2 != 5 && pos2 != 8 && pos2 != 9 ) {
                                        cout << "Invalid move!" << endl;
                                }
                                else if(Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2) {
                                        cout << "You cannot overwrite another mark!" << endl;
                                }
                        }
                        }while(!isdigit(c2[0]) || c2.length() > 1 || pos2 <=0 || pos2 >=10 || (pos2 != 2 && pos2 != 3 && pos2 != 5 && pos2 != 8 && pos2 != 9) || Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2);
                        Positions[5] = '6';
                        Positions[pos2-1] = mark1;
                        }
                        break;

                case 7:
                        if(!isdigit(Positions[3]) && !isdigit(Positions[4]) && !isdigit(Positions[7])) {
                                cout << "You cannot move this mark!" << endl;
                                goto label;
                        }
                        else {
                        do {
                        cout << "Enter the position you want to move to:" << endl;
                        getline(cin, c2);
                        if(!isdigit(c2[0]) || c2.length() > 1) {
                                cout << "That is not a valid input!" << endl;
                        }
                        else if(isdigit(c2[0]) && c2.length() == 1) {
                                pos2 = stoi(c2);
                                if(pos2 <= 0 || pos2 >= 10) {
                                        cout << "That value is not in range!" << endl;
                                }
                                else if(pos2 != 5 && pos2 != 4 && pos2 != 8 ) {
                                        cout << "Invalid move!" << endl;
                                }
                                else if(Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2) {
                                        cout << "You cannot overwrite another mark!" << endl;
                                }
                        }
                        }while(!isdigit(c2[0]) || c2.length() > 1 || pos2 <=0 || pos2 >=10 || (pos2 != 4 && pos2 != 5 && pos2 != 8) || Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2);
                        Positions[6] = '7';
                        Positions[pos2-1] = mark1;
                        }
                        break;
                case 8:
                        if(!isdigit(Positions[3]) && !isdigit(Positions[4]) && !isdigit(Positions[5]) && !isdigit(Positions[6])&& !isdigit(Positions[8])) {
                                cout << "You cannot move this mark!" << endl;
                                goto label;
                        }
                        else {
                        do {
                        cout << "Enter the position you want to move to:" << endl;
                        getline(cin, c2);
                        if(!isdigit(c2[0]) || c2.length() > 1) {
                                cout << "That is not a valid input!" << endl;
                        }
                        else if(isdigit(c2[0]) && c2.length() == 1) {
                                pos2 = stoi(c2);
                                if(pos2 <= 0 || pos2 >= 10) {
                                        cout << "That value is not in range!" << endl;
                                }
                                else if(pos2 != 4 &&  pos2 != 5 &&  pos2 != 6 && pos2 != 7 && pos2 != 9 ) {
                                        cout << "Invalid move!" << endl;
                                }
                                else if(Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2) {
                                        cout << "You cannot overwrite another mark!" << endl;
                                }
                        }
                        }while(!isdigit(c2[0]) || c2.length() > 1 || pos2 <=0 || pos2 >=10 || (pos2 != 4 && pos2 != 5 && pos2 != 6 && pos2 != 7 && pos2 != 9) || Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2);
                        Positions[7] = '8';
                        Positions[pos2-1] = mark1;
                        }
                        break;
                case 9:
                        if(!isdigit(Positions[4]) && !isdigit(Positions[5]) && !isdigit(Positions[7])) {
                                cout << "You cannot move this mark!" << endl;
                                goto label;
                        }
                        else {
                        do {
                        cout << "Enter the position you want to move to:" << endl;
                        getline(cin, c2);
                        if(!isdigit(c2[0]) || c2.length() > 1) {
                                cout << "That is not a valid input!" << endl;
                        }
                        else if(isdigit(c2[0]) && c2.length() == 1) {
                                pos2 = stoi(c2);
                                if(pos2 <= 0 || pos2 >= 10) {
                                        cout << "That value is not in range!" << endl;
                                }
                                else if(pos2 != 5 && pos2 != 8 && pos2 != 6 ) {
                                        cout << "Invalid move!" << endl;
                                }
                                else if(Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2) {
                                        cout << "You cannot overwrite another mark!" << endl;
                                }
                        }
                        }while(!isdigit(c2[0]) || c2.length() > 1 || pos2 <=0 || pos2 >=10 || (pos2 != 8 && pos2 != 5 && pos2 != 6) || Positions[pos2-1] == mark1 || Positions[pos2-1] == mark2);
                        Positions[8] = '9';
                        Positions[pos2-1] = mark1;
                        }
                        break;


        }
}


void Paladin(char Positions[], string P, char mark1, char mark2 ) {
        cout << P << " activated the Paladin ability!" << endl;
        move_adj(Positions, mark1, mark2);
}

void Alchemist(char Positions[], string P, char mark1, char mark2) {
        cout << P << " activated the Alchemist ability!" << endl;
        swap(Positions, mark1, mark2);
}

void BattleTTT(string P1, string P2, char mark1, char mark2, char Positions[], string c1, string c2, int choice1, int choice2, int turns) {
        int P1power_used = 0;
        int P2power_used = 0;
        int P1power, P2power;
        string p1input, p2input;
        cin.ignore();
        do {
        cout << P1 << ", please select a power:\n (1) Paladin\n (2) Alchemist" << endl;
        getline(cin, p1input);
        if(!isdigit(p1input[0]) || p1input.length() > 1 || (p1input!= "1" && p1input!= "2")){
                cout << "That is not a valid choice!" << endl;
        }
        }while(!isdigit(p1input[0]) || p1input.length() > 1 || (p1input!= "1" && p1input!= "2"));
        do {
        cout << P2 << ", please select a power:\n (1) Paladin\n (2) Alchemist" << endl;
        getline(cin, p2input);
        if(!isdigit(p2input[0]) || p2input.length() > 1 || (p2input!="1" && p2input!="2")){
                cout << "That is not a valid choice!" << endl;
        }
        }while(!isdigit(p2input[0]) || p2input.length() > 1 || (p2input!="1" && p2input!="2"));
        P1power = stoi(p1input);
        P2power = stoi(p2input);


        printGrid(Positions);
        do{
                do{
                if(P1power_used == 1) {
                cout << P1 << ", choose a valid position between 1 and 9." << endl;
                }
                else if(P1power_used == 0) {
                cout << P1 << ", choose a valid position between 1 and 9. Or input Q to use your power!" << endl;
                }
                getline(cin, c1);
                if(c1.length() == 1 && isdigit(c1[0])) {
                        choice1 = stoi(c1);
                }
                else if (c1 == "Q") {
                        if(P1power == 1 && turns < 2) {
                                cout << "You cannot use your power yet!" << endl;
                                c1 = "q";
                        }
                        else if (P1power == 2 && turns < 2) {
                                cout << "You cannot use your power yet!" << endl;
                                c1 = "q";
                        }
                        else if (P1power_used == 1) {
                                cout << "You cannot use your power twice!" << endl;
                                c1 = "q";
                        }
                        else {
                                break;
                        }
                }
                }while(choice1 <=0 || choice1 >=10 || Positions[choice1 -1] == mark1 || Positions[choice1 -1] == mark2 || (c1 != "Q" && !isdigit(c1[0])));
                if(c1 != "Q") {
                Positions[choice1 - 1] = mark1;
                turns++;
                }
                else if(c1 == "Q" && P1power_used == 0 && P1power == 1 && turns >= 2) {
                        Paladin(Positions, P1, mark1, mark2);
                        P1power_used  = 1;
                }
                else if(c1 == "Q" && P1power_used == 0 && P1power == 2 && turns >= 2) {
                        Alchemist(Positions, P1, mark1, mark2);
                        P1power_used = 1;
                }
                printGrid(Positions);
                if(Winner(Positions, mark1, mark2, P1, P2) == true) {
                        break;
                }
                if(turns == 9) {
                        cout << "The game is a tie!" << endl;
                        break;
                }
                do{
                if(P2power_used == 1) {
                cout << P2 << ", choose a valid position between 1 and 9." << endl;
                }
                else if(P2power_used == 0) {
                cout << P2 << ", choose a valid position between 1 and 9. Or input Q to use your power!" << endl;
                }
                getline(cin, c2);
                if(c2.length() == 1 && isdigit(c2[0])) {
                        choice2 = stoi(c2);
                }
                else if (c2 == "Q") {
                        if(P2power == 1 && turns < 2) {
                                cout << "You cannot use your power yet!" << endl;
                                c2 = "q";
                        }
                        else if (P2power == 2 && turns < 2) {
                                cout << "You cannot use your power yet!" << endl;
                                c2 = "q";
                        }
                        else if (P2power_used == 1) {
                                cout << "You cannot use your power twice!" << endl;
                                c2 = "q";
                        }
                        else {
                                break;
                        }
                }

                }while(choice2 <=0 || choice2 >=10 || Positions[choice2 -1] == mark1 || Positions[choice2 -1] == mark2 || (c2 != "Q" && !isdigit(c2[0])));

                if(c2 != "Q") {
                Positions[choice2 - 1] = mark2;
                turns++;
                }
                else if(c2 == "Q" && P2power_used == 0 && P2power == 1 && turns >= 2) {
                        Paladin(Positions, P2, mark2, mark1);
                        P2power_used  = 1;
                }
                else if(c2 == "Q" && P2power_used == 0 && P2power == 2 && turns >= 2) {
                        Alchemist(Positions, P2, mark2, mark1);
                        P2power_used = 1;
                }
                printGrid(Positions);
                if(turns == 9 && Winner(Positions, mark1, mark2, P1, P2) == false){
                        cout << "The game is a tie!" << endl;;
                        break;
                }
        }while(!Winner(Positions, mark1, mark2, P1, P2));
}
int main() {
        char mark1;
        char mark2;
        string c1;
        string c2;
        string gOption;
        string playAgain;
        int choice1;
        int choice2;
        int option;
        string P1 = "Player 1";
        string P2 = "Player 2";
        do{
        char Positions[9] = {'1','2','3','4','5','6','7','8','9'};
        int turns = 0;
        do{
        cout << "Welcome to TicTacToe! Please select a gamemode: \n (1) Regular TicTacToe \n (2) Battle TicTacToe" << endl;
        getline(cin, gOption);
        if(isdigit(gOption[0]) && gOption.length() == 1) {
                option = stoi(gOption);
        }
        }while(!isdigit(gOption[0]) ||  gOption.length() > 1 || (option != 1 && option != 2));
        GameStart(P1, P2, mark1, mark2, Positions);
        totalCount++;
        if(option == 1) {
                RegularTTT(P1, P2, mark1, mark2, Positions, c1, c2, choice1, choice2, turns);
        }
        else if (option == 2) {
                BattleTTT(P1, P2, mark1, mark2, Positions, c1, c2, choice1, choice2, turns);
        }
        cout << "Would you like to play again? (Y or N)" << endl;
        getline(cin, playAgain);
        }while(playAgain == "Yes" || playAgain == "yes" || playAgain == "Y" || playAgain == "y");
        tie = totalCount - (player1Won + player2Won);
        string fileName = "tttresult.csv";
        ofstream csvfile("tttresult.csv");
        csvfile << "Total Games Played,Player 1 Wins,Player 2 Wins, Ties"<< endl;
        csvfile << totalCount << ","<< player1Won<<","<< player2Won<<","<<tie<<endl;
        csvfile.close();
        cout << "Succesfully saved to disk as 'tttresult.csv'!" << endl;
        return 0;
}

