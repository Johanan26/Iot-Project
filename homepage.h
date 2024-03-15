String homePagePart1 = F(R"=====(<!DOCTYPE html>
<html lang="en" >
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1, viewport-fit=cover">
<meta http-equiv="refresh" content="5">
<title>Smart Terrarium Web</title>
<style>
body {
  background-color: #f0f0f0;
  font-family: Arial, sans-serif;
}
.navbar {
  background-color: #333;
  overflow: hidden;
}
.navbar a {
  float: left;
  display: block;
  color: #f2f2f2;
  text-align: center;
  padding: 14px 16px;
  text-decoration: none;
}
.navbar a:hover {
  background-color: #ddd;
  color: black;
}
.flex-Container {
  display: flex;
  flex-direction: column;
  background-color: #fff;
  align-items: center;
  margin: 20px;
  padding: 20px;
  border-radius: 10px;
  box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
}
h1 {
  font-size: 40px;
  color: #333;
}
p {
  font-size: 18px;
  color: #555;
}
table {
  width: 100%;
  border-collapse: collapse;
  margin-top: 20px;
}
th, td {
  font-size: 20px;
  padding: 12px;
  text-align: left;
  border-bottom: 1px solid #ddd;
}
</style>
</head>
<body>
<div class="flex-Container">
  <h1>Smart Terrarium Data Website</h1>
  <p>Welcome to the Smart Terrarium display at ATU</p>
  <table>
    <tr>
      <th>Sensor</th>
      <th>Value</th>
      <th>Unit</th>
    </tr>
    <tr>
      <td>Temperature</td>
      <td>)=====");

String homePagePart2 = F(R"=====(</td>
      <td>Degree Cel</td>
    </tr>
    <tr>
      <td>Humidity</td>
      <td>)=====");

String homePagePart3 = F(R"=====(</td>
      <td>Kg/L</td>
    </tr>
    <tr>
      <td>Water Level</td>
      <td>)=====");

String homePagePart4 = F(R"=====(</td>
      <td>%</td>
    </tr>
    <tr>
      <td>Soil</td>
      <td>)=====");

String homePagePart5 = F(R"=====(</td>
      <td>Status</td>
    </tr>
  </table>
</div>

</body>

</html>)=====");

//
<!doctype html>
 
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Smart Terrarium</title>
  <link rel="icon" type="image/x-icon" href="sample-logo.jpg">
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.5.1/css/all.min.css" integrity="sha512-DTOQO9RWCH3ppGqcWaEA1BIZOC6xxalwEsw9c2QQeAIftl+Vegovlnee1c9QX4TctnWMn13TZye+giMm8e2LwA==" crossorigin="anonymous" referrerpolicy="no-referrer" />
  <style>
    .flex-Container{
        display: flex;
        flex-direction: column;
    }
    .flex-row {
        display: flex;
        flex-direction: column;
        align-items: center;
    }
 
    .flex-col{
      display: flex;
        flex-direction: row;
      align-items: center;
      justify-content:space-evenly;
        border-bottom: 5px solid black;
        padding: 20px;
    }
    img{
        width: 200px;
        height: auto;
    }
    html{
      scroll-behavior: smooth;
    }
    body{
        margin: 0px;
        padding: 0px;
    }
     #SmartTerarrium{
      background-color:rgb(0, 158, 206);
    }
    #DHT11{
        background-color:rgb(98, 157, 247);
 
    }
    #Waterlevel{
        background-color: rgb(90, 171, 236);
    }
    #SoilMoisture{
        background-color: rgb(54, 112, 238);
    }
  </style>
 
 
</head>
 
<body>
    <div class="flex-Container" >
          <div class="flex-col" id="#SmartTerarrium">

            <div class="flex-row">
              <h1>Smart Terrarium</h1>
              <p>The Smart Terrarium is the new and innovative way to keep your home immersed in nature</p>
            </div>
        </div>
        <div class="flex-col" id="DHT11">
            <div class="flex-row">
                <h1>DHT11</h1>
                <p>Temp:</p>
                <p>Humidity:</p>
            </div>
            <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/2413135/charts/1?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&xaxis=Time&yaxis=TempC"></iframe>
            <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/2413135/charts/2?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line"></iframe>
        </div>
        <div class="flex-col" id="Waterlevel">
            <div class="flex-row">
                <h1>Water level</h1>
                <p>Level</p>
 
            </div>
            <iframe width="450" height="260" style="border: 1px solid #cccccc;" src="https://thingspeak.com/channels/2413135/widgets/819996"></iframe>
        </div>
        <div class="flex-col" id="SoilMoisture">
            <div class="flex-row" class="test">
                <h1>Siol moisutere</h1>
                <p>Soil Status</p>
            </div>
        </div>
    </div>
 
</body>