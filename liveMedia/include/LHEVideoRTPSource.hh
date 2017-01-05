// LHE Video RTP Sources
// Implementation

#ifndef _LHE_VIDEO_RTP_SOURCE_HH
#define _LHE_VIDEO_RTP_SOURCE_HH

#ifndef _MULTI_FRAMED_RTP_SOURCE_HH
#include "MultiFramedRTPSource.hh"
#endif

class LHEVideoRTPSource: public MultiFramedRTPSource {
public:
  static LHEVideoRTPSource*
  createNew(UsageEnvironment& env, Groupsock* RTPgs,
	    unsigned char rtpPayloadFormat = 69,
	    unsigned rtpPayloadFrequency = 90000,
	    unsigned defaultWidth = 0, unsigned defaultHeight = 0);

protected:
  virtual ~LHEVideoRTPSource();

private:
  LHEVideoRTPSource(UsageEnvironment& env, Groupsock* RTPgs,
		     unsigned char rtpPayloadFormat,
		     unsigned rtpTimestampFrequency,
		     unsigned defaultWidth, unsigned defaultHeight);
      // called only by createNew()

  // Image dimensions from the SDP description, if any
  unsigned fDefaultWidth, fDefaultHeight;

private:
  virtual char const* MIMEtype() const;
};

#endif
