

# 🍰 Use Chart.js
___
### USE chart
**1.Bubble chart**   
**2.Doughnut chart**   
**3.Line chart**   

___
### set up Chart.js  
html 에 chart 를 쓰기위해서는 세팅을 해주어야한다.  
js종류여서 script를 이용하여야한다.  
**canvas** 를 이용하여 차트를 불러와준다.     
**body**안에 써야한다.  
```
    <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.5.0/Chart.min.js"></script>
    <canvas id="bubble-chart" width="800" height="800"></canvas>
    <canvas id="doughnut-chart" width="800" height="450"></canvas>
    <canvas id="line-chart" width="800" height="450"></canvas>
    
```
___
### chart   

Bubble chart: mbti별 성격  

Doughnut chart: 혈액형별 인기순위  

Line chart: My life graph 를 구현하였다.

 ___
### Improvement   
우선 bubble chart  에서 x축을 보면 칸의 크기가 80으로 다른걸 알 수 있다.
이부분을 개선하기 위해서 options에
```
  ticks:{min:-100 , max:100}
```
으로 칸개수를 100으로 맞춰볼려했지만 화면이 아예 뜨지않았다...

```
    responsive:false
```
를 써서 바꿔보라는 말도 있었는데 이것도 위와같이 화면이 뜨지않았다..
### webHosting
>[netlify](https://loquacious-cuchufli-e1c176.netlify.app/)
