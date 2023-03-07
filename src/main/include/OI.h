// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#pragma once

#include "frc/Joystick.h"
#include <frc2/command/button/Button.h>
#include <frc2/command/button/JoystickButton.h>
#include <subsystems/TelescopeArm.h>
#include <subsystems/PneumaticsModular.h>
#include "subsystems/Elevator.h"
class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS


PneumaticsModular pneumatics;
 frc2::JoystickButton* TelescopeExtendButton;
 frc2::JoystickButton* TelescopeRetractButton;
 frc2::JoystickButton* GrabberFrontTrigger;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
Elevator m_elevator;
std::function<bool()> IsSystemStickUp;
std::function<bool()> IsSystemStickDown;

public:

	OI();

frc::Joystick* driveStick;
frc::Joystick* systemStick;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

frc::Joystick* getDriveStick();
frc::Joystick* getSystemStick();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};
