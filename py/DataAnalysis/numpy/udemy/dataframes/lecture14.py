import numpy as np
import pandas as pd
from pandas import Series, DataFrame

import webbrowser 
website="http://en.wikipedia.org/wiki/NFL_win-loss_records"
#webbrowser.open(website)

nfl_frame = pd.read_clipboard()

dframe = pd.read_table("20x20grid.txt", sep=" ", header=None)
print dframe