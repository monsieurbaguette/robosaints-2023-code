#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "frc/smartdashboard/SmartDashboard.h"
#include "Commands/Drive.h"
#include "commands/TelescopeExtend.h"
#include "commands/TelescopeRetract.h"
#include <frc2/command/button/JoystickButton.h>
#include "subsystems/DrivetrainModular.h"
#include "subsystems/TelescopeArm.h"
#include "commands/TelescopeElevatorPreset.h"
#include "subsystems/Elevator.h"
#include "commands/ElevatorDown.h"
#include "commands/ElevatorUp.h"
#include "commands/TelescopeNope.h"
#include <frc2/command/button/Trigger.h>
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
//driveStick = std::shared_ptr<frc::Joystick> (new frc::Joystick(0));
//std::shared_ptr<frc::Joystick> systemStick(new frc::Joystick(1)); // if & no work use new keyword again
driveStick = new frc::Joystick(0);
systemStick = new frc::Joystick(1);
frc2::JoystickButton TelescopeExtendButton(systemStick, 5);
frc2::JoystickButton TelescopeRetractButton(systemStick, 3);
frc2::JoystickButton ElevatorUpButton(systemStick, 6);
frc2::JoystickButton ElevatorDownButton(systemStick, 4);
//MultiButtonCheck BothArmButtons(driveStick, 5, 3);


//frc2::JoystickButton TelesccopeExtendButton(systemStick, 7);
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

//One-joystick control quickfix. For readability/clarity, remove systemStick and reassign all of the commands to driveStick (which will be renamed for clarity aswell- perhaps "mainStick"?  
    // SmartDashboard Buttons
 
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
//TelescopeExtendButton.WhileHeld(TelescopeExtend(&telescopearm)); deprecated

TelescopeExtendButton.WhileTrue(TelescopeExtend(&telescopearm).ToPtr());
TelescopeRetractButton.WhileTrue(TelescopeRetract(&telescopearm).ToPtr());
//BothArmButtons.WhileFalse(TelescopeNope(&telescopearm).ToPtr());
//(TelescopeExtendButton && TelescopeRetractButton).WhenInactive(TelescopeNope(&telescopearm));
//TelescopeRetractButton.OnFalse(TelescopeNope(&telescopearm).ToPtr());
//TelescopeExtendButton.OnFalse(TelescopeNope(&telescopearm).ToPtr());
ElevatorUpButton.WhileTrue(ElevatorUp(&m_elevator).ToPtr());
ElevatorDownButton.WhileTrue(ElevatorDown(&m_elevator).ToPtr());
}


frc::Joystick* OI::getDriveStick() {
   return driveStick;
   
}
frc::Joystick* OI::getSystemStick(){
    return systemStick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS