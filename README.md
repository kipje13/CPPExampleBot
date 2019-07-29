# CPPExampleBot

## How to use:
 - Clone this repository by running: `git clone https://github.com/kipje13/CPPExampleBot.git --recursive`
 - Generate the solution with CMake.
 - Start a match by executing `rlbot/run.bat`
 - Build and run the CPPExampleBot executable.
 
## Auto-start
The rlbot framework has the ability to launch the bot executable automatically. This is usefull when sharing your bot and usually required when you enter a tournament.

In order to get auto-starting to work you will need to do the following things.
 - Build your bot executable.
 - Set the `cpp_executable_path` field in `rlbot/CppPythonAgent.cfg` so it points to the bot executable. It is recommended to copy your bot executable to the `rlbot` folder to make this process easier.
 
## Notes:
  - People might have issues when trying to run your bot if you have compiled it in debug mode. It is better to compile in release mode when you want to share your bot with others.
