#include "Drive.h"

Drive::Drive(){
	Requires(CommandBase::driveSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Drive::Initialize() {
	CommandBase::driveSubsystem->Drive(0,0);
	CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kForward);
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	Joystick* pDriveStick = CommandBase::oi->GetDriveStick();
	CommandBase::driveSubsystem->Drive(
			pDriveStick->GetRawAxis(1),
			pDriveStick->GetRawAxis(4));
	if(pDriveStick->GetRawButton(1))
	{
		CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kForward);
	}
	if(pDriveStick->GetRawButton(2))
	{
		CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kReverse);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Drive::End() {
	CommandBase::driveSubsystem->Drive(0,0);
	CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
