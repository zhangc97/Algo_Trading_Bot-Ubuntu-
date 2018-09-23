#include "StdAfx.h"

#include "ContractSamples.h"

#include "Contract.h"

std::vector<Contract> ContractSamples::compileSTKS()
{
    std::vector<Contract> stk_list;
    stk_list.push_back(NVDASTK());
    stk_list.push_back(TSLASTK());
    stk_list.push_back(IBMSTK());
    stk_list.push_back(CASASTK());

    return stk_list;
}
Contract ContractSamples::NVDASTK() {
	//! [NVIDIA stock contract]
	Contract contract;
	contract.symbol = "NVDA";
	contract.secType = "STK";
	contract.currency = "USD";
	contract.exchange = "SMART";
	contract.primaryExchange = "NASDAQ";
	//! [NVIDIA stock contract]
	return contract;
}

Contract ContractSamples::IBMSTK()
{
    Contract contract;
    contract.symbol = "IBM";
    contract.secType = "STK";
    contract.currency = "USD";
    contract.exchange = "SMART";
    contract.primaryExchange = "NASDAQ";
    return contract;
}

Contract ContractSamples::CASASTK()
{
    Contract contract;
    contract.symbol = "CASA";
    contract.secType = "STK";
    contract.currency = "USD";
    contract.exchange = "SMART";
    contract.primaryExchange = "NASDAQ";
    return contract;
}

Contract ContractSamples::TSLASTK() {
	Contract contract;
	contract.symbol = "TSLA";
	contract.secType = "STK";
	contract.currency = "USD";
	contract.exchange = "SMART";
	contract.primaryExchange = "NASDAQ";
	return contract;
}
