var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().split(' ');
console.log(parseInt(input[0])+parseInt(input[1]));
