#ifndef DelaySeconds_H
#define DelaySeconds_H

#include "../CommandBase.h"

class DelaySeconds : public CommandBase {
private:
	double seconds;
	bool done = false;
public:
	DelaySeconds(double seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DelaySeconds_H
