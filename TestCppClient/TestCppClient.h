#pragma once

#ifndef testcppclient_h__INCLUDED
#define testcppclient_h__INCLUDED

#include "EWrapper.h"
#include "EReaderOSSignal.h"
#include "EReader.h"
#include "Contract.h"
#include <memory>
#include <vector>

struct file_row {
	time_t timestamp;
	double open_price;
	double close_price;
	double high_price;
	double low_price;
	int volume;
    int count; 
    double WAP;
};
class EClientSocket;

enum State {
	ST_CONNECT,
	ST_TEST,
	ST_PING,
	ST_PING_ACK,
	ST_HISTORICALDATAREQUEST,
	ST_HISTORICALDATAREQUESTS_ACK,
	ST_INITIALTEST
};
//! [ewrapperimpl]
class TestCppClient : public EWrapper
{
//! [ewrapperimpl]
	
public:
	TestCppClient();
	~TestCppClient();

	void setConnectOptions(const std::string&);
	void processMessages();

public:

	bool connect(const char* host, unsigned int port, int clientId = 0);
	void disconnect() const;
	bool isConnected() const;
    void STK_group_req();
	void outputCSV(std::vector<file_row>* pre_processed_file, std::string file_name);
private:
	//Functions go here
	void reqCurrentTime();
	void historicalDataRequests(const std::vector<Contract>& data);

public:
	//events
	#include "EWrapper_prototypes.h"

private:
	void printContractMsg(const Contract& contract);
	void printContractDetailsMsg(const ContractDetails& contractDetails);
	void printContractDetailsSecIdList(const TagValueListSPtr &secIdList);
	void printBondContractDetailsMsg(const ContractDetails& contractDetails);
	void ReadCSV();
    void ScanAndOutputMarketData(const file_row& data);
private:
	//variables
	double support;
	double ATH;
	double trending_mean;
	double previous_tick_price;
	int trading_volume;
	

private:
	//! [socket_declare]
	EReaderOSSignal m_osSignal;
	EClientSocket *const m_pClient;
	//! [socket_declare]
	State m_state;
	time_t m_sleepDeadline;

	OrderId m_orderId;
	EReader *m_pReader;
	bool m_extraAuth;
	std::string m_bboExchange;
};
#endif
