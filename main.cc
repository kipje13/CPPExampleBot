#include "rlbot_generated.h"

#include "examplebot.h"

#include "bot.h"
#include "botmanager.h"
#include "interface.h"
#include "platform.h"

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

uint16_t getPortFromFile(std::string filename) {
  std::ifstream file;
  file.open(filename);
  std::string line;
  std::getline(file, line);
  file.close();

  return std::stoi(line);
}

int main(int argc, char **argv) {
  // Set the working directory to the directory of this executable so we can use
  // relative paths.
  rlbot::platform::SetWorkingDirectory(
      rlbot::platform::GetExecutableDirectory());

  // Read the port that we use for receiving bot spawn messages.
  uint16_t port = getPortFromFile("port.cfg");

  rlbot::BotManager<ExampleBot> botmanager;
  botmanager.StartBotServer(port);

  return 0;
}
