#pragma once

#include "bot.h"

class ExampleBot : public rlbot::Bot {
public:
  ExampleBot(int _index, int _team, std::string _name);
  rlbot::Controller
  GetOutput(const rlbot::flat::GameTickPacket *gameTickPacket,
            const rlbot::flat::FieldInfo *fieldInfo,
            const rlbot::flat::BallPrediction *ballPrediction);
};
