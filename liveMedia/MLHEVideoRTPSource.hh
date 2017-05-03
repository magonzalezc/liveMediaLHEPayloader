// MLHE Video RTP Sources
// Implementation

#ifndef _MLHE_VIDEO_RTP_SOURCE_HH
#define _MLHE_VIDEO_RTP_SOURCE_HH

#ifndef _MULTI_FRAMED_RTP_SOURCE_HH
#include "MultiFramedRTPSource.hh"
#endif

#define MAX_MLHE_HEADER_SIZE 1024

class MLHEVideoRTPSource: public MultiFramedRTPSource {
public:
  static MLHEVideoRTPSource*
  createNew(UsageEnvironment& env, Groupsock* RTPgs,
	    unsigned char rtpPayloadFormat = 70,
	    unsigned rtpPayloadFrequency = 90000);

protected:
  virtual ~MLHEVideoRTPSource();

private:
  MLHEVideoRTPSource(UsageEnvironment& env, Groupsock* RTPgs,
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
