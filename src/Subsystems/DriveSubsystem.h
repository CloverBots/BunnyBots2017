#ifndef DriveSubsystem_H
#define DriveSubsystem_H
#include <WPILib.h>
#include <Commands/Subsystem.h>

class DriveSubsystem : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* Front_Right_Motor;
	Talon* Front_Left_Motor;
	Talon* Middle_Right_Motor;
	Talon* Middle_Left_Motor;
	Talon* Back_Right_Motor;
	Talon* Back_Left_Motor;
	DoubleSolenoid* Left_Gear_Box;
	DoubleSolenoid* Right_Gear_Box;

public:
	DriveSubsystem();
	void Drive(double speed, double turn);
	void Shift(DoubleSolenoid::Value value);
	void InitDefaultCommand();
};

#endif  // DriveSubsystem_H
