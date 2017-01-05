// RTP sink for LHE codec
// C++ header

#ifndef _LHE_VIDEO_RTP_SINK_HH
#define _LHE_VIDEO_RTP_SINK_HH

#ifndef _VIDEO_RTP_SINK_HH
#include "VideoRTPSink.hh"
#endif

class LHEVideoRTPSink: public VideoRTPSink {
public:
  static LHEVideoRTPSink* createNew(UsageEnvironment& env, Groupsock* RTPgs);

protected:
  LHEVideoRTPSink(UsageEnvironment& env, Groupsock* RTPgs);
	// called only by createNew()

  virtual ~LHEVideoRTPSink();

};

#endif