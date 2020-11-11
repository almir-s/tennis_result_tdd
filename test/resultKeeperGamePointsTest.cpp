
#include <ResultKeeper.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

class ResultKeeperGamePointsTest : public Test {
  public:
  ResultKeeper resultKeeper;

  void addFourPointsToFirstPlayer() {
    resultKeeper.firstPlayerPoint();
    resultKeeper.firstPlayerPoint();
    resultKeeper.firstPlayerPoint();
    resultKeeper.firstPlayerPoint();
  }

  void addFourPointsToSecondPlayer() {
    resultKeeper.secondPlayerPoint();
    resultKeeper.secondPlayerPoint();
    resultKeeper.secondPlayerPoint();
    resultKeeper.secondPlayerPoint();
  }

  void SetUp() override {
    resultKeeper.firstPlayerPoint();
    resultKeeper.firstPlayerPoint();
    resultKeeper.firstPlayerPoint();

    resultKeeper.secondPlayerPoint();
    resultKeeper.secondPlayerPoint();
    resultKeeper.secondPlayerPoint();
  }
};

TEST_F(ResultKeeperGamePointsTest, FirstPlayerAdventage) {
  resultKeeper.firstPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | A \n") + std::string("0 | 0 | 40 "));
}

TEST_F(ResultKeeperGamePointsTest, FirstPlayerWinsGamePointAfterAdventage) {
  resultKeeper.firstPlayerPoint();
  resultKeeper.firstPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 1 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperGamePointsTest, SecondPlayerAdventage) {
  resultKeeper.secondPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 40 \n") + std::string("0 | 0 | A "));
}

TEST_F(ResultKeeperGamePointsTest, SecondPlayerWinsGamePointAfterAdventage) {
  resultKeeper.secondPlayerPoint();
  resultKeeper.secondPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 1 | 0 "));
}

TEST_F(ResultKeeperGamePointsTest, BothPlayersScoreAdvantage) {
  resultKeeper.firstPlayerPoint();
  resultKeeper.secondPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 40 \n") + std::string("0 | 0 | 40 "));
}

TEST_F(ResultKeeperGamePointsTest, BothPlayersScoreAdvantageReverseOrder) {
  resultKeeper.secondPlayerPoint();
  resultKeeper.firstPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 40 \n") + std::string("0 | 0 | 40 "));
}
