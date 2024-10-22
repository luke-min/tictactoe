#include <iostream>
#include <vector>
#include "functions.hpp"

int main() {
  // Declare board
  introduction();

  // Initialize some variables
  bool is_game_running = true;
  bool is_player_As_turn = true;
  
  // Initialize board
  std::vector<char> board(9);
  for (int i = 0; i < board.size(); i++) {
    board[i] = ' ';
  }

  // while loop
  while (is_game_running){
    // Play one turn
    board = play_one_turn(is_player_As_turn, board);

    // Draw board
    draw(board);

    // Check winner
    is_game_running = check_winner(board);

    // Check is board full
    is_game_running = check_board_full(is_game_running, board);

    // switch turn
    if (is_player_As_turn) {
      is_player_As_turn = false;
    }
    else {
      is_player_As_turn = true;
    }

  }
  
}