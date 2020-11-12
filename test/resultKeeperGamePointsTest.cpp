
#include <ResultKeeper.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

class ResultKeeperWinningGamePointFromAdvantage : public Test {
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

  void addFiveGamePointsToFirstPlayer() {
    addFourPointsToFirstPlayer();
    addFourPointsToFirstPlayer();
    addFourPointsToFirstPlayer();
    addFourPointsToFirstPlayer();
    addFourPointsToFirstPlayer();
  }

  void addFiveGamePointsToSecondPlayer() {
    addFourPointsToSecondPlayer();
    addFourPointsToSecondPlayer();
    addFourPointsToSecondPlayer();
    addFourPointsToSecondPlayer();
    addFourPointsToSecondPlayer();
  }

  void addSetPointToFirstPlayer() {
    addFiveGamePointsToFirstPlayer();
    addFourPointsToFirstPlayer();
  }

  void addSetPointToSecondPlayer() {
    addFiveGamePointsToSecondPlayer();
    addFourPointsToSecondPlayer();
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

class ResultKeeperWinningGamePointsTest
    : public ResultKeeperWinningGamePointFromAdvantage {
  public:
  void SetUp() override {}
};

TEST_F(ResultKeeperWinningGamePointFromAdvantage, FirstPlayerAdventage) {
  resultKeeper.firstPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | A \n") + std::string("0 | 0 | 40 "));
}

TEST_F(ResultKeeperWinningGamePointFromAdvantage,
       FirstPlayerWinsGamePointAfterAdventage) {
  resultKeeper.firstPlayerPoint();
  resultKeeper.firstPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 1 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointFromAdvantage, SecondPlayerAdventage) {
  resultKeeper.secondPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 40 \n") + std::string("0 | 0 | A "));
}

TEST_F(ResultKeeperWinningGamePointFromAdvantage,
       SecondPlayerWinsGamePointAfterAdventage) {
  resultKeeper.secondPlayerPoint();
  resultKeeper.secondPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 1 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointFromAdvantage, BothPlayersScoreAdvantage) {
  resultKeeper.firstPlayerPoint();
  resultKeeper.secondPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 40 \n") + std::string("0 | 0 | 40 "));
}

TEST_F(ResultKeeperWinningGamePointFromAdvantage,
       BothPlayersScoreAdvantageReverseOrder) {
  resultKeeper.secondPlayerPoint();
  resultKeeper.firstPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 40 \n") + std::string("0 | 0 | 40 "));
}

TEST_F(ResultKeeperWinningGamePointsTest, FirstPlayerScoresUpToFiveGamePoints) {
  addFourPointsToFirstPlayer();
  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 2 | 0 \n") + std::string("0 | 0 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 3 | 0 \n") + std::string("0 | 0 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 4 | 0 \n") + std::string("0 | 0 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 5 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointsTest, SecondPlayerScoresUpToFivePoints) {
  addFourPointsToSecondPlayer();
  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 2 | 0 "));

  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 3 | 0 "));

  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 4 | 0 "));

  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 5 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointsTest,
       FirstPlayerWinsSixthGamePointAndWinSetPoint) {
  addFiveGamePointsToFirstPlayer();
  addFourPointsToFirstPlayer();

  ASSERT_THAT(resultKeeper.getResult(),
              std::string("1 | 0 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointsTest,
       FirstPlayerWinsSixthGamePointSecondPlayerScoresUpToFourGamePoints) {
  addFiveGamePointsToFirstPlayer();
  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 5 | 0 \n") + std::string("0 | 1 | 0 "));

  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 5 | 0 \n") + std::string("0 | 2 | 0 "));
  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 5 | 0 \n") + std::string("0 | 3 | 0 "));
  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 5 | 0 \n") + std::string("0 | 4 | 0 "));

  addFourPointsToFirstPlayer();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("1 | 0 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointsTest,
       SecondPlayerWinsSixthGamePointAndWinSetPoint) {
  addFiveGamePointsToSecondPlayer();
  addFourPointsToSecondPlayer();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("1 | 0 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointsTest,
       SecondPlayerWinsSixGamePointsFirstPlayerWinsUpToFourGamePoints) {
  addFiveGamePointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 5 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 1 | 0 \n") + std::string("0 | 5 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 2 | 0 \n") + std::string("0 | 5 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 3 | 0 \n") + std::string("0 | 5 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 4 | 0 \n") + std::string("0 | 5 | 0 "));

  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("1 | 0 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointsTest,
       FirstPlayerWinsSixGamePointsSecondPlayerWinsFiveGamePoints) {
  addFiveGamePointsToFirstPlayer();
  addFiveGamePointsToSecondPlayer();

  addFourPointsToFirstPlayer();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 6 | 0 \n") + std::string("0 | 5 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointsTest,
       FirstPlayerWinsSevenGamePointsSecondPlayerWinsFiveGamePoints) {
  addFiveGamePointsToFirstPlayer();
  addFiveGamePointsToSecondPlayer();

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 6 | 0 \n") + std::string("0 | 5 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("1 | 0 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointsTest,
       BothPlayersWinSixGamePointsSecondPlayerWinsInTB) {
  addFiveGamePointsToFirstPlayer();
  addFiveGamePointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 5 | 0 \n") + std::string("0 | 5 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 6 | 0 \n") + std::string("0 | 5 | 0 "));

  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 6 | 0 \n") + std::string("0 | 6 | 0 "));

  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 6 | 0 \n") + std::string("0 | 7 | 0 "));

  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("1 | 0 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointsTest,
       BothPlayersWinSixGamePointsFirstPlayerWinsInTB) {
  addFiveGamePointsToFirstPlayer();
  addFiveGamePointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 5 | 0 \n") + std::string("0 | 5 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 6 | 0 \n") + std::string("0 | 5 | 0 "));

  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 6 | 0 \n") + std::string("0 | 6 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 7 | 0 \n") + std::string("0 | 6 | 0 "));

  addFourPointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 7 | 0 \n") + std::string("0 | 7 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 8 | 0 \n") + std::string("0 | 7 | 0 "));

  addFourPointsToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("1 | 0 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointsTest, PlayersWinSetPoints) {
  addSetPointToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("1 | 0 | 0 \n") + std::string("0 | 0 | 0 "));

  addSetPointToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("1 | 0 | 0 \n") + std::string("1 | 0 | 0 "));

  addSetPointToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("1 | 0 | 0 \n") + std::string("2 | 0 | 0 "));

  addSetPointToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("2 | 0 | 0 \n") + std::string("2 | 0 | 0 "));

  resultKeeper.firstPlayerPoint();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("2 | 0 | 15 \n") + std::string("2 | 0 | 0 "));

  resultKeeper.firstPlayerPoint();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("2 | 0 | 30 \n") + std::string("2 | 0 | 0 "));
}

TEST_F(ResultKeeperWinningGamePointsTest, FirstPlayerWinsTheMatch) {
  addSetPointToFirstPlayer();
  addSetPointToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("2 | 0 | 0 \n") + std::string("0 | 0 | 0 "));

  addSetPointToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("3 | 0 | 0 \n") + std::string("0 | 0 | 0 "));

  resultKeeper.firstPlayerPoint();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("3 | 0 | 0 \n") + std::string("0 | 0 | 0 "));

  resultKeeper.secondPlayerPoint();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("3 | 0 | 0 \n") + std::string("0 | 0 | 0 "));

  addFiveGamePointsToSecondPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("3 | 0 | 0 \n") + std::string("0 | 0 | 0 "));

  addSetPointToFirstPlayer();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("3 | 0 | 0 \n") + std::string("0 | 0 | 0 "));
}

