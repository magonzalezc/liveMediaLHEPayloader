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
				rtpTimestampFrequency);
}

LHEVideoRTPSource::LHEVideoRTPSource(UsageEnvironment& env,
				       Groupsock* RTPgs,
				       unsigned char rtpPayloadFormat,
				       unsigned rtpTimestampFrequency,
				       unsigned defaultWidth, unsigned defaultHeight)
  : MultiFramedRTPSource(env, RTPgs,
			 rtpPayloadFormat, rtpTimestampFrequency,
			 new LHEBufferedPacketFactory) {
}

LHEVideoRTPSource::~LHEVideoRTPSource() {
}

char const* LHEVideoRTPSource::MIMEtype() const {
  return "video/lhe";
}

////////// LHEBufferedPacket and LHEBufferedPacketFactory implementation

void LHEBufferedPacket::reset() {
  BufferedPacket::reset();
}

unsigned LHEBufferedPacket
::nextEnclosedFrameSize(unsigned char*& framePtr, unsigned dataSize) {

  return dataSize;
}

BufferedPacket* LHEBufferedPacketFactory
::createNewPacket(MultiFramedRTPSource* /*ourSource*/) {
  return new LHEBufferedPacket;
}