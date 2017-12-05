#include "BunnyPickUp.h"
#include "../RobotMap.h"
#include "WPILib.h"

BunnyPickUp::BunnyPickUp() : Subsystem("ExampleSubsystem") {
	Bunny_Pick_Up_Motor = new Talon(RobotMap::Bunny_Pick_Up_Motor);
}

void BunnyPickUp::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void BunnyPickUp::SetSpeed(double speed)
{
	Bunny_Pick_Up_Motor->Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
