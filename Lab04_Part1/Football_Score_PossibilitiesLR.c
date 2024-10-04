/*
10/03/2024
Luke Reicherter
KU ID: 3135060
EECS 348: Lab 04
Lab Session: Thursday 11:00 AM
Description: This program will ask the user for a score. If the score is less than 2, the program
ends. If the score is greater than or equal to 2, the program will print every possible combination 
of points to get that score. The program will repeat until 0 or 1 is entered.
*/

#include <stdio.h>

void rec_score_finder(int some_score, int cur_score, int a, int b, int c, int d, int e) {
    /*
    This code recursively determines each possible combination to obtain the given score.
    The variables are as follows: some_score = the user's score, cur_score = the score that is tracked recursively,
    a = the amount of TD+2pts scored, b = the amount of TD+1pts scored, c = the amount of TD's scored, d = the amount of FG's
    scored, and e = the amount of Safety's scored.
    */ 
    int TD = 6, TDand1point = 7, TDand2point = 8, Safety = 2, FG = 3;
    if ((cur_score + TDand2point)<= some_score && b == 0 && c == 0 && d == 0 && e == 0) {
        rec_score_finder(some_score, cur_score + 8, a+1, b, c, d, e);
    }
    if ((cur_score + TDand1point)<= some_score && c == 0 && d == 0 && e == 0) {
        rec_score_finder(some_score, cur_score + 7, a, b+1, c, d, e);
    }
    if ((cur_score + TD)<= some_score && d == 0 && e == 0) {
        rec_score_finder(some_score, cur_score + 6, a, b, c+1, d, e);
    }
    if ((cur_score + FG)<= some_score && e == 0) {
        rec_score_finder(some_score, cur_score + 3, a, b, c, d+1, e);
    }
    if ((cur_score + Safety)<= some_score) {
        rec_score_finder(some_score, cur_score + 2, a, b, c, d, e+1);
    }
    if (cur_score == some_score){
        printf("%d", a);
        printf(" TD+2pts, ");
        printf("%d", b);
        printf(" TD+1pt, ");
        printf("%d", c);
        printf(" TD, ");
        printf("%d", d);
        printf(" FG, ");
        printf("%d", e);
        printf(" Safety");
        printf("\n");
    }
}
int main() {
    /*
    This code initiates the loop that allows the user to input a score and recieve an output.
    It will repeat until the user inputs a 0 or 1.
    */
    int score = 0;
    int torf = 0;
    while(torf == 0) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score == 0 || score == 1){
            torf = 1;
        }
        else {
        rec_score_finder(score, 0, 0, 0, 0, 0, 0);
        }
    }
    return 0;
}