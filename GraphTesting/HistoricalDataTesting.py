import matplotlib.pyplot as plt
import matplotlib.dates as mdate
import csv
import os
import time
import collections
import matplotlib.ticker as mticker
from mpl_finance import candlestick_ohlc
import matplotlib.gridspec as gridspec

file_path = 'C:\AlgoTradingBot\AlgoTradingBot\Data'
value_dict = dict()
loop_number = input("How many files are you graphing?")
trading_type = input("Enter type increments of historical data: ")
for x in range(0, int(loop_number)):
    file_location = input("Enter a csv file name: ")

    with open(os.path.join(file_path,file_location) , 'r') as csvfile:
        next(csvfile)
        plots = csv.reader(csvfile, delimiter = ',')
        for row in plots:
            current_row = []
            timestamp = int(row[0])    
            current_row.append(float(row[1]))
            current_row.append(float(row[2]))
            current_row.append(float(row[3]))
            current_row.append(float(row[4]))
            current_row.append(float(row[5]))
            value_dict[timestamp] = current_row

ordered_value_dict = collections.OrderedDict(sorted(value_dict.items()))
price_values = {"open_price": [], "close_price": [], "high_price": [], "low_price":[], "volume": []}
ohlc = []
volumes = []
timestamps = []
bar_width = 0.6/ (24*(60/float(trading_type)))
for key, item in ordered_value_dict.items():
    #["open_price"] = item[0]
    #["close_price"] = item[1]
    #["high_price"] = item[2]
    #["low_price"] = item[3]
    #["volume"] = item[4]
    volumes.append(item[4])
    timestamps.append(mdate.epoch2num(key))
    append_me = mdate.epoch2num(key), item[0], item[2], item[3], item[1], item[4]
    ohlc.append(append_me)

plt.figure(figsize = (6,8))
gs1 = gridspec.GridSpec(2,1, height_ratios = [3,1])
gs1.update(wspace=0.025, hspace=0.05)

ax1 = plt.subplot(gs1[0])
date_fmt = '%d-%m-%y %H:%M:%S'
ax1.xaxis.set_major_formatter(mdate.DateFormatter(date_fmt))
ax1.xaxis.set_major_locator(mticker.MaxNLocator(10))

candlestick_ohlc(ax1, ohlc, width = float(bar_width), colorup='#77d879', colordown='#db3f3f')
plt.setp(ax1.get_xticklabels(), visible=False)
ax1.grid(True)
plt.xlabel('Date')
plt.ylabel('Price')
plt.title('Example')
#plt.subplots_adjust(left=0.09, bottom=0.20, right=0.94, top=0.90, wspace=0.2, hspace=0)

ax2 = plt.subplot(gs1[1], sharex=ax1)
for label in ax2.xaxis.get_ticklabels():
        label.set_rotation(90)
plt.bar(timestamps, volumes, width = float(bar_width))

plt.show()
