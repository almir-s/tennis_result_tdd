#include <ResultKeeper.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

class ResultKeeperTest : public Test {
  public:
  ResultKeeper resultKeeper;
};

class ResultKeeperTestWinningGamePoint : public Test {
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
};

TEST_F(ResultKeeperTest, ZeroZeroOnCreateResultKeeper) {
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperTest, ApplyPointsInsideOneGame) {
  resultKeeper.firstPlayerPoint();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 15 \n") + std::string("0 | 0 | 0 "));

  resultKeeper.secondPlayerPoint();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 15 \n") + std::string("0 | 0 | 15 "));

  resultKeeper.firstPlayerPoint();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 30 \n") + std::string("0 | 0 | 15 "));
  
  resultKeeper.secondPlayerPoint();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 30 \n") + std::string("0 | 0 | 30 "));
  
  resultKeeper.firstPlayerPoint();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 40 \n") + std::string("0 | 0 | 30 "));
  
  resultKeeper.secondPlayerPoint();
  EXPECT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 40 \n") + std::string("0 | 0 | 40 "));
}

// TEST_F(ResultKeeperTest, ApplyOnePointToBothPlayers) {
//   resultKeeper.firstPlayerPoint();
//   resultKeeper.secondPlayerPoint();
//   ASSERT_THAT(resultKeeper.getResult(),
//               std::string("0 | 0 | 15 \n") + std::string("0 | 0 | 15 "));
// }

// TEST_F(ResultKeeperTest, ApplyTwoPointsToFirstPlayerAndOnePointToSecond) {
//   resultKeeper.firstPlayerPoint();
//   resultKeeper.secondPlayerPoint();
//   resultKeeper.firstPlayerPoint();
//   ASSERT_THAT(resultKeeper.getResult(),
//               std::string("0 | 0 | 30 \n") + std::string("0 | 0 | 15 "));
// }

// TEST_F(ResultKeeperTest, ApplyTwoPointsToBothPlayers) {
//   resultKeeper.firstPlayerPoint();
//   resultKeeper.secondPlayerPoint();
//   resultKeeper.firstPlayerPoint();
//   resultKeeper.secondPlayerPoint();
//   ASSERT_THAT(resultKeeper.getResult(),
//               std::string("0 | 0 | 30 \n") + std::string("0 | 0 | 30 "));
// }

// TEST_F(ResultKeeperTest, ApplyThreePointsToFirstPlayerAndTwoToSecondPlayer) {
//   resultKeeper.firstPlayerPoint();
//   resultKeeper.secondPlayerPoint();
//   resultKeeper.firstPlayerPoint();
//   resultKeeper.secondPlayerPoint();
//   resultKeeper.firstPlayerPoint();
//   ASSERT_THAT(resultKeeper.getResult(),
//               std::string("0 | 0 | 40 \n") + std::string("0 | 0 | 30 "));
// }

// TEST_F(ResultKeeperTest, ApplyThreePointsToBothPlayes) {
//   resultKeeper.firstPlayerPoint();
//   resultKeeper.secondPlayerPoint();
//   resultKeeper.firstPlayerPoint();
//   resultKeeper.secondPlayerPoint();
//   resultKeeper.firstPlayerPoint();
//   resultKeeper.secondPlayerPoint();
//   ASSERT_THAT(resultKeeper.getResult(),
//               std::string("0 | 0 | 40 \n") + std::string("0 | 0 | 40 "));
// }

TEST_F(ResultKeeperTestWinningGamePoint, ApplyFourPointsToFirstPlayer) {
  addFourPointsToFirstPlayer();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 1 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperTestWinningGamePoint, ApplyOneGamePointToFirstPlayerAndOnePointToSecondPlayer) {
  resultKeeper.firstPlayerPoint();
  resultKeeper.firstPlayerPoint();
  resultKeeper.firstPlayerPoint();

  resultKeeper.secondPlayerPoint();
  resultKeeper.firstPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 1 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperTestWinningGamePoint, ApplyOneGamePointToFirstPlayerAndTwoPointToSecondPlayer) {
  resultKeeper.firstPlayerPoint();
  resultKeeper.firstPlayerPoint();
  resultKeeper.firstPlayerPoint();

  resultKeeper.secondPlayerPoint();
  resultKeeper.secondPlayerPoint();
  resultKeeper.firstPlayerPoint();
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 1 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperTestWinningGamePoint, ApplyFourPointsToSecondPlayer) {
 addFourPointsToSecondPlayer(); 
  ASSERT_THAT(resultKeeper.getResult(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 1 | 0 "));
}
