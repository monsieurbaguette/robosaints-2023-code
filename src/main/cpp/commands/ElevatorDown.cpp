// RobotBuilder Version: 5.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Command.

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

#include "commands/ElevatorDown.h"
#include <frc/Joystick.h>
ElevatorDown::ElevatorDown(Elevator* m_elevator, PneumaticsArm* telescopearm, bool arm)
:m_elevator(m_elevator), telescopearm(telescopearm){

    // Use AddRequirements() here to declare subsystem dependencies
    // eg. AddRequirements(m_Subsystem);
    SetName("ElevatorDown");
    AddRequirements({m_elevator});
    
    systemStick = new frc::Joystick(1);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

}

// Called just before this Command runs the first time
void ElevatorDown::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ElevatorDown::Execute() {
 /*   if(arm) { // convenience, will update later
        if (systemStick->GetMagnitude() > 0.1) {
m_elevator->ElevatorManual(systemStick->GetY()); //arm and elevator, adjust speed if necessary
telescopearm->ValveOpen(1);
        }
    } else {*/
        
        m_elevator->ElevatorManual(-.5); // sets elevator speed as a decimal (out of 1)
        
  //  }

}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorDown::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void ElevatorDown::End(bool interrupted) {
m_elevator->ElevatorStop();

}

bool ElevatorDown::RunsWhenDisabled() const {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DISABLED
    return false;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DISABLED
}
