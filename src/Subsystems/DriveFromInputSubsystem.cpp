#include <Commands/DriveFromInput.h>
#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include "WPILib.h"
#include <iostream>
DriveSubsystem::DriveSubsystem() : Subsystem("driveSubsystem") {
		Front_Right_Motor = new Talon(RobotMap::Front_Right_Motor);
		Front_Left_Motor = new Talon(RobotMap::Front_Left_Motor);
		Middle_Right_Motor = new Talon(RobotMap::Middle_Right_Motor);
		Middle_Left_Motor = new Talon(RobotMap::Middle_Left_Motor);
		Back_Right_Motor = new Talon(RobotMap::Back_Right_Motor);
		Back_Left_Motor = new Talon(RobotMap::Back_Left_Motor);
		Gear_Box = new DoubleSolenoid(0, 1);
	}

void DriveSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new DriveFromInput());
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void DriveSubsystem::Drive(double speed, double turn)
{
	Front_Right_Motor->Set(-(speed + (turn/3)));
	Front_Left_Motor->Set(speed - (turn/3));
	Middle_Right_Motor->Set(-(speed + (turn/3)));
	Middle_Left_Motor->Set(speed - (turn/3));
	Back_Right_Motor->Set(-(speed + (turn/3)));
	Back_Left_Motor->Set(speed - (turn/3));
}

void DriveSubsystem::Shift(DoubleSolenoid::Value value)
{
	Gear_Box->Set(value);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
