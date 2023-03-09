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
#include "commands/GrabberGrab.h"
#include <frc2/command/Command.h>
#include <frc2/command/Commands.h>
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
/*bool ssu(frc::Joystick* systemStick) {
}
bool ssd(frc::Joystick* systemStick) {
    return (systemStick->GetX() > .1);
}*/
OI::OI() {
//driveStick = std::shared_ptr<frc::Joystick> (new frc::Joystick(0));
//std::shared_ptr<frc::Joystick> systemStick(new frc::Joystick(1)); // if & no work use new keyword again
//    explicit Expletive(ExplicitWord* wasHere); bool removed = true;    the ampersand didnt work 
//memory leaks it is
driveStick = new frc::Joystick(0);
systemStick = new frc::Joystick(1);

frc2::JoystickButton TelescopeExtendButton(driveStick, 5);
frc2::JoystickButton TelescopeRetractButton(driveStick, 3);
frc2::JoystickButton ElevatorUpButton(driveStick, 6);
frc2::JoystickButton ElevatorDownButton(driveStick, 4);
frc2::JoystickButton GrabberFrontTrigger(driveStick, 1);
frc2::JoystickButton GrabberExtendSideTrigger(driveStick, 11);
frc2::JoystickButton GrabberExtendSideTrigger1(driveStick, 12);
//MultiButtonCheck BothArmButtons(driveStick, 5, 3);


//frc2::JoystickButton TelesccopeExtendButton(systemStick, 7);
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

//One-joystick control quickfix. For readability/clarity, remove systemStick and reassign all of the commands to driveStick (which will be renamed for clarity aswell- perhaps "mainStick"?  
    // SmartDashboard Buttons
 
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
//TelescopeExtendButton.WhileHeld(TelescopeExtend(&pneumatics)); deprecated

TelescopeExtendButton.WhileTrue(TelescopeExtend(&pneumatics).ToPtr());
TelescopeRetractButton.WhileTrue(TelescopeRetract(&pneumatics).ToPtr());
//BothArmButtons.WhileFalse(TelescopeNope(&pneumatics).ToPtr());
//(TelescopeExtendButton && TelescopeRetractButton).WhenInactive(TelescopeNope(&pneumatics));
//TelescopeRetractButton.OnFalse(TelescopeNope(&pneumatics).ToPtr());
//TelescopeExtendButton.OnFalse(TelescopeNope(&pneumatics).ToPtr());
ElevatorUpButton.WhileTrue(ElevatorUp(&m_elevator, &pneumatics, false).ToPtr());
ElevatorDownButton.WhileTrue(ElevatorDown(&m_elevator, &pneumatics, false).ToPtr());
GrabberFrontTrigger.WhileTrue(GrabberGrab(&pneumatics).ToPtr());
GrabberExtendSideTrigger.ToggleOnTrue(frc2::cmd::StartEnd([&] { pneumatics.ValveOpen(3); },
    [&] { pneumatics.ValveClose(3); },
    {&pneumatics}));

std::function<bool()> isUp = ([this] { 
       return (frc::Joystick(1).GetY() > .1);

 });
 std::function<bool()> isDown = ([this] { 
       return (frc::Joystick(1).GetY() < -.1);

 });
frc2::Trigger(isDown).WhileTrue(ElevatorUp(&m_elevator, &pneumatics, false).ToPtr());
frc2::Trigger(isDown).WhileTrue(TelescopeRetract(&pneumatics).ToPtr());
frc2::Trigger(isUp).WhileTrue(ElevatorDown(&m_elevator, &pneumatics, true).ToPtr());
frc2::Trigger(isUp).WhileTrue(TelescopeExtend(&pneumatics).ToPtr());


}



frc::Joystick* OI::getDriveStick() {
   return driveStick;
   
}
frc::Joystick* OI::getSystemStick(){
    return systemStick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS