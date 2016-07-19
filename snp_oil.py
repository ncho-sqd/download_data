from yahoo_finance import Share
from pprint import pprint

start_dt = '2010-01-01'
end_dt = '2016-07-01'

snp=Share('^GSPC')
oil=Share('BZU16.NYM')
pprint(snp.get_historical(start_dt,end_dt))
pprint(oil.get_historical(start_dt,end_dt))

http://stackoverflow.com/questions/12433076/download-history-stock-prices-automatically-from-yahoo-finance-in-python
from pandas.datareader
