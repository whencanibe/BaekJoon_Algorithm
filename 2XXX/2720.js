// const fs = require('fs');
// const input = fs.readFileSync('input.txt').toString().trim().split('\n'); // input.txt에서 읽기

//백준용 입력
const fs =require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

function getChange(cents){
    const coins = [25,10,5,1];
    let result = [];

    for(let coin of coins){
        result.push(Math.floor( cents / coin));
        cents %= coin;
    }

    console.log(result.join(' '));
}

function processInput(input){
    const T = parseInt(input[0]);

    for(let i = 1 ; i <= T ; i++){
        let cents = parseInt(input[i]);
        getChange(cents);
    }
}

processInput(input);