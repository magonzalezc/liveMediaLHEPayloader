// RTP sink for MLHE codec
// C++ header

#ifndef _MLHE_VIDEO_RTP_SINK_HH
#define _MLHE_VIDEO_RTP_SINK_HH

#ifndef _VIDEO_RTP_SINK_HH
#include "VideoRTPSink.hh"
#endif

class MLHEVideoRTPSink: public VideoRTPSink {
public:
  static MLHEVideoRTPSink* createNew(UsageEnvironment& env, Groupsock* RTPgs);

protected:
  MLHEVideoRTPSink(UsageEnvironment& env, Groupsock* RTPgs);
	// called only by createNew()

  virtual ~MLHEVideoRTPSink();
  virtual void doSpecialFrameHandling(unsigned fragmentationOffset,
                                      unsigned char* frameStart,
                                      unsigned numBytesInFrame,
                                      struct timeval framePresentationTime,
                                      unsigned numRemainingBytes);
  virtual
  Boolean frameCanAppearAfterPacketStart(unsigned char const* frameStart,
					 unsigned numBytesInFrame) const;
  //virtual unsigned specialHeaderSize() const;

};

#endif
