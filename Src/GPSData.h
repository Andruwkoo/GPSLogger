#ifndef __GPSDATA_H__
#define __GPSDATA_H__

// Forward declarations
class gps_fix;
typedef void * QueueHandle_t;
typedef QueueHandle_t SemaphoreHandle_t;

class GPSData
{
public:
	GPSData();
	
	void processNewGPSFix(const gps_fix & fix);
	gps_fix getGPSFix();
	
private:
	gps_fix cur_fix; /// most recent fix data
	gps_fix prev_fix; /// previously set fix data
	
	SemaphoreHandle_t xGPSDataMutex;
	
	GPSData( const GPSData &c );
	GPSData& operator=( const GPSData &c );	
}; //GPSData

/// A single instance of GPS data
extern GPSData gpsData;

#endif //__GPSDATA_H__