// StubInstTests.cpp
#include <gtest/gtest.h>

#include "StubInst.h"
#include "Message.h"
#include "InstModelTests.h"
#include "ModelTests.h"

#include <string>

using namespace std;

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
class StubInstTest : public ::testing::Test {
  protected:
    StubInst* src_inst;

    virtual void SetUp(){
      src_inst = new StubInst();
    };

    virtual void TearDown() {
      delete src_inst;
    }
};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Model* StubInstModelConstructor(){
  return dynamic_cast<Model*>(new StubInst());
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
InstModel* StubInstConstructor(){
  return dynamic_cast<InstModel*>(new StubInst());
}


//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_F(StubInstTest, InitialState) {
  // Test things about the initial state of the inst here
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_F(StubInstTest, Print) {
  EXPECT_NO_THROW(string s = src_inst->str());
  // Test StubInst specific aspects of the print method here
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_F(StubInstTest, ReceiveMessage) {
  msg_ptr msg;
  // Test StubInst specific behaviors of the receiveMessage function here
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_F(StubInstTest, Tick) {
  int time = 1;
  EXPECT_NO_THROW(src_inst->handleTick(time));
  // Test StubInst specific behaviors of the handleTick function here
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
TEST_F(StubInstTest, Tock) {
  int time = 1;
  EXPECT_NO_THROW(src_inst->handleTick(time));
  // Test StubInst specific behaviors of the handleTock function here
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
INSTANTIATE_TEST_CASE_P(StubInst, InstModelTests, Values(&StubInstConstructor));
INSTANTIATE_TEST_CASE_P(StubInst, ModelTests, Values(&StubInstModelConstructor));

