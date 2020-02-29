var http = require("http");
var fs = require("fs");
var qs = require("querystring");

//var users = [];
//var i = 0;
var server = http.createServer(function (req, response) {
  //  req.url = req.url.replace(/%20/g, " ");
    console.log(req.url);
    switch (req.method) {
        case "GET":

            if (req.url === "/") {
                fs.readFile("index.html", function (error, data) {
                    response.writeHead(200, { 'Content-Type': 'text/html' });
                    response.write(data);
                    response.end();
                });
            }
            else if (req.url === "/Main.js") {
                fs.readFile("Main.js", function (error, data) {
                    response.writeHead(200, { 'Content-Type': 'text/javascript' });
                    response.write(data);
                    response.end();
                });
            }
            else if (req.url === "/Klocek.js") {
                fs.readFile("classes/Klocek.js", function (error, data) {
                    response.writeHead(200, { 'Content-Type': 'text/javascript' });
                    response.write(data);
                    response.end();
                });
            }
            else if (req.url === "/Game.js") {
                fs.readFile("classes/Game.js", function (error, data) {
                    response.writeHead(200, { 'Content-Type': 'text/javascript' });
                    response.write(data);
                    response.end();
                });
            }
            else if (req.url === "/Dobudowanie.js") {
                fs.readFile("classes/Dobudowanie.js", function (error, data) {
                    response.writeHead(200, { 'Content-Type': 'text/javascript' });
                    response.write(data);
                    response.end();
                });
            }
            else if (req.url === "/three.js") {
                fs.readFile("three.js", function (error, data) {
                    response.writeHead(200, { 'Content-Type': 'text/javascript' });
                    response.write(data);
                    response.end();
                });
            }
            else if (req.url === "/arial.js") {
                fs.readFile("arial.js", function (error, data) {
                    response.writeHead(200, { 'Content-Type': 'text/javascript' });
                    response.write(data);
                    response.end();
                });
            }
            else if (req.url === "/Intro.js") {
                fs.readFile("classes/Intro.js", function (error, data) {
                    response.writeHead(200, { 'Content-Type': 'text/javascript' });
                    response.write(data);
                    response.end();
                });
            }
            else if (req.url === "/ElementSiatki.js") {
                fs.readFile("classes/ElementSiatki.js", function (error, data) {
                    response.writeHead(200, { 'Content-Type': 'text/javascript' });
                    response.write(data);
                    response.end();
                });
            }
    
           
            break;
        case "POST":
            var allData = '';
            req.on("data", function (data) {
                // console.log("data: " + data)
                allData += data;

            })                
            break;
    }
})



server.listen(3000);
var socketio = require("socket.io")
var io = socketio.listen(server)
io.sockets.on("connection", function (client) {

    console.log("klient sie podłączył" + client.id)
    // client.id - unikalna nazwa klienta generowana przez socket.io
    client.emit("onconnect", {
        clientName: client.id
    })
    client.on("disconnect", function () {
        console.log("klient się rozłącza")
    })
    client.on("mouseposition", function (data) {
        console.log(data.posX + " - " + data.posY)
        client.broadcast.emit("mouseposition", { posX: data.posX, posY: data.posY });
    })


    client.on("budowanie", function (data) {
      
        client.broadcast.emit("budowanie", { posX: data.posX, posY: data.posY, posZ: data.posZ });
    })
    client.on("kolorowanie", function (data) {
      
        client.broadcast.emit("kolorowanie", { col: data.col,  });
    })
    client.on("ruszanie", function (data) {
        client.broadcast.emit("ruszanie", { posX: data.posX, posZ: data.posZ });
    })
    client.on("dobudowanie", function (data) {
        client.broadcast.emit("dobudowanie", { licz:data.licz });
    })
    client.on("obracanie", function (data) {
        client.broadcast.emit("obracanie", { rot: data.rot });
    })



   /* client.on("mouseposition", function (data) {
        console.log(data.posX + " - " + data.posY)
        io.sockets.emit("mouseposition", { posX: data.posX, posY: data.posY });
    })*/
})


console.log("serwer staruje na porcie 3000 - ten komunikat zobaczysz tylko raz")