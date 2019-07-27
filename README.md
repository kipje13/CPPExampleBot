# CPPExampleBot

## How to use:
 - Clone this repository by running: `git clone https://github.com/kipje13/CPPExampleBot.git --recursive`
 - Generate the solution with CMake.
 
#### Dev-mode:
This is what you would use to create and test your own bot.
 - Begin a match by starting: `rlbot-dev/run.bat`
 - Set the `botIndex` and `botTeam` variables in `main.cc` to match the values in the command prompt. (These should match if you haven't touched `rlbot.cfg`).
 - Build and run the executable.
 
#### Release-mode:
This is what you need to do if you want to share your bot.
 - Build the executable.
 - Copy the executable to `rlbot-release`.
 - Make sure that the path field in rlbot-release/CppPythonAgent.cfg points to your C++ bot executable.
 
 Notes:
  - When your bot is started by the RLBot match runner it will not be able to use relative file paths.
  - People might have issues when trying to run your bot if you have compiled it in debug mode, it is better to compile in release mode.
