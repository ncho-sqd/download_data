from yahoo_finance import Share
from pprint import pprint
from tabulate import tabulate
import pandas as pd
from datetime import datetime as dt

start_dt = '2016-01-01'
end_dt = dt.today().strftime("%Y-%m-%d")

snp=Share('^GSPC')
oil=Share('BZU16.NYM')

snp_list = snp.get_historical(start_dt,end_dt)
df=pd.DataFrame(snp_list)
print df

#http://stackoverflow.com/questions/12433076/download-history-stock-prices-automatically-from-yahoo-finance-in-python
#from pandas.datareader
