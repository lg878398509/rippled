#ifndef __WSDOOR__
#define __WSDOOR__

#include "../websocketpp/src/sockets/tls.hpp"
#include "../websocketpp/src/websocketpp.hpp"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>

#if 1
#define WSDOOR_SERVER	server
#else
#define WSDOOR_SERVER	server_tls
#endif

class WSDoor
{
private:
	websocketpp::WSDOOR_SERVER*	mEndpoint;
	boost::thread*				mThread;
	bool						mPublic;
	std::string					mIp;
	int							mPort;

	void		startListening();

public:

	WSDoor(const std::string& strIp, int iPort, bool bPublic) : mEndpoint(0), mThread(0), mPublic(bPublic), mIp(strIp), mPort(iPort) { ; }

	void		stop();

	static WSDoor* createWSDoor(const std::string& strIp, const int iPort, bool bPublic);
};

#endif

// vim:ts=4