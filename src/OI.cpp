#include "OI.h"

#include <WPILib.h>
#include <Commands/PickUp.h>

OI::OI() {
	pDriveStick = new Joystick(0);
	pOperatorStick = new Joystick(1);
	AButton = new JoystickButton(pOperatorStick, 1);
	BButton = new JoystickButton(pOperatorStick, 2);
	AButton->WhenPressed(new PickUp(1));
	BButton->WhenPressed(new PickUp(-1));

	m_pNetworkTable = NetworkTable::GetTable("GRIP/tape");

	m_Contours = std::vector<Contour>();

	m_pAlignment = new grip::TapeAlignment();

	m_Camera = CameraServer::GetInstance()->StartAutomaticCapture(0);
	m_Camera.SetResolution(CAMERA_X_RES, CAMERA_Y_RES);
	m_Camera.SetExposureManual(16);
	m_Camera.SetExposureHoldCurrent();
	m_Camera.SetFPS(30);


	m_pVisionRunner = new VisionRunner<grip::TapeAlignment>(m_Camera, m_pAlignment,
			std::bind(&OI::ProcessAlignment, this));

	m_Thread = std::thread(std::bind(&OI::AlignmentThread, this));
	m_Thread.detach();

	// Process operator interface input here.
}

void OI::ProcessAlignment()
{
	m_Contours = GenerateContours(m_pAlignment->getfilterContoursOutput());

	//std::cout << m_gearContours.size() << std::endl;
}

std::vector<OI::Contour> OI::GenerateContours(std::vector<std::vector<cv::Point>>* points)
{
	std::vector<Contour> contours;

	for (unsigned int i = 0; i < points->size(); i++)
	{
		Contour c;

		for (unsigned int j = 0; j < points->at(i).size(); j++)
		{
			cv::Point p = (cv::Point)points->at(i).at(j);

			c.left = std::min(c.left, p.x);
			c.right = std::max(c.right, p.x);
			c.top = std::min(c.top, p.y);
			c.bottom = std::max(c.bottom, p.y);
		}

		c.centerX = (c.left + c.right) / 2;
		c.centerY = (c.top + c.bottom / 2);

		contours.push_back(c);
	}

	return contours;
}

void OI::AlignmentThread()
{
	m_pVisionRunner->RunForever();
}

cv::Point OI::GetCenterContours(std::vector<Contour> contours)
{
	cv::Point avg;
	int numPoints = contours.size();

	if (numPoints == 0)
		return avg;

	for (int i = 0; i < numPoints; i++)
	{
		avg.x += contours[i].centerX;
		avg.y += contours[i].centerY;
	}

	avg.x /= numPoints;
	avg.y /= numPoints;
	avg.x -= CAMERA_X_RES / 2;
	avg.y -= CAMERA_Y_RES / 2;

	return avg;
}

cv::Point OI::GetCenter()
{
	return GetCenterContours(m_Contours);
}


std::vector<OI::Contour> OI::GetContours()
{
	return m_Contours;
}

grip::TapeAlignment* OI::GetAlignment()
{
	return m_pAlignment;
}

std::vector<double> OI::GetContourValues(std::string value)
{
	return m_pNetworkTable->GetNumberArray(value, llvm::ArrayRef<double>());
}

Joystick* OI::GetDriveStick()
{
	return pDriveStick;
}
