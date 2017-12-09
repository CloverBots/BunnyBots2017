#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/DriveSubsystem.h"
#include <iostream>
// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.

std::unique_ptr<DriveSubsystem> CommandBase::driveSubsystem;
std::unique_ptr<BunnyPickUp> CommandBase::bunnyPickUp;

std::unique_ptr<OI> CommandBase::oi;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::Init()
{
	driveSubsystem.reset(new DriveSubsystem);
	bunnyPickUp.reset(new BunnyPickUp);
	oi.reset(new OI);
}
