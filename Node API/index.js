const express = require("express");
const { send } = require("express/lib/response");
const app = express();

const port = 3000;

var sendBeep = true;

var count = 0;

app.get("/", (req,res) => {
    console.log("Someone Requested \n" + req.ip)
    count++;
    if(sendBeep) {
        res.status(200).send('Hello Arduino')
        sendBeep = false;
        return;
    }
    res.status(201).send("I don't wanna see you");
 


})

app.get("/beep", (req,res) => {
    res.status(200).send("I'll send notes <3")
    sendBeep = true;
})

app.listen(port,() => {
    console.log("We running on port " + port)
})