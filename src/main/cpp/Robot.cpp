// RobotBuilder Version: 5.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Robot.

#include "Robot.h"
#include <cameraserver/CameraServer.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <commands/Drive.h>
#include <subsystems/PneumaticsModular.h>
#include <OI.h>
void Robot::RobotInit() {
 controlInterface = new OI(); // USE SMART POINTERS HERE LATER! DO THIS AT SOME POINT IN ORDER TO STOP MEMORY LEAKS! (sure, one memory leak is better than 10, but it would be better to have 0! ) (shared_ptr?)
 drivetrain.SetDefaultCommand(Drive(
      &drivetrain, [this] { return controlInterface->getDriveStick(); })); // [this] is lambda notation, it essentially allows defining/running a function wihout defining/running it explicitly. the this keyword makes sure that the function is treated like it is a member function of robot, so we can use the same scopes/variables.
      //remember, we are trying to minimize/eliminate use of the new keyword! instead of drivetrain= new drivetrain() we just do &drivetrain, referencing the subsystem directly
  frc::CameraServer::StartAutomaticCapture(0);
  frc::CameraServer::StartAutomaticCapture(1);
  
}
void Robot::SimulationInit() {

    //controlInterface = new OI();
    //drivetrain = new DrivetrainModular();
}
/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { 

  frc2::CommandScheduler::GetInstance().Run();
  
  }
void Robot::SimulationPeriodic() { 
  //frc2::CommandScheduler::GetInstance().Run(); 
  }
/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  

}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
