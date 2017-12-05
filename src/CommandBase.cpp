#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/DriveSubsystem.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.

std::unique_ptr<DriveSubsystem> CommandBase::driveSubsystem =
		std::make_unique<DriveSubsystem>();
std::unique_ptr<BunnyPickUp> CommandBase::bunnyPickUp =
		std::make_unique<BunnyPickUp>();

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
