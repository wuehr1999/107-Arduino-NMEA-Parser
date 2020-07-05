/**
 * @brief Arduino library for interfacing with the PA1010D GPS module (MTK3333 chipset).
 * @license LGPL 3.0
 */

#ifndef ARDUINO_MTK3333_NMEA_GPRMC_PARSER_H_
#define ARDUINO_MTK3333_NMEA_GPRMC_PARSER_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace nmea
{

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class GPRMC
{

public:

  static bool parse(char const * gprmc, 
                    uint32_t & timestamp_fix_utc,
                    float & latitude,
                    float & longitude,
                    float & speed,
                    float & course);

private:

  GPRMC() { }
  GPRMC(GPRMC const &) { }

  enum class ParserState : int
  {
    MessadeId,
    UTCPositionFix,
    Status,
    LatitudeVal,
    LatitudeNS,
    LongitudeVal,
    LongitudeEW,
    SpeedOverGround,
    TrackAngle,
    Checksum,
    Done,
    Error
  };

  static ParserState handle_MessadeId        (char const * token);
  static ParserState handle_UTCPositionFix   (char const * token);
  static ParserState handle_Status           (char const * token);
  static ParserState handle_LatitudeVal      (char const * token, float & latitude);
  static ParserState handle_LatitudeNS       (char const * token, float & latitude);
  static ParserState handle_LongitudeVal     (char const * token, float & longitude);
  static ParserState handle_LongitudeEW      (char const * token, float & longitude);
  static ParserState handle_SpeedOverGround  (char const * token);
  static ParserState handle_TrackAngle       (char const * token);
  static ParserState handle_Checksum         (char const * token);

};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* nmea */

#endif /* ARDUINO_MTK3333_NMEA_GPRMC_PARSER_H_ */