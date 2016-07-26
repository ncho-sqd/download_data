from yahoo_finance import Share
from pprint import pprint
from tabulate import tabulate
import pandas as pd
from datetime import datetime as dt
import statsmodels.formula.api as sm

start_dt = '2015-08-01'
end_dt = dt.today().strftime("%Y-%m-%d")

snp=Share('^GSPC')
oil=Share('BZU16.NYM')

snp_list = snp.get_historical(start_dt,end_dt)
df=pd.DataFrame(snp_list)
df["Adj_Ret"] = df["Adj_Close"].astype(float)/df["Adj_Close"].astype(float).shift(-1)-1
df["Abs_Adj_Ret"] = abs(df["Adj_Ret"])
df["Volume"] = df["Volume"].astype(float)

result = sm.ols(formula="Abs_Adj_Ret ~ Volume", data=df).fit()
print result.summary()


#http://stackoverflow.com/questions/12433076/download-history-stock-prices-automatically-from-yahoo-finance-in-python
#from pandas.datareader
