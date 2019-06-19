#include "rlbot_generated.h"

#include "examplebot.h"

#include "bot.h"
#include "botmanager.h"
#include "interface.h"

#include <iostream>

int main(int argc, char** argv) {
  int botIndex = 0;
  int botTeam = 0;
  std::string botName = "";

  std::string interface_dll = std::string(DLLNAME);

  // parse arguments
  for (int i = 1; i < argc; ++i) {
    std::string arg(argv[i]);

    if ((arg == "-index") && i + 1 < argc) {
      botIndex = atoi(argv[++i]);
    } else if ((arg == "-team") && i + 1 < argc) {
      botTeam = atoi(argv[++i]);
    } else if ((arg == "-name") && i + 1 < argc) {
      botName = std::string(argv[++i]);
    } else if ((arg == "-dll-path") && i + 1 < argc) {
      interface_dll = std::string(argv[++i]) + "\\" + DLLNAME;
    } else {
      std::cerr << "Bad option: '" << arg << "'" << std::endl;
    }
  }

  Interface::LoadInterface(interface_dll);

  while (!Interface::IsInitialized()) {
  }

  ExampleBot b(botIndex, botTeam, botName);

  BotManager::RunSingleBot(&b);

  return 0;
}
