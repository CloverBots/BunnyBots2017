#ifndef BunnyPickUp_H
#define BunnyPickUp_H

#include <Commands/Subsystem.h>
#include <WPILib.h>

class BunnyPickUp : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* Bunny_Pick_Up_Motor;
public:
	BunnyPickUp();
	void SetSpeed(double speed);
	void InitDefaultCommand();
};

#endif  // BunnyPickUp_H
