# CPPExampleBot

## How to use:
 - Clone this repository by running: `git clone https://github.com/kipje13/CPPExampleBot.git --recursive`
 - Make sure you have CMake. If you don't have it, visit https://cmake.org/download/ and run the Windows win64-x64 Installer.
 - Make sure you have Visual Studio 2017. You can get it from https://visualstudio.microsoft.com/vs/older-downloads/.
 - In a command prompt (use a fresh one if you just installed cmake), navigate to the folder and run `cmake .`
 - Open Visual Studio 2017 and open the .sln file which now exists in the folder.
 - Confirm that Build->Build Solution works.
 - Right click on CPPExampleBot in the solution explorer and choose 'Set as StartUp Project'
 - Start a match by executing `rlbot/run.bat`
 - Choose Debug->Start Debugging (or F5), or press the green play button in Visual Studio.
 - Open up examplebot.cc and start changing stuff! Visual Studio has a restart button you can press (or Ctrl+Shift+F5) when you want to recompile and try your new changes.
 
## Auto-start
The rlbot framework has the ability to launch the bot executable automatically. This is usefull when sharing your bot and usually required when you enter a tournament.

In order to get auto-starting to work you will need to do the following things.
 - Build your bot executable.
 - Set the `cpp_executable_path` field in `rlbot/CppPythonAgent.cfg` so it points to the bot executable. It is recommended to copy your bot executable to the `rlbot` folder to make this process easier.
 
## Notes:
  - People might have issues when trying to run your bot if you have compiled it in debug mode. It is better to compile in release mode when you want to share your bot with others.
