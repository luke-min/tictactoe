#include <iostream>
#include <vector>
#include "functions.hpp"


void draw(std::vector<char> board) {

    std::cout << "     |     |      \n";

    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";

    std::cout << "\n";
}

void introduction(){
  // Start up the game
  std::cout << "Welcome to a game of tic-tac-toe!\n";

  // Here is a board
  std::cout << "Here is your board:\n";

  // Initialize a board with numbers
  std::vector<char> numbered_board(9);
  for (int i = 0; i < numbered_board.size(); i++) {
    numbered_board[i] = '0' + i;
  }

  // Draw it
  draw(numbered_board);
}

std::vector<char> play_one_turn(bool is_player_As_turn, std::vector<char> board) {
    int curr_pos_num;

    if (is_player_As_turn) {
        while (is_player_As_turn) {
            std::cout << "Player A enter your move by position number : \n";
            std::cin >> curr_pos_num;
            
            if (curr_pos_num < 0 || curr_pos_num > 9) {
                std::cout << "Out of bounds!\n";
            }
            else if (board[curr_pos_num] != ' ') {
                std::cout << "Already taken!\n";
            }
            else {
                std::cout << "Updating board...\n";
                board[curr_pos_num] = 'O';
                is_player_As_turn = false;
            }
        }
    }
    else {
        // Case 2 : Player B's turn
        while (!is_player_As_turn) {
            std::cout << "Player B enter your move by position number : \n";
            std::cin >> curr_pos_num;

            if (curr_pos_num < 0 || curr_pos_num > 9) {
                std::cout << "Out of bounds!\n";
            }
            else if (board[curr_pos_num] != ' ') {
                std::cout << "Already taken!\n";
            }
            else {
                std::cout << "Updating board...\n";
                board[curr_pos_num] = 'X';
                is_player_As_turn = true;
            }
        }
    }
    return board;
}

bool check_winner(std::vector<char> board) {
    bool is_game_running;

    // Check if somebody won:
    char winner_char = 'N';
    if (board[0] != ' ' && board[0] == board[1] && board[1] == board[2]) {
      winner_char = board[0];
    }
    else if (board[3] != ' ' && board[3] == board[4] && board[4] == board[5]){
      //
      winner_char = board[3];
    }
    else if (board[6] != ' ' && board[6] == board[7] && board[7] == board[8]){
      //
      winner_char = board[6];
    }
    else if (board[0] != ' ' && board[0] == board[3] && board[3] == board[6]){
      //
      winner_char = board[0];
    }
    else if (board[1] != ' ' && board[1] == board[4] && board[4] == board[7]){
      //
      winner_char = board[1];
    }
    else if (board[2] != ' ' && board[2] == board[5] && board[5] == board[8]){
      //
      winner_char = board[2];
    }
    else if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8]){
      //
      winner_char = board[0];
    }
    else if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6]){
      //
      winner_char = board[2];
    }
    
    // Check the winner's character
    if (winner_char == 'O') {
        std::cout << "Player A won!\n";
        is_game_running = false;
    }
    else if (winner_char == 'X') {
        std::cout << "Player B won!\n";
        is_game_running = false;
    }
    else {
        std::cout << "Game still going...\n";
        is_game_running = true;
    }
    return is_game_running;
}

bool check_board_full(bool is_game_running, std::vector<char> board) {

    bool is_full;

    if (is_game_running) {
      // Check if full
      is_full = true;
      for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
          is_full = false;
        };
      }
      
      // Print statement based on board being full or not
      if (is_full) {
        std::cout << "Board is full!\n";
        is_game_running = false;
      }
      else {
        std::cout << "Board not full!\n";
      }
    }

    return is_game_running;

} 