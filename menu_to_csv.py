import pandas as pd
import json

menu = pd.read_json("menu.json")

menuData = pd.DataFrame(menu)

Arranged_menu = menuData.transpose()

Arranged_menu.to_xarray()   