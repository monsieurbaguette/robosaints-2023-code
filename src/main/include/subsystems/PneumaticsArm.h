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
#pragma once

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include <frc2/command/SubsystemBase.h>
#include <frc/Compressor.h>
#include <frc/Solenoid.h>
#include <frc/PneumaticsModuleType.h>
#include <frc/DoubleSolenoid.h>

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 *
 *
 * @author ExampleAuthor
 */
class PneumaticsArm: public frc2::SubsystemBase {
private:
    // It's desirable that everything possible is private except
    // for methods that implement subsystem capabilities
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
//frc::DoubleSolenoid ArmSolenoid{0, frc::PneumaticsModuleType::CTREPCM, 0, 1};

frc::Compressor Compressor{0, frc::PneumaticsModuleType::CTREPCM};
bool armIsExtend;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:

frc::DoubleSolenoid ArmSolenoid{0, frc::PneumaticsModuleType::CTREPCM, 0, 1};
PneumaticsArm();
//frc::Solenoid* STUPID;
    void Periodic() override;
    void SimulationPeriodic() override;
    void ExtendArm();
    void RetractArm();
    void Closer();

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS


};

