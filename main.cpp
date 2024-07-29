#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>

using namespace std;
using namespace chrono;

int tMove();
int hMove();
void printPositions(int, int);
void printWinner(int, int);

int main(){
    // Create Random generator. Random serie will be different for each execution
    srand(time(0));

    // Set time interval to 1 second.
    seconds interval(1);
    
    int tPos = 1;
    int hPos = 1;

    while (tPos < 70 && hPos < 70){
        auto start = chrono::steady_clock::now(); // Record the start time
        
        // Calculate new positions
        tPos += tMove();
        hPos += hMove();

        // Print new positions
        if (tPos <70 && hPos < 70){
            printPositions(tPos, hPos);
        }
         // Calculate the elapsed time
        auto end = chrono::steady_clock::now();
        this_thread::sleep_until(start + interval); // Wait for the next interval
        
        
    }
    printWinner(tPos, hPos);

    return 0;
}

int tMove(){
    int dice = 1+ rand() % 10;
    int points; 

    if (dice <=5){
        points = 3;
    } 
    else if (dice <= 7){
        points = -6;
    }
    else {
        points = 1;
    }
    return dice;
}

int hMove(){
    int dice = 1+ rand() % 10;
    int points; 

    if (dice <=2){
        points = 0;
    } 
    else if (dice <= 4){
        points = 9;
    }
    else if (dice <= 5){
        points = -12;
    }
    else if (dice <= 8){
        points = 1;
    }
    else {
        points = -2;
    }
    return dice;
}

void printPositions(int tPos, int hPos){
    string raceLine;
    string outch;
    char sp = '_';

    if (tPos < hPos) {
        string a(tPos - 1, sp);
        string b(hPos - tPos, sp);
        string c(70 - hPos, sp);
        raceLine = a + "T" + b + "H" + c;
        outch = "";
    }
    else if (hPos < tPos){
        string a(hPos - 1, sp);
        string b(tPos - hPos, sp);
        string c(70 - tPos, sp);
        raceLine = a + "H" + b + "T" + c;
        outch = "";
    }
    else {
        string a(tPos - 1, sp);
        string b(70 - tPos, sp);
        string c= "";
        raceLine = a + "T" + b  + c;
        outch = a + "OUTCH";
    }

    cout << raceLine << "\n" << outch << endl;
}

void printWinner(int tPos, int hPos){
    if (tPos >=70){
        cout << "TORTOISE WINS\n\n";
    }
    else {
        cout << "HARE WINS\n\n";
    }
}