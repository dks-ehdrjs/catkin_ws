// Generated by gencpp from file ublox_msgs/CfgRST.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_CFGRST_H
#define UBLOX_MSGS_MESSAGE_CFGRST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ublox_msgs
{
template <class ContainerAllocator>
struct CfgRST_
{
  typedef CfgRST_<ContainerAllocator> Type;

  CfgRST_()
    : navBbrMask(0)
    , resetMode(0)
    , reserved1(0)  {
    }
  CfgRST_(const ContainerAllocator& _alloc)
    : navBbrMask(0)
    , resetMode(0)
    , reserved1(0)  {
  (void)_alloc;
    }



   typedef uint16_t _navBbrMask_type;
  _navBbrMask_type navBbrMask;

   typedef uint8_t _resetMode_type;
  _resetMode_type resetMode;

   typedef uint8_t _reserved1_type;
  _reserved1_type reserved1;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(CLASS_ID)
  #undef CLASS_ID
#endif
#if defined(_WIN32) && defined(MESSAGE_ID)
  #undef MESSAGE_ID
#endif
#if defined(_WIN32) && defined(NAV_BBR_HOT_START)
  #undef NAV_BBR_HOT_START
#endif
#if defined(_WIN32) && defined(NAV_BBR_WARM_START)
  #undef NAV_BBR_WARM_START
#endif
#if defined(_WIN32) && defined(NAV_BBR_COLD_START)
  #undef NAV_BBR_COLD_START
#endif
#if defined(_WIN32) && defined(NAV_BBR_EPH)
  #undef NAV_BBR_EPH
#endif
#if defined(_WIN32) && defined(NAV_BBR_ALM)
  #undef NAV_BBR_ALM
#endif
#if defined(_WIN32) && defined(NAV_BBR_HEALTH)
  #undef NAV_BBR_HEALTH
#endif
#if defined(_WIN32) && defined(NAV_BBR_KLOB)
  #undef NAV_BBR_KLOB
#endif
#if defined(_WIN32) && defined(NAV_BBR_POS)
  #undef NAV_BBR_POS
#endif
#if defined(_WIN32) && defined(NAV_BBR_CLKD)
  #undef NAV_BBR_CLKD
#endif
#if defined(_WIN32) && defined(NAV_BBR_OSC)
  #undef NAV_BBR_OSC
#endif
#if defined(_WIN32) && defined(NAV_BBR_UTC)
  #undef NAV_BBR_UTC
#endif
#if defined(_WIN32) && defined(NAV_BBR_RTC)
  #undef NAV_BBR_RTC
#endif
#if defined(_WIN32) && defined(NAV_BBR_AOP)
  #undef NAV_BBR_AOP
#endif
#if defined(_WIN32) && defined(RESET_MODE_HW_IMMEDIATE)
  #undef RESET_MODE_HW_IMMEDIATE
#endif
#if defined(_WIN32) && defined(RESET_MODE_SW)
  #undef RESET_MODE_SW
#endif
#if defined(_WIN32) && defined(RESET_MODE_GNSS)
  #undef RESET_MODE_GNSS
#endif
#if defined(_WIN32) && defined(RESET_MODE_HW_AFTER_SHUTDOWN)
  #undef RESET_MODE_HW_AFTER_SHUTDOWN
#endif
#if defined(_WIN32) && defined(RESET_MODE_GNSS_STOP)
  #undef RESET_MODE_GNSS_STOP
#endif
#if defined(_WIN32) && defined(RESET_MODE_GNSS_START)
  #undef RESET_MODE_GNSS_START
#endif

  enum {
    CLASS_ID = 6u,
    MESSAGE_ID = 4u,
    NAV_BBR_HOT_START = 0u,
    NAV_BBR_WARM_START = 1u,
    NAV_BBR_COLD_START = 65535u,
    NAV_BBR_EPH = 1u,
    NAV_BBR_ALM = 2u,
    NAV_BBR_HEALTH = 4u,
    NAV_BBR_KLOB = 8u,
    NAV_BBR_POS = 16u,
    NAV_BBR_CLKD = 32u,
    NAV_BBR_OSC = 64u,
    NAV_BBR_UTC = 128u,
    NAV_BBR_RTC = 256u,
    NAV_BBR_AOP = 32768u,
    RESET_MODE_HW_IMMEDIATE = 0u,
    RESET_MODE_SW = 1u,
    RESET_MODE_GNSS = 2u,
    RESET_MODE_HW_AFTER_SHUTDOWN = 4u,
    RESET_MODE_GNSS_STOP = 8u,
    RESET_MODE_GNSS_START = 9u,
  };


  typedef boost::shared_ptr< ::ublox_msgs::CfgRST_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::CfgRST_<ContainerAllocator> const> ConstPtr;

}; // struct CfgRST_

typedef ::ublox_msgs::CfgRST_<std::allocator<void> > CfgRST;

typedef boost::shared_ptr< ::ublox_msgs::CfgRST > CfgRSTPtr;
typedef boost::shared_ptr< ::ublox_msgs::CfgRST const> CfgRSTConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::CfgRST_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::CfgRST_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ublox_msgs::CfgRST_<ContainerAllocator1> & lhs, const ::ublox_msgs::CfgRST_<ContainerAllocator2> & rhs)
{
  return lhs.navBbrMask == rhs.navBbrMask &&
    lhs.resetMode == rhs.resetMode &&
    lhs.reserved1 == rhs.reserved1;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ublox_msgs::CfgRST_<ContainerAllocator1> & lhs, const ::ublox_msgs::CfgRST_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ublox_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::CfgRST_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::CfgRST_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::CfgRST_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::CfgRST_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::CfgRST_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::CfgRST_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::CfgRST_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a1d02f583dd30373e526af3ea4137f5d";
  }

  static const char* value(const ::ublox_msgs::CfgRST_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa1d02f583dd30373ULL;
  static const uint64_t static_value2 = 0xe526af3ea4137f5dULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::CfgRST_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/CfgRST";
  }

  static const char* value(const ::ublox_msgs::CfgRST_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::CfgRST_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# CFG-RST (0x06 0x04)\n"
"# Reset Receiver / Clear Backup Data Structures\n"
"#\n"
"# Don't expect this message to be acknowledged by the receiver.\n"
"#  - Newer FW version won't acknowledge this message at all.\n"
"#  - Older FW version will acknowledge this message but the acknowledge may not\n"
"#    be sent completely before the receiver is reset.\n"
"#\n"
"\n"
"uint8 CLASS_ID = 6\n"
"uint8 MESSAGE_ID = 4 \n"
"\n"
"uint16 navBbrMask # BBR Sections to clear. \n"
"# The following Special Sets apply:\n"
"uint16 NAV_BBR_HOT_START = 0       # Hot start the device\n"
"uint16 NAV_BBR_WARM_START = 1      # Warm start the device\n"
"uint16 NAV_BBR_COLD_START = 65535  # Cold start the device\n"
"uint16 NAV_BBR_EPH = 1       # Ephemeris\n"
"uint16 NAV_BBR_ALM = 2       # Almanac\n"
"uint16 NAV_BBR_HEALTH = 4    # Health\n"
"uint16 NAV_BBR_KLOB = 8      # Klobuchar parameters\n"
"uint16 NAV_BBR_POS = 16      # Position\n"
"uint16 NAV_BBR_CLKD = 32     # Clock Drift\n"
"uint16 NAV_BBR_OSC = 64      # Oscillator Parameter\n"
"uint16 NAV_BBR_UTC = 128     # UTC Correction + GPS Leap Seconds Parameters\n"
"uint16 NAV_BBR_RTC = 256     # RTC\n"
"uint16 NAV_BBR_AOP = 32768   # Autonomous Orbit Parameters\n"
"\n"
"uint8 resetMode              # Reset Type:\n"
"uint8 RESET_MODE_HW_IMMEDIATE = 0       # Hardware reset (Watchdog) immediately\n"
"uint8 RESET_MODE_SW = 1                 # Controlled Software reset\n"
"uint8 RESET_MODE_GNSS = 2               # Controlled Software reset (GNSS only)\n"
"uint8 RESET_MODE_HW_AFTER_SHUTDOWN = 4  # Hardware reset (Watchdog) after \n"
"                                        # shutdown\n"
"uint8 RESET_MODE_GNSS_STOP = 8          # Controlled GNSS stop\n"
"uint8 RESET_MODE_GNSS_START = 9         # Controlled GNSS start\n"
"\n"
"uint8 reserved1     # Reserved\n"
;
  }

  static const char* value(const ::ublox_msgs::CfgRST_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::CfgRST_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.navBbrMask);
      stream.next(m.resetMode);
      stream.next(m.reserved1);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CfgRST_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::CfgRST_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::CfgRST_<ContainerAllocator>& v)
  {
    s << indent << "navBbrMask: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.navBbrMask);
    s << indent << "resetMode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.resetMode);
    s << indent << "reserved1: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.reserved1);
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_CFGRST_H
