#include "timeMgmt.h"

namespace dbf
{
	void timeMgmt::gameTick()
	{
		clock_duration duration = clock::now() - m_startTimePoint;
		time = duration.count() / static_cast<float>(clock_duration::period::den);

		duration = clock::now() - m_frameTimePoint;
		deltaTime = duration.count() / static_cast<float>(clock_duration::period::den);

		m_frameTimePoint = clock::now();
	}
}

