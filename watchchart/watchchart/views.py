from django.shortcuts import render
from plotly.offline import plot
from plotly.graph_objs import Scatter
import requests
def index(request):
    result = requests.get('http://techpradnya.in:4040/getHealthReading')
    raw_data = result.json()
    temp = []
    timeDate = []
    heartRate = []
    for i in raw_data['records']:
        d1 = i
        for key, value in d1.items():
            if (key == "temp"):
                temp.append(value)
            elif (key == "timeDate"):
                timeDate.append(value)
            elif (key == "heartRate"):
                heartRate.append(value)
    y = timeDate.sort()
    x_data = timeDate
    y_data = temp
    plot_div = plot([Scatter(x=x_data, y=y_data,
                        mode='lines', name='test',
                        opacity=0.8, marker_color='green')],
               output_type='div')
    x_data = timeDate
    y_data = heartRate
    plot_div2 = plot([Scatter(x=x_data, y=y_data,
                             mode='lines', name='test',
                             opacity=0.8, marker_color='blue')],
                    output_type='div')
    return render(request, "index.html", context={'plot_div': plot_div,'plot_div2': plot_div2})
