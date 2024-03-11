import pandas as pd
import json

menu = pd.read_json("menu.json")

menuData = pd.DataFrame(menu)

Arranged_menu = menuData.transpose()

convert_cols = ['Tall', 'Grande', 'Venti']

converted_menu = (Arranged_menu[convert_cols] * 55.5).round(2)

print(converted_menu)