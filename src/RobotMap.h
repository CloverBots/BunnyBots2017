#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

class RobotMap
{
public:
	const static unsigned int
		Front_Right_Motor = 0,
		Front_Left_Motor = 1,
		Middle_Right_Motor = 2,
		Middle_Left_Motor = 3,
		Back_Right_Motor = 4,
		Back_Left_Motor = 5,
		Bunny_Pick_Up_Motor = 6;
};
#endif  // ROBOTMAP_H