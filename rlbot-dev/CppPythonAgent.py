from multiprocessing import Event

from rlbot.agents.base_dotnet_agent import BaseIndependentAgent
from rlbot.utils.structures.game_interface import get_dll_directory


class DummyAgent(BaseIndependentAgent):
    def run_independently(self, terminate_request_event: Event) -> None:
        print("Bot (index: %d, team: %d, name: %s) started in dev mode." % (self.index, self.team, self.name))
        print("RLBot dll directory: " + get_dll_directory())
