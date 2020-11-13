#ifndef RESULT_KEEPER_H
#define RESULT_KEEPER_H

#include <map>
#include <string>

namespace tennis {
struct PlayerStats {
  std::string points = "0";
  int gamePoints = 0;
  int setPoints = 0;

  std::string getScore() const {
    return std::to_string(setPoints) + " | " + std::to_string(gamePoints) +
           " | " + points + " ";
  }
};

class ResultKeeper {
  PlayerStats firstPlayer;
  PlayerStats secondPlayer;

  std::map<std::string, std::string> nextPoint = {
      {"0", "15"}, {"15", "30"}, {"30", "40"}, {"40", "A"}};

  bool isMatchOver() {
    return firstPlayer.setPoints == 3 || secondPlayer.setPoints == 3;
  }

  void applyPointToPlayer(PlayerStats& scorer, PlayerStats& opponent) {
    if (isMatchOver()) return;

    if ((scorer.points == "40" &&
         (opponent.points != "40" && opponent.points != "A")) ||
        (scorer.points == "A" && opponent.points == "40")) {
      scorer.points = "0";
      opponent.points = "0";

      if ((scorer.gamePoints == 5 && opponent.gamePoints < 5) ||
          (scorer.gamePoints > 5 && scorer.gamePoints > opponent.gamePoints)) {
        scorer.setPoints++;
        scorer.gamePoints = 0;
        opponent.gamePoints = 0;
        return;
      } else if (scorer.gamePoints == 5 && opponent.gamePoints >= 5) {
        scorer.gamePoints++;
        return;
      }
      scorer.gamePoints++;
      return;
    } else if (scorer.points == "40" && opponent.points == "A") {
      opponent.points = "40";
      return;
    }
    scorer.points = nextPoint[scorer.points];
  }

  public:
  std::string result() const {
    return firstPlayer.getScore() + "\n" + secondPlayer.getScore();
  }

  void firstPlayerPoint() { applyPointToPlayer(firstPlayer, secondPlayer); }

  void secondPlayerPoint() { applyPointToPlayer(secondPlayer, firstPlayer); }
};
}  // namespace tennis
#endif
