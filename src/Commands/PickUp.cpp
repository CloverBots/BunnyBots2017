#include "PickUp.h"

PickUp::PickUp(double speed) : speed(speed){
	Requires(CommandBase::bunnyPickUp.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void PickUp::Initialize() {
	CommandBase::bunnyPickUp->SetSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void PickUp::Execute() {
	CommandBase::bunnyPickUp->SetSpeed(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool PickUp::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void PickUp::End() {
	CommandBase::bunnyPickUp->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PickUp::Interrupted() {

}
