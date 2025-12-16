import math
import signal

from pydrivingsim import World
from scenarios import AutonomousVehicle,DrawPath, Scenario1, Scenario2

class GracefulKiller:
  kill_now = False
  def __init__(self):
    signal.signal(signal.SIGINT, self.exit_gracefully)
    signal.signal(signal.SIGTERM, self.exit_gracefully)

  def exit_gracefully(self, *args):
    self.kill_now = True

def main():
    DrawPath()
    av = AutonomousVehicle()
    #Scenario1(av)
    Scenario2(av)
    

    killer = GracefulKiller()
    while not killer.kill_now and World().loop:
        av.update()
        World().update()

    av.terminate()
    World().exit()

main()