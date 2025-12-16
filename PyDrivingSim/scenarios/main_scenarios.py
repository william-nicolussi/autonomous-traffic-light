
from pydrivingsim import TrafficLight, Target, TrafficCone, SuggestedSpeedSignal, GraphicObject, Vehicle, Agent, Coin, Graph, Rock, GPS, RoadSegment, World

class OnlyVehicle():
    def __init__(self):
        #Initialize the vehicle
        self.vehicle = Vehicle()
        self.vehicle.set_screen_here()
        self.vehicle.set_pos_ang((0, -1, 0))

        #Initialize target
        target = Target()
        target.set_pos((182, -1))
        target.set_object(self.vehicle)

    def update(self):
        self.vehicle.set_screen_here()
        self.vehicle.control([0.5, 0.0])

    def terminate(self):
        pass

class AutonomousVehicle():
    def __init__(self):
        # Initialize the vehicle
        self.vehicle = Vehicle()
        self.vehicle.set_screen_here()
        self.vehicle.set_pos_ang((0, -1, 0.1))
        self.gps = GPS(self.vehicle)

        #Initialize the agent
        self.agent = Agent(self.vehicle)
        
        #Initialize target
        #target = Target()
        #target.set_pos((182, -1))
        #target.set_object(self.vehicle)

    def update(self):
        self.agent.compute()
        action = self.agent.get_action()

        self.vehicle.set_screen_here()
        self.vehicle.control([action[0], action[1]])

    def terminate(self):
        self.agent.terminate()


class BasicTrafficLight():
    def __init__(self):
        cone = TrafficCone()
        cone.set_pos((65, -0.5))
        cone = TrafficCone()
        cone.set_pos((65, -1.5))
        cone = TrafficCone()
        cone.set_pos((90, 0.5))
        cone = TrafficCone()
        cone.set_pos((90, 1.5))

        trafficlight = TrafficLight()
        trafficlight.set_pos((160,-3))
        trafficlight.reset()

class GetTheCoins():
    def __init__(self):
        # Added point in zero to be able to start with a reference
        coin = Coin()
        coin.set_pos((0,-1))

        # Targets to avoid cones
        coin = Coin()
        coin.set_pos((10,-1))
        coin = Coin()
        coin.set_pos((35,1))
        coin = Coin()
        coin.set_pos((60,-1))
        coin = Coin()
        coin.set_pos((100,1))
        coin = Coin()
        coin.set_pos((130,-1))

        # Add two final points to stabilize the trajectory
        coin = Coin()
        coin.set_pos((160,-1))
        coin = Coin()
        coin.set_pos((182,-1))
        
class ObstacleRocks():
    def __init__(self):
        rock = Rock()
        rock.set_pos_size((20, -2), 2.0, 2.0)
        rock = Rock()
        rock.set_pos_size((45, 2), 3.0, 4.0)


class BasicSpeedLimit():
    def __init__(self):
        signal = SuggestedSpeedSignal(10)
        signal.set_pos((50, 4))
        bologna = GraphicObject("imgs/pictures/bologna.png", 35)
        bologna.set_pos((67,12))
        signal = SuggestedSpeedSignal(90)
        signal.set_pos((96, 4))
        super = GraphicObject("imgs/pictures/superstrada.png", 5)
        super.set_pos((100,6))
        
# draw path into m.m.TrajectoryPointIX
class DrawPath():
    def __init__(self):
        self.graph = Graph()
        
class MixedTerrain():
    def __init__(self):
        segm1 = RoadSegment(x=0, y=0, length=40, width=4, terrain_type="asphalt")
        segm2 = RoadSegment(x=35, y=0, length=30, width=4, terrain_type="dirt")
        segm3 = RoadSegment(x=125, y=0, length=150, width=4, terrain_type="asphalt")
        segm4 = RoadSegment(x=15, y=-4, length=10, width=4, terrain_type="asphalt")
        segm5 = RoadSegment(x=55, y=-4, length=10, width=4, terrain_type="asphalt")
        segm6 = RoadSegment(x=35, y=-5, length=30, width=4, terrain_type="asphalt")
        
class Scenario1():
    def __init__(self, av):
        # draw the background image
        World().set_background("imgs/Scenario_1.png", bg_pos=(-1100,-1745))
        
        # draw the rectangle of terrain
        segm = RoadSegment(x=0, y=0, length=6, width=100, terrain_type="asphalt")
        segm = RoadSegment(x=33, y=46, length=60, width=8, terrain_type="asphalt")
        segm = RoadSegment(x=66, y=0, length=6, width=100, terrain_type="asphalt")
        segm = RoadSegment(x=99, y=-46, length=60, width=8, terrain_type="asphalt")
        segm = RoadSegment(x=132, y=0, length=6, width=100, terrain_type="dirt")
        segm = RoadSegment(x=165, y=46, length=60, width=8, terrain_type="asphalt")
        
        # draw the vehicle
        # remove and add the vehicle to put it in the focus
        if av.vehicle in World().obj_list:
            World().obj_list.remove(av.vehicle)
        World().obj_list.append(av.vehicle)
        av.vehicle.set_pos_ang((0, -40, 1.57)) #((0,-1,0.1))
        
        #Initialize target
        target = Target()
        target.set_pos((175, 46))
        target.set_object(av.vehicle)
        
        # draw the cones
        cone = TrafficCone()
        cone.set_pos((63.5, 10))
        cone = TrafficCone()
        cone.set_pos((65, 10))
        cone = TrafficCone()
        cone.set_pos((67, -20))
        cone = TrafficCone()
        cone.set_pos((68.5, -20))
        
        # draw the rocks
        rock = Rock()
        rock.set_pos_size((130, -5), 2.0, 2.0)
        rock = Rock()
        rock.set_pos_size((134, 15), 2.0, 3.0)

class Scenario2():
    def __init__(self, av):
        # draw the background image
        World().set_background("imgs/Scenario_2.png", bg_pos=(-1100,-1745))
        
        # draw the rectangle of terrain
        segm = RoadSegment(x=0, y=12, length=8, width=20, terrain_type="asphalt")
        segm = RoadSegment(x=14, y=18, length=20, width=8, terrain_type="asphalt")
        segm = RoadSegment(x=13, y=0, length=42, width=4, terrain_type="asphalt")
        segm = RoadSegment(x=30, y=-7, length=8, width=10, terrain_type="asphalt")
        segm = RoadSegment(x=54, y=-10, length=40, width=4, terrain_type="asphalt")
        segm = RoadSegment(x=78, y=-7, length=8, width=10, terrain_type="asphalt")
        segm = RoadSegment(x=54, y=0, length=40, width=4, terrain_type="dirt")
        segm = RoadSegment(x=134, y=0, length=120, width=4, terrain_type="asphalt")
        segm = RoadSegment(x=162.5, y=0, length=4, width=40, terrain_type="asphalt")
        
        # draw the vehicle
        # remove and add the vehicle to put it in the focus
        if av.vehicle in World().obj_list:
            World().obj_list.remove(av.vehicle)
        World().obj_list.append(av.vehicle)
        av.vehicle.set_pos_ang((14, 18, 3.14)) #((0,-1,0.1))
        
        #Initialize target
        target = Target()
        target.set_pos((182, -1))
        target.set_object(av.vehicle)
        
        # draw the cones
        cone = TrafficCone()
        cone.set_pos((0, 0))
        cone = TrafficCone()
        cone.set_pos((65, -8))
        cone = TrafficCone()
        cone.set_pos((65, -9))
        cone = TrafficCone()
        cone.set_pos((90, 0.5))
        cone = TrafficCone()
        cone.set_pos((90, 1.5))

        # draw the traffic light
        trafficlight = TrafficLight()
        trafficlight.set_pos((160,-3))
        trafficlight.reset()
        
        # draw the rocks
        rock = Rock()
        rock.set_pos_size((60, -2), 2.0, 2.0)
        rock = Rock()
        rock.set_pos_size((45, 2), 3.0, 4.0)