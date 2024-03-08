import pandas as pd
import json

menu = pd.read_json("menu.json")

df = pd.DataFrame(menu).unstack(fill_value=pd.NA)

print(df)