import os
from shutil import copy 

from rlbot.utils.structures.game_interface import get_dll_directory

dest = os.path.dirname(os.path.abspath(__file__))

copy(get_dll_directory() + "/RLBot_Core_Interface.dll", dest)
copy(get_dll_directory() + "/RLBot_Core_Interface_32.dll", dest) 