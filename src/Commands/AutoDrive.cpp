#include "AutoDrive.h"

AutoDrive::AutoDrive(double speed, double turn) {
	m_speed = speed;
	m_turn = turn;
	Requires(CommandBase::driveSubsystem.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
	CommandBase::driveSubsystem->Drive(0,0);
	CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kForward);
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {
	//Joystick* pDriveStick = CommandBase::oi->GetDriveStick();
	CommandBase::driveSubsystem->Drive(m_speed, m_turn);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void AutoDrive::End() {
	//CommandBase::driveSubsystem->Drive(0,0);
	//CommandBase::driveSubsystem->Shift(DoubleSolenoid::Value::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {

}
