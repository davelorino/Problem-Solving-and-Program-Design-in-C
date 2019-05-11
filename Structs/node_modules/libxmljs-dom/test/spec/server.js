var http = require('http');
var URL = require("url");
var qs = require("querystring");
var fs = require("fs");

var host = '0.0.0.0';
var port = 1337;

var server = http.createServer(function(req, res) {
    var url = URL.parse(req.url, true);
    var uri = url.pathname;
    if (uri === '/')
        uri = '/index.html'
    if (uri === '/specs.json') {
        res.write(JSON.stringify({
            element: JSON.parse(fs.readFileSync(__dirname+'/element.json'))
        }));
        res.end();
        return;
    }
    var file = __dirname+uri;
    console.log(url.method, uri)
    if (!fs.existsSync(file)) {
        res.write(404);
        res.end();
        return;
    }
    res.write(fs.readFileSync(file))
    res.end();
});

server.on('error', function(err) {
    console.log("ERROR:", error);
})

server.listen(port);

module.exports = {};
module.exports.host = host;
module.exports.port = port;
module.exports.close = function() {
    server.close();
}
