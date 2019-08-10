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
  rlbotcpp::platform::SetWorkingDirectory(
      rlbotcpp::platform::GetExecutableDirectory());
  uint16_t port = getPortFromFile("port.cfg");

  std::string interface_dll = std::string(DLLNAME);

  // parse arguments
  for (int i = 1; i < argc; ++i) {
    std::string arg(argv[i]);

    if ((arg == "-dll-path") && i + 1 < argc) {
      interface_dll = std::string(argv[++i]) + "\\" + DLLNAME;
    } else {
      std::cerr << "Bad option: '" << arg << "'" << std::endl;
    }
  }

  rlbotcpp::Interface::LoadInterface(interface_dll);

  while (!rlbotcpp::Interface::IsInitialized()) {
    rlbotcpp::platform::SleepMilliseconds(1);
  }

  rlbotcpp::BotManager<ExampleBot> botmanager =
      rlbotcpp::BotManager<ExampleBot>();
  botmanager.StartBotServer(port);

  return 0;
}
