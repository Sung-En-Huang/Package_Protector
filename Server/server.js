// dataReceiver.js
const express = require("express");
const bodyParser = require("body-parser");
require("dotenv").config();

const app = express();
const port = 3000;
const accountSid = "AC969f05faf0dbe841b4f4316b8a0db065";
const authToken = "51696e65e87056314ab9c414c565ba11";
const client = require("twilio")(accountSid, authToken);
app.use(bodyParser.json());
console.log("ACCOUNT", accountSid);

app.get("/hello", (req, res) => {
  console.log("yessir");
  client.messages
    .create({
      body: "This is the ship that made the Kessel Run in fourteen parsecs?",
      from: "+14345428567",
      to: "+16479720017",
    })
    .then((message) => console.log(message.sid));
  res.status(200).send("Hello, World!");
});

app.post("/picture", (req, res) => {
  // Access the data sent in the request body
  const postData = req.body;

  // Process the data (you can save it to a database, perform actions, etc.)
  console.log("Received data:", postData);

  // Respond to the client
  res.status(200).json({ message: "Data received successfully" });
});

app.listen(port, "100.66.153.218", () => {
  console.log(`Server is running on port ${port}`);
});
