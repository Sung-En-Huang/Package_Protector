// dataReceiver.js
const express = require("express");
const bodyParser = require("body-parser");

const app = express();
const port = 3000;

app.use(bodyParser.json());

app.get("/hello", (req, res) => {
  console.log("yessir");
  res.status(200).send("Hello, World!");
});

app.listen(port, "100.66.153.218", () => {
  console.log(`Server is running on port ${port}`);
});
