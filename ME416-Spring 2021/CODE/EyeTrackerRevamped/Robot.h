/*
   This is the header file for the robot class. The robot class is the logic engine of the robot.
   The robot class is responsible for holding the eyes, shoulder and neck objects.
   It also sets the state of the robot and has additional private-public functions
   to run the corresponding states.
*/
#ifndef _ROBOT_H
#define _ROBOT_H

#include "EyeSubsystem.h"
#include "Shoulder.h"
#include <BasicLinearAlgebra.h>

/*
   Class declaration for robot class.
*/
class Robot
{
    /*
       Private objects consist of the state, eyes, shoulder and neck objects.
       Also desired gaze coordinates.
       Private functions consist of the different functions implemented by each state.
    */
  private:
    StateMachineState robotState;
    Eyes robotEyes;
    Shoulder robotShoulder;
    //Neck robotNeck;
    BLA::Matrix<4> screenDotPos;

    char getSerialCommand();

    void runMenuModeState();
    void runServoCalibrationState();
    void runServoManualState();
    void runStepperHomeState();


  public:
    Robot();
    void init();
    void SetState(int stateNumber);
    int GetState();
    void RunState();
};

#endif