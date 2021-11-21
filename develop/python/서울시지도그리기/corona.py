import pandas as pd
import numpy as np
from pandas.io.json import json_normalize
import webbrowser
import folium
import math
from folium.features import DivIcon
from folium import plugins


def dist(tx, ty, dx, dy):
    return math.sqrt((tx-dx)**2 + (ty-dy)**2)
    

def min_dist(target_x, target_y):
    res = {}
    _min_dist = 1e10
    for i in range(len(df)):
        name, code, x, y = df.iloc[i]
        _dist = dist(target_x, target_y, x, y)
        if _min_dist > _dist: 
            _min_dist = _dist
            res['name'] = name
            res['code'] = code
            res['x'] = x
            res['y'] = y
    return res


state_geo = 'https://raw.githubusercontent.com/southkorea/seoul-maps/master/juso/2015/json/seoul_municipalities_geo_simple.json'

raw_data = pd.read_json(state_geo)
data = [
    ['도봉구', '11320', 127.03278382986406, 37.667199069165044],
    ['은평구', '11380', 126.92388486168254, 37.61600184192064],
    ['동대문구', '11230', 127.05326118159924, 37.58362488095133],
    ['동작구', '11590', 126.95219874667816, 37.50092869817122],
    ['금천구', '11545', 126.89911181670232, 37.46640549118321],
    ['구로구', '11530', 126.86939217118206, 37.49824594332609],
    ['종로구', '11110', 126.98444920906223, 37.59081035058071],
    ['강북구', '11305', 127.0215254728531, 37.632046746187775],
    ['중랑구', '11260', 127.09211952814929, 37.600870218534695],
    ['강남구', '11680', 127.07283998849552, 37.48909545646018],
    ['강서구', '11500', 126.81414741792146, 37.560886482642864],
    ['중구', '11140', 126.99506018214162, 37.558371750266666],
    ['강동구', '11740', 127.14885555264618, 37.551717380107696],
    ['광진구', '11215', 127.08974321215258, 37.55189624394916],
    ['마포구', '11440', 126.91488843257431, 37.55228785521782],
    ['관악구', '11620', 126.93583046752502, 37.47409667026501],
    ['서초구', '11650', 127.0339660401257, 37.46566083673712],
    ['성북구', '11290', 127.02240243094009, 37.60011928159995],
    ['노원구', '11350', 127.0775512372282, 37.64238136613501],
    ['송파구', '11710', 127.12101213187754, 37.50039326183675],
    ['성동구', '11200', 127.03850383263077, 37.55278841153847],
    ['서대문구', '11410', 126.94351606661385, 37.57925155480199],
    ['양천구', '11470', 126.8652013125735, 37.52284379192651],
    ['영등포구', '11560', 126.90733526751012, 37.523154626882516],
    ['용산구', '11170', 126.97963765655432, 37.53836767596737]
]

df = pd.DataFrame(data, columns=['name', 'code', 'x', 'y'])
df = df.sort_values(by=['name']).reset_index(drop=True)

df_corona = pd.read_csv("corona.csv", encoding='euc-kr').drop(["Unnamed: 0"], axis=1)
df_corona = df_corona.drop([4, 26]).reset_index(drop=True)    # '전체' 제거
df_corona.columns = ["name", "value"]
# print(df_corona)
# exit()

state_data = df_corona.sort_values(by=['name']).reset_index(drop=True)

df['value'] = state_data.value

# print(df, state_data)
# exit(0)

# Initialize the map:
m = folium.Map(location=[37.562225, 126.978555], tiles="cartodbpositron", zoom_start=12)

m.choropleth(
    geo_data=state_geo,
    name='코로나확진자수',
    data=state_data,
    columns=['name', 'value'],
    key_on='feature.properties.SIG_KOR_NM',
    color = 'gray',
    fill_color='YlGnBu',
    fill_opacity=0.7,
    line_opacity=0.5,
    legend_name = ''
)

for i in range(len(df)):
    name, code, x, y, count = df.iloc[i]
    
    folium.CircleMarker(
        [y, x],
        radius=40,
        fill_opacity=0.2,
        opacity=0.5,
        color='blue',
        fill_color='white',
        popup = folium.Popup('<div style="font-size: 10pt; width:50px; text-align:center">%s</div>' % name)
        ).add_to(m)

    folium.map.Marker(
        [y, x],
        icon=DivIcon(
            icon_size=(80,60),
            icon_anchor=(39, 27),
            html='<div style="font-size: 20px;text-align:center;">%s<br>%d</div>' % (name, count),
            )
        ).add_to(m)

# folium.LayerControl().add_to(m)

# Save to html
file_name = "corona.html"
m.save(file_name)
webbrowser.open_new(file_name)