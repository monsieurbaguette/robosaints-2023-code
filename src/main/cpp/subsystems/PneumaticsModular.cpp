// RobotBuilder Version: 5.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

// ROBOTBUILDER TYPE: Subsystem.

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "subsystems/PneumaticsModular.h"
#include <frc/smartdashboard/SmartDashboard.h>

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

PneumaticsModular::PneumaticsModular(){
     ///frc::Solenoid* STUPID = &Solenoid;
    SetName("PneumaticsModular");
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    SetSubsystem("PneumaticsModular");

 AddChild("Double Solenoid", &Solenoid);
 

 AddChild("Double Solenoid 1", &Solenoid1);
 

 AddChild("Compressor", &compressor);



    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void PneumaticsModular::Periodic() {
    // Put code here to be run every loop

}

void PneumaticsModular::SimulationPeriodic() {
    // This method will be called once per scheduler run when in simulation

}

void PneumaticsModular::ValveOpen(int solId) {
    if(solId == 1){
        frc::DoubleSolenoid* gwenStefani =  &Solenoid;
        gwenStefani->Set(frc::DoubleSolenoid::kForward);


        armIsExtend = true;
     //sol is shorthand for solenoid valve (its a double solenoid so there are two channels of air movement, forward and reverse)
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // i love exclaimation points!!!!!
    } if( solId ==2 ){
                frc::DoubleSolenoid* gwenStefani =  &Solenoid1;
        gwenStefani->Set(frc::DoubleSolenoid::kForward);


        //armIsExtend = true;
    }
}

void PneumaticsModular::ValveClose(int solId) {
    if(solId == 1){
        frc::DoubleSolenoid* gwenStefani =  &Solenoid;
        gwenStefani->Set(frc::DoubleSolenoid::kReverse);


        armIsExtend = false;
     //sol is shorthand for solenoid valve (its a double solenoid so there are two channels of air movement, forward and reverse)
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // i love exclaimation points!!!!!
    }
    if (solId==2) {
                frc::DoubleSolenoid* gwenStefani =  &Solenoid1;
        gwenStefani->Set(frc::DoubleSolenoid::kReverse);


       // armIsExtend = false;
    }
}
void PneumaticsModular::ValveCloseAll(int solId) {
    if(solId == 1){
        frc::DoubleSolenoid* gwenStefani =  &Solenoid;
        gwenStefani->Set(frc::DoubleSolenoid::kOff);


        armIsExtend = false;
     //sol is shorthand for solenoid valve (its a double solenoid so there are two channels of air movement, forward and reverse)
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // i love exclaimation points!!!!!
    }
    if (solId==2) {
                frc::DoubleSolenoid* gwenStefani =  &Solenoid;
        gwenStefani->Set(frc::DoubleSolenoid::kOff);


        armIsExtend = false;
    }
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.
