#ifndef ResultKeeper_h
#define ResultKeeper_h

#include <map>
#include <string>

class ResultKeeper {
  std::string firstPlayerPoints = "0";
  std::string secondPlayerPoints = "0";

  int firstPlayerGamePoints = 0;
  int secondPlayerGamePoints = 0;

  int firstPlayerSetPoints = 0;
  int secondPlayerSetPoints = 0;

  std::map<std::string, std::string> nextPoint = {
      {"0", "15"}, {"15", "30"}, {"30", "40"}, {"40", "A"}};

  public:
  ResultKeeper(){};

  // ResultKeeper(std::string firstPlayerPoints, std::string secondPlayerPoints,
  //              int firstPlayerGamePoints, int secondPlayerGamePoints,
  //              int firstPlayerSetPoints, int secondPlayerSetPoints)
  //     : firstPlayerPoints(firstPlayerPoints),
  //       secondPlayerPoints(secondPlayerPoints),
  //       firstPlayerGamePoints(firstPlayerGamePoints),
  //       secondPlayerGamePoints(secondPlayerGamePoints),
  //       firstPlayerSetPoints(firstPlayerSetPoints),
  //       secondPlayerSetPoints(secondPlayerSetPoints) {}

  std::string getResult() {
    return std::to_string(firstPlayerSetPoints) + " | " +
           std::to_string(firstPlayerGamePoints) + " | " + firstPlayerPoints +
           " \n" +

           std::to_string(secondPlayerSetPoints) + " | " +
           std::to_string(secondPlayerGamePoints) + " | " + secondPlayerPoints +
           " ";
  }

  void firstPlayerPoint() {
    if(firstPlayerPoints == "40") {
      firstPlayerPoints = "0";
      secondPlayerPoints = "0";
      firstPlayerGamePoints++;
      return;
    } 

    firstPlayerPoints = nextPoint[firstPlayerPoints];
  }

  void secondPlayerPoint() {
    secondPlayerPoints = nextPoint[secondPlayerPoints];
  }
};

#endif