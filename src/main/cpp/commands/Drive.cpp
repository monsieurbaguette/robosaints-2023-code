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

#include "commands/Drive.h"
#include "Robot.h"
#include "OI.h"

Drive::Drive(DrivetrainModular* driveSubsystem,
                           std::function<frc::Joystick*()> drivestick)
    : drivetrainmodular(std::move(driveSubsystem)), //welcome to wpilib's new command framework, where new programmers' dreams go to die! in all seriousness, though, see the comment below this declaration block for info on why this has been changed, and how to make sense of it.
      joystick(std::move(drivestick)) //use std::move because we dont need to make a copy; the joystick is only used in the drivetrain, so the value does not need to remain global/undeleted in the OI scope. less ram usage is important, especially when we will be using autonomous! every byte matters!
       {
        /*
        alright, as promised. Back in our old command-based bot codebase (the one that we reused up until now), AddRequirements would have been 
        written as Requires(Robot::driveSubsystem) (note that it was actually Robot::drivetrain, it has been changed to help make the new structure readable)
        The values contained within the Robot class that we referenced were initialized/created in the Robot.h file using a pointer; it would look something like this:
    class Robot : public frc::TimedRobot {
        public:
	        static OI* oi;
	        static Subsystem1* subsystem1;
	        static Subsystem2* subsystem2;
	       ....
        } ...
        These were then declared/defined in Robot.cpp, at the top of the file: 

        Subsystem* Robot::subsystem = 0;

        This made sure that they were declared in the robot file (no undefined/nullptr errors)
        In the robot initiallization function, they were changed from 0 (a useless value for a command, would generate runtime errors if left as-is) to the following:

        subsystem = new Subsystem();

        (note that this was declared inside of one of the robot class's member functions/methods, so we dont need to have the Robot:: prefix)

        The problem with this is that it complicated the dependencies (one file requires robot.h, and the robot.cpp file requires that file, so you get this messy circular dependency that is just not good at all)

        The other issue with this is that initializing all of these subsystems (and commands, as subsystems with default commands also used the new keyword for the commands themselves)
        is that it created memory leaks, no matter what the user did. Not good. In order to fix this, WPILib opted to keep the library itself clean/simple, but as a result, user code has to be a little more complex 
        in order to work as intended. The first issue is fixed by passing subsystems as parameters for each command, rather than having each command require them from the robot class.
        In order to do this, these subsystems (and other parameters, passed using std::function<variableType --asterisk here if necessary based on how you declared it in the header -- ()> functionVariableName if passed as a function result)
        Then, we use the : to make the drive command inherit the data of the drivetrain subsystem class, and to also set the subsystem variable passed in the declaration as the one that we refer to in this code. there are some complexities that i am leaving out, as this is supposed to be a guide for some of the new programmers.
        the same thing is done with the joystick (because it also needs to be declared as a part of the robot class). Std::move used instead of new.
        These can then be used as normal in the command's main code.

        Feb. 21, 2023 
       ---------------------------------------------------------------------------------------------------------
        uh yeah lots of stuff happened and the code had to be last minuted so memory leaks 
        will have to be tolerated for now. not the biggest deal, there arent as many
        so the ram wont skyrocket fast enough to cause any issues (just dont run the bot for 10 hours straight)
       ---------------------------------------------------------------------------------------------------------




        */
       
  AddRequirements({driveSubsystem});
    // Use AddRequirements() here to declare subsystem dependencies
    // eg. AddRequirements(m_Subsystem);
    SetName("Drive");
    

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

}

// Called just before this Command runs the first time
void Drive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
//double maxSpeed = ((joystick()->GetRawAxis(3)*-1)+1)*0.5;
drivetrainmodular->StandardDrive(joystick());

}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void Drive::End(bool interrupted) {

}

bool Drive::RunsWhenDisabled() const {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DISABLED
    return false;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DISABLED
}
