#include <iostream>
#include<ostream>
#include <vector>
#include<string>
#include<cstring>

using namespace std;


class Tic_Tac_Toe{
    public:

    void draw_board(vector<vector<string>> board_contents){
    // draw board with the contents of 2d vector.
        string row_line = "+-+-+-+";
        string column_line = "|";
        for(int i = 0; i < 3; i++){
                cout<<row_line<<endl;
        for(int j = 0; j < 3; j++){

            cout<<column_line;
            cout << board_contents[i][j] ;
        }
        cout<<column_line;
        cout<< endl;
    }
    cout<<row_line<<endl;

    }


    void reset_board(vector<vector<string>> &board_contents){
    // resets the items of 2d vector and draws an empty board.
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            board_contents[i][j] = " ";
        }
    }
    draw_board(board_contents);
    }

    bool check_for_winner (vector<vector<string>> board){
    // checks all the cases required to win a tic tac toe game and returns true if win.
    if (((board[0][0]==board[0][1]) && (board[0][1] == board[0][2])) && (board[0][2] != " ") ){
        cout << board[0][2]<<" wins!"<<endl;
        return true;
    }
    else if (((board[1][0]==board[1][1]) && (board[1][1] == board[1][2])) && (board[1][2] != " ") ){
        cout << board[1][2]<<" wins!"<<endl;
        return true;
    }
    else if (((board[2][0]==board[2][1]) && (board[2][1] == board[2][2])) && (board[2][2] != " ") ){
        cout << board[2][2]<<" wins!"<<endl;
        return true;
    }
    else if ((board[0][0]==board[1][0]) && (board[1][0] == board[2][0]) && (board[2][0] != " ") ){
        cout << board[2][0]<<" wins!"<<endl;
        return true;
    }
    else if (((board[0][1]==board[1][1]) && (board[1][1] == board[2][1])) && (board[2][1] != " ") ){
        cout << board[2][1]<<" wins!"<<endl;
        return true;
    }
    else if (((board[0][2]==board[1][2]) && (board[1][2] == board[2][2])) && (board[2][2] != " ") ){
        cout << board[2][2]<<" wins!"<<endl;
        return true;
    }
    else if (((board[0][0]==board[1][1]) && (board[1][1] == board[2][2])) && (board[2][2] != " ") ){
        cout << board[2][2]<<" wins!"<<endl;
        return true;
    }
    else if (((board[0][2]==board[1][1]) && (board[1][1] == board[2][0])) && (board[2][0] != " ") ){
        cout << board[2][0]<<" wins!"<<endl;
        return true;
    }
    else{
        return false;
    }


    }

    bool apply_moves(vector<vector<string>> &board, string location, string player){
    // applies move to certain location and if the location is occupied return false with error message.
    if (location =="A"){
        if (board[0][0] != " "){
                cout<<"Illegal Move! Block occupied by "<< board[0][0]<<endl;
            return false;
        }else{
            board[0][0] = player;
            draw_board(board);
            return true;
        }
    }
    if (location =="B"){
        if (board[0][1] != " "){
                cout<<"Illegal Move! Block occupied by "<< board[0][1]<<endl;
            return false;
        }else{
            board[0][1] = player;
            draw_board(board);
            return true;
        }

    }
    if (location =="C"){
        if (board[0][2] != " "){
                cout<<"Illegal Move! Block occupied by "<< board[0][2]<<endl;
            return false;
        }
        else{
            board[0][2] = player;
            draw_board(board);
            return true;
        }

    }
    if (location =="D"){
        if (board[1][0] != " "){
                cout<<"Illegal Move! Block occupied by "<< board[1][0]<<endl;
            return false;
        }else{
            board[1][0] = player;
            draw_board(board);
            return true;
        }

    }
    if (location =="E"){
        if (board[1][1] != " "){
                cout<<"Illegal Move! Block occupied by "<< board[1][1]<<endl;
            return false;
        }
        else{
            board[1][1] = player;
            draw_board(board);
            return true;
        }

    }
    if (location =="F"){
        if (board[1][2] != " "){
                cout<<"Illegal Move! Block occupied by "<< board[1][2]<<endl;
            return false;
        }else{
            board[1][2] = player;
            draw_board(board);
            return true;
        }

    }
    if (location =="G"){
        if (board[2][0] != " "){
                cout<<"Illegal Move! Block occupied by "<< board[2][0]<<endl;
            return false;
        }else{
            board[2][0] = player;
            draw_board(board);
            return true;
        }

    }
    if (location =="H"){
        if (board[2][1] != " "){
                cout<<"Illegal Move! Block occupied by "<< board[2][1]<<endl;
            return false;
        }else{
            board[2][1] = player;
            draw_board(board);
            return true;
        }

    }
    if (location =="I"){
        if (board[2][2] != " "){
                cout<<"Illegal Move! Block occupied by "<< board[2][2]<<endl;
            return false;
        }else{
            board[2][2] = player;
            draw_board(board);
            return true;
        }

    }

    }


};

int Play_game(vector<vector<string>> board_contents){
    // function that does I/O for the game
Tic_Tac_Toe tic;
string command ="";
int moves = 0;
//breaks after all the moves is over.
while (moves<9){

    cout<<"Player X: "<<endl;
    cin>>command;
    for (auto & c: command) c = toupper(c);
    if (command =="RESET"){
        return 0;
    }
    if (command =="EXIT"){
        exit(0);
    }
    while(!tic.apply_moves(board_contents,command, "X")){
        cout<<"Player X: "<<endl;
        cin>>command;
        for (auto & c: command) c = toupper(c);
    }
    moves+=1;
    if (tic.check_for_winner(board_contents)){
        return 0;
    }
    if (moves ==9){
    break;
    }

    cout<<"Player O: "<<endl;
    cin>>command;

    for (auto & c: command) c = toupper(c);
    if (command =="RESET"){
        return 0;
    }
    if (command =="EXIT"){
        exit(0);
    }

    while(!tic.apply_moves(board_contents,command, "O")){
        cout<<"Player O: "<<endl;
        cin>>command;
        for (auto & c: command) c = toupper(c);
    }
    moves+=1;
    if (tic.check_for_winner(board_contents)){
        return 0;
    }



}
cout<<"Game Over! Out of Moves, Tie!"<<endl;
return 0;
}

int main(){
// main function to display the game rules and start the game by calling Play_game function according to user input.
Tic_Tac_Toe tic;
string cmd;
vector <vector<string>> board_contents ( 3, vector<string>(3, " "));
cout<< "The Board will look like : "<<endl;
tic.draw_board(board_contents);

cout<<"\nThe Squares are named :"<<endl;
cout<<"A B C"<<endl;
cout<<"D E F"<<endl;
cout<<"G H I"<<endl;
cout<<"\nTo claim a square, type the letter associated with it during the game. "<<endl;
cout<<"To reset the board at any time of game, type reset."<<endl;
cout<<"To exit game while playing, type exit."<<endl;
cout<<"\n"<<endl;

Play_game(board_contents);
cout<<"Play again(Y/N)"<<endl;
cin>>cmd;
while(cmd !="N"){
    tic.reset_board(board_contents);
    Play_game(board_contents);
    cout<<"Play again(Y/N)"<<endl;
    cin>>cmd;
}


}
