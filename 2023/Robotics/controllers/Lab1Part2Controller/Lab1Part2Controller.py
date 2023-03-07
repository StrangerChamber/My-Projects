"""Lab1Part2Controller controller."""

#JACK BLACKBURN ROBOTICS LAB 1 PART 2 CONTROLLER

# You may need to import some classes of the controller module. Ex:
#  from controller import Robot, Motor, DistanceSensor

from controller import Robot, DistanceSensor, Motor

TIME_STEP = 64

#JUST GOING WITH WHAT THE TUTORIALS USED 

MAX_SPEED = 6.28

# create the Robot instance.

#all setup for main loop
robot = Robot()

ps = []

psNames = [
    'ps0', 'ps1', 'ps2', 'ps3',
    'ps4', 'ps5', 'ps6', 'ps7'
]

for i in range(8):
    ps.append(robot.getDevice(psNames[i]))
    ps[i].enable(TIME_STEP)

count = 0
secCount = 0
turn1 = 0
count3 = 0

leftMotor = robot.getDevice('left wheel motor')
rightMotor = robot.getDevice('right wheel motor')
leftMotor.setPosition(float('inf'))
rightMotor.setPosition(float('inf'))
leftMotor.setVelocity(0.0)
rightMotor.setVelocity(0.0)

# Main loop:
# - perform simulation steps until Webots is stopping the controller
while robot.step(TIME_STEP) != -1:

    psValues = []
    for i in range(8):
    
        psValues.append(ps[i].getValue())
        
    #baseline behaviour go forward
    if count < 2:
        leftSpeed  = 0.5 * MAX_SPEED
        rightSpeed = 0.5 * MAX_SPEED
    else:
    #after we've avoided the first two objects we stop forever
        leftSpeed = 0
        rightSpeed = 0
        
    #sense objects
    front_obstacle = psValues[7] > 90 or psValues[0] > 90 
    left_obstacle = psValues[5] > 90 or psValues[6] > 90
    back_obstacle = psValues[4] > 90 or psValues[3] > 90
    right_obstacle = psValues[2] > 90 or psValues[1] > 90
    
    #first object avoidance series
    if count == 0:
    
        if front_obstacle or left_obstacle:
            #turn1 makes sure we turn 180 degrees with if statement at the bottom
            turn1 = 1
            leftSpeed  =  MAX_SPEED
            rightSpeed = -MAX_SPEED
            
            
        elif back_obstacle:
            
            leftSpeed  = MAX_SPEED
            rightSpeed = MAX_SPEED
            count += 1
    #second object avoidance series        
    elif count == 1:
    
        if front_obstacle:
            #secCount makes sure that we won't just skip this routine before we hit the second obstacle
            secCount = 1
            leftSpeed  =  MAX_SPEED
            rightSpeed = -MAX_SPEED
        
        elif left_obstacle:
        
            leftSpeed  = 0.5 * MAX_SPEED
            rightSpeed = 0.5 * MAX_SPEED
            
        else:
            if secCount == 1:
                count += 1

    #want it to turn for 68 loop cycles to do a full 180
    if turn1 == 1 and count3 < 68 :
        count3 +=1
        leftSpeed = MAX_SPEED
        rightSpeed =-MAX_SPEED
    
    leftMotor.setVelocity(leftSpeed)
    rightMotor.setVelocity(rightSpeed)
    
# Enter here exit cleanup code.
