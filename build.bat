IF NOT EXIST RLBotCPP\ (
git clone https://github.com/kipje13/RLBotCPP.git
cd RLBotCPP
git checkout restructure
)

cmake -A x64 -B build