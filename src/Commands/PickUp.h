#ifndef PickUp_H
#define PickUp_H

#include "../CommandBase.h"

class PickUp : public CommandBase {
private:
	double speed;
public:
	PickUp(double speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // PickUp_H
