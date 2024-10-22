#include <iostream>
#include <vector>

void draw(std::vector<char> board);
void introduction();
std::vector<char> play_one_turn(bool is_player_As_turn, std::vector<char> board);
bool check_winner(std::vector<char> board);
bool check_board_full(bool is_game_running, std::vector<char> board);