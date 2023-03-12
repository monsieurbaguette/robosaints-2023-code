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
#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include <photonlib/PhotonCamera.h>
#include <frc/controller/PIDController.h>
#include "OI.h"
#include "subsystems/DrivetrainModular.h"
#include <units/angle.h>
#include <units/length.h>
class Robot : public frc::TimedRobot {
 public:
 photonlib::PhotonCamera camera{"photonvision"};
 frc2::PIDController controller{.1, 0, 0};
  void RobotInit() override;
  void RobotPeriodic() override;
   void SimulationInit() override;
  void SimulationPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  PneumaticsArm* pneumaticarm;
  PneumaticsGrabber* grabbah;
 private:  
   OI* controlInterface;
   DrivetrainModular drivetrain;
   
    double forwardSpeed;
    double rotationSpeed;
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc2::Command* m_autonomousCommand = nullptr;
 


};
