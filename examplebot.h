#pragma once

#include "rlbot/bot.h"

class ExampleBot : public rlbot::Bot {
public:
  ExampleBot(int _index, int _team, std::string _name);
  ~ExampleBot();
  rlbot::Controller GetOutput(rlbot::GameTickPacket gametickpacket) override;
};
