/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2015, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+ */
#pragma once

#include "gnss_messages_common.h"
#include <mrpt/math/CMatrixFixedNumeric.h>

namespace mrpt {
namespace obs {
namespace gnss {


#if 0
/** The GPS datum for TopCon's mmGPS devices
	*/
struct OBS_IMPEXP TGPSDatum_PZS
{
	TGPSDatum_PZS();

	/**  Return the geodetic coords as a mrpt::topography::TGeodeticCoords structure (requires linking against mrpt-topography)
		*   Call as: getAsStruct<TGeodeticCoords>();
		*/
	template <class TGEODETICCOORDS>
	inline TGEODETICCOORDS getAsStruct() const {
		return TGEODETICCOORDS(latitude_degrees,longitude_degrees,height_meters);
	}

	double		latitude_degrees;	//!< The measured latitude, in degrees (North:+ , South:-)
	double		longitude_degrees;	//!< The measured longitude, in degrees (East:+ , West:-)
	double		height_meters;		//!< ellipsoidal height from N-beam [m] perhaps weighted with regular gps
	double		RTK_height_meters;	//!< ellipsoidal height [m] without N-beam correction
	float		PSigma;				//!< position SEP [m]
	double		angle_transmitter;	//!< Vertical angle of N-beam
	uint8_t		nId;		//!< ID of the transmitter [1-4], 0 if none.
	uint8_t		Fix;		//!< 1: GPS, 2: mmGPS
	uint8_t		TXBattery;	//!< battery level on transmitter
	uint8_t		RXBattery;	//!< battery level on receiver
	uint8_t		error;		//! system error indicator

	bool hasCartesianPosVel;
	double		cartesian_x,cartesian_y,cartesian_z;  //!< Only if hasCartesianPosVel is true
	double		cartesian_vx,cartesian_vy,cartesian_vz;  //!< Only if hasCartesianPosVel is true

	bool hasPosCov;
	mrpt::math::CMatrixFloat44   pos_covariance;	//!< Only if hasPosCov is true

	bool hasVelCov;
	mrpt::math::CMatrixFloat44   vel_covariance;	//!< Only if hasPosCov is true

	bool hasStats;
	uint8_t  stats_GPS_sats_used, stats_GLONASS_sats_used; //<! Only if hasStats is true
	uint8_t  stats_rtk_fix_progress; //!< [0,100] %, only in modes other than RTK FIXED.

};

/** A generic structure for statistics about tracked satelites and their positions.
	*/
struct OBS_IMPEXP TGPSDatum_SATS
{
	TGPSDatum_SATS();
	vector_byte  USIs;  //!< The list of USI (Universal Sat ID) for the detected sats (See GRIL Manual, pag 4-31).
	vector_signed_byte ELs; //!< Elevation (in degrees, 0-90) for each satellite in USIs.
	vector_signed_word AZs; //!< Azimuth (in degrees, 0-360) for each satellite in USIs.
};

#pragma pack(pop) // End of pack = 1

#endif

} } } // End of namespaces

