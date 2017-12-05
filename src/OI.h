#ifndef OI_H
#define OI_H
#include <WPILib.h>
#include "TapeAlignment.h"

class OI {
private:

public:

	const static int CAMERA_X_RES = 160;
	const static int CAMERA_Y_RES = 120;

	struct Contour
	{
		int left;
		int right;
		int top;
		int bottom;
		int centerX;
		int centerY;

		Contour()
		{
			left = OI::CAMERA_X_RES;
			right = 0;
			top = OI::CAMERA_Y_RES;
			bottom = 0;
			centerX = top / 2;
			centerY = bottom / 2;
		}
	};


	Joystick* pDriveStick;
	Joystick* pOperatorStick;
	JoystickButton* AButton;
	JoystickButton* BButton;
	OI();

	grip::TapeAlignment* GetAlignment();

	std::vector<double> GetContourValues(std::string value);
	std::vector<Contour> GetContours();
	cv::Point GetCenter();

	Joystick* GetDriveStick();


	cs::UsbCamera m_Camera;

	grip::TapeAlignment* m_pAlignment;

	VisionRunner<grip::TapeAlignment>* m_pVisionRunner;

	std::thread m_Thread;

	std::shared_ptr<NetworkTable> m_pNetworkTable;

	std::vector<Contour> m_Contours;

	void AlignmentThread();

	void ProcessAlignment();

	std::vector<Contour> GenerateContours(std::vector<std::vector<cv::Point>>* points);
	cv::Point GetCenterContours(std::vector<Contour> contours);

};

#endif  // OI_H
