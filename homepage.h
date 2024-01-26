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
