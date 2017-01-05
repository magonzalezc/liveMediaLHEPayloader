// LHE Video RTP Sources
// Implementation

#include "LHEVideoRTPSource.hh"

////////// LHEBufferedPacket and LHEBufferedPacketFactory //////////

class LHEBufferedPacket: public BufferedPacket {
public:
  Boolean completesFrame;

private:
  // Redefined virtual functions:
  virtual void reset();
  virtual unsigned nextEnclosedFrameSize(unsigned char*& framePtr,
					 unsigned dataSize);
};

class LHEBufferedPacketFactory: public BufferedPacketFactory {
private: // redefined virtual functions
  virtual BufferedPacket* createNewPacket(MultiFramedRTPSource* ourSource);
};


////////// JPEGVideoRTPSource implementation //////////

#define BYTE unsigned char
#define WORD unsigned
#define DWORD unsigned long

LHEVideoRTPSource*
LHEVideoRTPSource::createNew(UsageEnvironment& env, Groupsock* RTPgs,
			      unsigned char rtpPayloadFormat,
			      unsigned rtpTimestampFrequency,
			      unsigned defaultWidth, unsigned defaultHeight) {
  return new LHEVideoRTPSource(env, RTPgs, rtpPayloadFormat,
				rtpTimestampFrequency, defaultWidth, defaultHeight);
}

LHEVideoRTPSource::LHEVideoRTPSource(UsageEnvironment& env,
				       Groupsock* RTPgs,
				       unsigned char rtpPayloadFormat,
				       unsigned rtpTimestampFrequency,
				       unsigned defaultWidth, unsigned defaultHeight)
  : MultiFramedRTPSource(env, RTPgs,
			 rtpPayloadFormat, rtpTimestampFrequency,
			 new LHEBufferedPacketFactory),
    fDefaultWidth(defaultWidth), fDefaultHeight(defaultHeight) {
}

LHEVideoRTPSource::~LHEVideoRTPSource() {
}

char const* LHEVideoRTPSource::MIMEtype() const {
  return "video/lhe";
}