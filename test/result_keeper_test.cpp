#include <result_keeper.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;
using namespace tennis;

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
  ASSERT_THAT(resultKeeper.result(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperTest, ApplyPointsInsideOneGame) {
  resultKeeper.firstPlayerPoint();
  EXPECT_THAT(resultKeeper.result(),
              std::string("0 | 0 | 15 \n") + std::string("0 | 0 | 0 "));

  resultKeeper.secondPlayerPoint();
  EXPECT_THAT(resultKeeper.result(),
              std::string("0 | 0 | 15 \n") + std::string("0 | 0 | 15 "));

  resultKeeper.firstPlayerPoint();
  EXPECT_THAT(resultKeeper.result(),
              std::string("0 | 0 | 30 \n") + std::string("0 | 0 | 15 "));

  resultKeeper.secondPlayerPoint();
  EXPECT_THAT(resultKeeper.result(),
              std::string("0 | 0 | 30 \n") + std::string("0 | 0 | 30 "));

  resultKeeper.firstPlayerPoint();
  EXPECT_THAT(resultKeeper.result(),
              std::string("0 | 0 | 40 \n") + std::string("0 | 0 | 30 "));

  resultKeeper.secondPlayerPoint();
  EXPECT_THAT(resultKeeper.result(),
              std::string("0 | 0 | 40 \n") + std::string("0 | 0 | 40 "));
}

TEST_F(ResultKeeperTestWinningGamePoint, ApplyFourPointsToFirstPlayer) {
  addFourPointsToFirstPlayer();
  ASSERT_THAT(resultKeeper.result(),
              std::string("0 | 1 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperTestWinningGamePoint,
       ApplyOneGamePointToFirstPlayerAndOnePointToSecondPlayer) {
  resultKeeper.secondPlayerPoint();
  addFourPointsToFirstPlayer();
  ASSERT_THAT(resultKeeper.result(),
              std::string("0 | 1 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperTestWinningGamePoint,
       ApplyOneGamePointToFirstPlayerAndTwoPointToSecondPlayer) {
  resultKeeper.secondPlayerPoint();
  resultKeeper.secondPlayerPoint();

  addFourPointsToFirstPlayer();
  ASSERT_THAT(resultKeeper.result(),
              std::string("0 | 1 | 0 \n") + std::string("0 | 0 | 0 "));
}

TEST_F(ResultKeeperTestWinningGamePoint, ApplyFourPointsToSecondPlayer) {
  addFourPointsToSecondPlayer();
  ASSERT_THAT(resultKeeper.result(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 1 | 0 "));
}

TEST_F(ResultKeeperTestWinningGamePoint,
       ApplyFourPointsToSecondPlayerAndOnePointToFirstPlayer) {
  resultKeeper.firstPlayerPoint();
  addFourPointsToSecondPlayer();
  ASSERT_THAT(resultKeeper.result(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 1 | 0 "));
}

TEST_F(ResultKeeperTestWinningGamePoint,
       ApplyFourPointsToSecondPlayerAndTwoPointsToFirstPlayer) {
  resultKeeper.firstPlayerPoint();
  resultKeeper.firstPlayerPoint();
  addFourPointsToSecondPlayer();
  ASSERT_THAT(resultKeeper.result(),
              std::string("0 | 0 | 0 \n") + std::string("0 | 1 | 0 "));
}
