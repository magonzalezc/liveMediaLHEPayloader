// LHE Video RTP Sources
// Implementation

#ifndef _LHE_VIDEO_RTP_SOURCE_HH
#define _LHE_VIDEO_RTP_SOURCE_HH

#ifndef _MULTI_FRAMED_RTP_SOURCE_HH
#include "MultiFramedRTPSource.hh"
#endif

#define MAX_LHE_HEADER_SIZE 1024

class LHEVideoRTPSource: public MultiFramedRTPSource {
public:
  static LHEVideoRTPSource*
  createNew(UsageEnvironment& env, Groupsock* RTPgs,
	    unsigned char rtpPayloadFormat = 69,
	    unsigned rtpPayloadFrequency = 90000);

protected:
  virtual ~LHEVideoRTPSource();

private:
  LHEVideoRTPSource(UsageEnvironment& env, Groupsock* RTPgs,
		     unsigned char rtpPayloadFormat,
		     unsigned rtpTimestampFrequency);
      // called only by createNew()

protected:
  // redefined virtual functions:
  virtual Boolean processSpecialHeader(BufferedPacket* packet,
                                       unsigned& resultSpecialHeaderSize);

private:
  virtual char const* MIMEtype() const;
};

#endif
