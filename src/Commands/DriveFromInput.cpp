#include <Commands/DriveFromInput.h>
#include "../Subsystems/DriveSubsystem.h"
DriveFromInput::DriveFromInput(){
	Requires(CommandBase::driveSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before thiSs Command runs the first time
void DriveFromInput::Initialize() {
	CommandBase::driveSubsystem->Drive(0,0);
	CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kForward);
}

// Called repeatedly when this Command is scheduled to run
void DriveFromInput::Execute() {
	Joystick* pDriveStick = CommandBase::oi->GetDriveStick();
	CommandBase::driveSubsystem->Drive(
			pDriveStick->GetRawAxis(1),
			pDriveStick->GetRawAxis(4));
	frc::SmartDashboard::PutNumber("forward", pDriveStick->GetRawAxis(1));
	frc::SmartDashboard::PutNumber("turn", pDriveStick->GetRawAxis(4));
	//std::cout << CommandBase::oi->GetContours().size() << std::endl;
	/*
	if(pDriveStick->GetRawButton(3))
	{
	CommandBase::driveSubsystem->Drive(
			.1,
			0);
	}else if(pDriveStick->GetRawButton(4))
	{
		CommandBase::driveSubsystem->Drive(
				-.1,
				0);
	}else
	{
		CommandBase::driveSubsystem->Drive(
				0,
				0);
	}
	*/
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
bool DriveFromInput::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveFromInput::End() {
	//CommandBase::driveSubsystem->DriveFromInput(0,0);
	//CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveFromInput::Interrupted() {

}
