#include "BucketAuto.h"
#include "AutoDrive.h"
#include "AlignWithTape.h"
#include "DelaySeconds.h"

BucketAuto::BucketAuto() {
	/*
	 Add Commands here:
	 e.g. AddSequential(new Command1());
	      AddSequential(new Command2());
	 these will run in order.

	 To run multiple commands at the same time,
	 use AddParallel()
	 e.g. AddParallel(new Command1());
	      AddSequential(new Command2());
	 Command1 and Command2 will run in parallel.

	 A command group will require all of the subsystems that each member
	 would require.
	 e.g. if Command1 requires chassis, and Command2 requires arm,
	 a CommandGroup containing them would require both the chassis and the
	 arm.
	 */
	AddSequential(new AutoDrive(1,-.2));
	AddSequential(new DelaySeconds(1.4));
	AddSequential(new AlignWithTape(0.0, 2.5, AlignWithTape::AlignDirection::NONE));
	AddSequential(new AutoDrive(0,0));
}
