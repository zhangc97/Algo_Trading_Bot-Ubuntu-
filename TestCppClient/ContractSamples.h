#pragma once
#ifndef CONTRACTSAMPLE
#define CONTRACTSAMPLE

struct Contract;

class ContractSamples {
	public:
		//contracts go here
		static Contract NVDASTK();
		static Contract TSLASTK();
        static Contract IBMSTK();
        static Contract CASASTK();
        static std::vector<Contract> compileSTKS();
};

#endif
