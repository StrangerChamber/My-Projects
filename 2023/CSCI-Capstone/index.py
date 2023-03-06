import streamlit as st
import datetime
import pandas as pd
import requests
from os import path
from requests.auth import HTTPBasicAuth

#THIS LOGS YOU IN AND GIVES YOU YOUR TOKEN
login_url = 'https://api2.watttime.org/v2/login'
token = requests.get(login_url, auth=HTTPBasicAuth('justin_energyhub', '4OXv0yc96zHRLLG*ve5mN6ykNp8UNd5'))



st.subheader("singsub")
st.write("SingBANCData")

st.subheader("wattsub")
st.write("WattTimeDf")





# Choose balancing authority to be displayed
option = st.selectbox(
    'Which balancing authority would you like to display?',
    ('BANC', 'AEC', 'AECI', 'AVA', 'AZPS'))

BAselection = option + ".csv"
fileToRead = "data/" + BAselection
selectBoxChoice = pd.read_csv(fileToRead)






# Choose timeframe to be displayed
startDate = datetime.date(2020, 1, 1)
d = st.date_input(
    "Select the start date of timeframe to be displayed (must be in year 2020):",
    startDate)

startDate = d
startDate = str(startDate)
if (startDate == "2020-01-01"):
    start = startDate + " 08:00:00+00:00"
else:
    start = startDate + " 00:00:00+00:00"

endDate = datetime.date(2020, 12, 31)
d = st.date_input(
    "Select the end date of timeframe to be displayed (must be in year 2020):",
    endDate)
endDate = d
endDate = str(endDate)
end = endDate + " 23:00:00+00:00"





# Create new dataframe with user selected dates for Singularity data
mask = (selectBoxChoice['datetime_utc'] >= start) & (selectBoxChoice['datetime_utc'] <= end)
selectBoxChoice = selectBoxChoice.loc[mask]





# Change start and end dates to be searchable in WattTime csv
WT_start = start.replace(" ", "T")
WT_end = end.replace(" ", "T")





# Create new dataframe with user selected dates using WattTime dataframe
# NOTE: unlike for the singularity charts, here we have hard coded in the balancing authority we are using
# This balancing authority data is grabbed in watttime_banc_2020.py
mask = (WattTimeDf['timestamp'] >= WT_start) & (WattTimeDf['timestamp'] <= WT_end)
WattTimeDf = WattTimeDf.loc[mask]





# Display Singularity area chart
st.write("Singularity Data Area Chart")
st.area_chart(data=selectBoxChoice, x="datetime_utc", y="consumed_co2_rate_lb_per_mwh_for_electricity")



# Display WattTime area chart
st.write("WattTime Data Area Chart")
st.area_chart(data=WattTimeDf, x="timestamp", y="MOER")





# Display Singularity line chart
st.write("Singularity Data Line Graph")
st.line_chart(data= selectBoxChoice,x="datetime_utc",y="consumed_co2_rate_lb_per_mwh_for_electricity")





# Display WattTime line chart
st.write("WattTime Data Line Graph")
st.line_chart(data= WattTimeDf,x="timestamp",y="MOER")





#violin plot for singularity data
st.write("Violin plot for first 3 months of 2020 (singularity data)")
t1 = "2020-02-01 00:00:00-08:00"
t2 = "2020-03-01 00:00:00-08:00"
jan = SingBANCData.loc[SingBANCData['datetime_local']<t1]['consumed_co2_rate_lb_per_mwh_for_electricity']
feb = SingBANCData.loc[SingBANCData['datetime_local']<t2]['consumed_co2_rate_lb_per_mwh_for_electricity']
mar = SingBANCData.loc[SingBANCData['datetime_local']>=t2]['consumed_co2_rate_lb_per_mwh_for_electricity']




toplot = list([jan,feb,mar])





violin, ax = plt.subplots()





xticklabels = ['Jan 2020', 'Feb 2020','Mar 2020']
ax.set_xticks([1, 2,3])
ax.set_xticklabels(xticklabels)
#axes.violinplot(df1['MOER'])
ax.violinplot(toplot)
st.pyplot(violin)