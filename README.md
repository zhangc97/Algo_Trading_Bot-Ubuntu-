# Algo Trading Bot

## Folders
* cppclient is the all API material
* TestCppClient is actual client that creates the socket connect

`$ git pull https://github.com/zhangc97/Algo_Trading_Bot-Linux-`

## Usage 
```
cd TestCppClient
make clean
make 
./TestCppClient
```
**Usage requires a TWS Trading Account**
**Default port is set to 7497 (Paper Trading Account)**
**Historical Data calls are located in** ``` ContractSamples.h ``` **and require a TWS data subscription**

## Future plans
* back test and deploy to brokerage account
* use ML to detect human sources 
* cross platform
* profit as a software
