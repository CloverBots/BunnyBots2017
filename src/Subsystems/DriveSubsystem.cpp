#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include "WPILib.h"

DriveSubsystem::DriveSubsystem() : Subsystem("driveSubsystem") {
	Front_Right_Motor = new Talon(RobotMap::Front_Right_Motor);
	Front_Left_Motor = new Talon(RobotMap::Front_Left_Motor);
	Middle_Right_Motor = new Talon(RobotMap::Middle_Right_Motor);
	Middle_Left_Motor = new Talon(RobotMap::Middle_Left_Motor);
	Back_Right_Motor = new Talon(RobotMap::Back_Right_Motor);
	Back_Left_Motor = new Talon(RobotMap::Back_Left_Motor);
	Left_Gear_Box = new DoubleSolenoid(1, 2);
	Right_Gear_Box = new DoubleSolenoid(3, 4);
}

void DriveSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void DriveSubsystem::Drive(double speed, double turn)
{
	Front_Right_Motor->Set(speed + turn);
	Front_Left_Motor->Set(speed - turn);
	Middle_Right_Motor->Set(speed + turn);
	Middle_Left_Motor->Set(speed - turn);
	Back_Right_Motor->Set(speed + turn);
	Back_Left_Motor->Set(speed - turn);
}

void DriveSubsystem::Shift(DoubleSolenoid::Value value)
{
	Left_Gear_Box->Set(value);
	Right_Gear_Box->Set(value);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
