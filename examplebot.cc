#include "examplebot.h"

#include <ctime>
#include <math.h>
#include <string>

#include "rlbot/bot.h"
#include "rlbot/color.h"
#include "rlbot/interface.h"
#include "rlbot/rlbot_generated.h"
#include "rlbot/scopedrenderer.h"
#include "rlbot/statesetting.h"

#define PI 3.1415

ExampleBot::ExampleBot(int _index, int _team, std::string _name)
    : Bot(_index, _team, _name) {
  rlbot::GameState gamestate = rlbot::GameState();

  gamestate.ballState.physicsState.location = {0, 0, 1000};
  gamestate.ballState.physicsState.velocity = {0, 0, 5000};

  rlbot::CarState carstate = rlbot::CarState();
  carstate.physicsState.location = {0, 500, 1000};
  carstate.physicsState.velocity = {500, 1000, 1000};
  carstate.physicsState.angularVelocity = {1, 2, 3};

  carstate.boostAmount = 50;

  gamestate.carStates[_index] = carstate;

  rlbot::Interface::SetGameState(gamestate);
}

ExampleBot::~ExampleBot() {
  // Free your allocated memory here.
}

rlbot::Controller ExampleBot::GetOutput(rlbot::GameTickPacket gametickpacket) {

  rlbot::flat::Vector3 ballLocation =
      *gametickpacket->ball()->physics()->location();
  rlbot::flat::Vector3 ballVelocity =
      *gametickpacket->ball()->physics()->velocity();
  rlbot::flat::Vector3 carLocation =
      *gametickpacket->players()->Get(index)->physics()->location();
  rlbot::flat::Rotator carRotation =
      *gametickpacket->players()->Get(index)->physics()->rotation();

  // Calculate the velocity of the ball.
  float velocity = sqrt(ballVelocity.x() * ballVelocity.x() +
                        ballVelocity.y() * ballVelocity.y() +
                        ballVelocity.z() * ballVelocity.z());

  // This renderer will build and send the packet once it goes out of scope.
  rlbot::ScopedRenderer renderer("test");

  // Load the ballprediction into a vector to use for rendering.
  std::vector<const rlbot::flat::Vector3 *> points;

  rlbot::BallPrediction ballprediction = GetBallPrediction();

  for (uint32_t i = 0; i < ballprediction->slices()->size(); i++) {
    points.push_back(ballprediction->slices()->Get(i)->physics()->location());
  }

  renderer.DrawPolyLine3D(rlbot::Color::red, points);

  renderer.DrawString2D("Hello world!", rlbot::Color::green,
                        rlbot::flat::Vector3{10, 10, 0}, 4, 4);
  renderer.DrawString3D(std::to_string(velocity), rlbot::Color::magenta,
                        ballLocation, 2, 2);

  // Calculate to get the angle from the front of the bot's car to the ball.
  double botToTargetAngle = atan2(ballLocation.y() - carLocation.y(),
                                  ballLocation.x() - carLocation.x());
  double botFrontToTargetAngle = botToTargetAngle - carRotation.yaw();
  // Correct the angle.
  if (botFrontToTargetAngle < -PI)
    botFrontToTargetAngle += 2 * PI;
  if (botFrontToTargetAngle > PI)
    botFrontToTargetAngle -= 2 * PI;

  rlbot::Controller controller{0};

  // Decide which way to steer in order to get to the ball.
  if (botFrontToTargetAngle > 0)
    controller.steer = 1;
  else
    controller.steer = -1;

  controller.throttle = 1.0f;

  return controller;
}
