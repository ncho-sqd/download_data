from yahoo_finance import Share
from pprint import pprint

snp=Share('^GSPC')
pprint(snp.get_historical('2010-01-01', '2016-07-01'))