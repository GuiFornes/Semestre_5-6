function powerOfTwo(n) {
    return 2**n;
}


//the highest power of two : 2**53-1, mais ici 2**54.
for (let i = 0 ; i < 100 ; i++){
    console.log(`2**${i} = ${powerOfTwo(i)}`);
}

//the highest int : ~8.9e+307
let i = 0;
while ( powerOfTwo(i) < Infinity ){
    i++;
}
console.log(`max int is ${powerOfTwo(i-1)}`);

//BigInt are bigger than 'normal' integer
const twobig = 2n;

function bigPower(n) {
    return twobig**BigInt(n);
}
for (let i = 0 ; i < 100 ; i++){
    console.log(`2**${i} = ${bigPower(i)}`);
}

// Type error while adding it with a 'normal' integer
//console.log(twobig+5);
// concaten while adding it with a string
console.log(twobig+"string");

//included string
const string = 'this is a string';

console.log(string.includes('string'));

function square(n){
    return n**2;
}

function discriminant(a, b, c){
    return square(b)-4*a*c;
}

function evalQuadratic(a, b, c, x){
    return a*square(x)+b*x+c;
}

function root1(a, b, c){
    return -b-math.sqrt(discriminant(a, b, c))/(2*a);
}

function root2(a, b, c){
    return -b+math.sqrt(discriminant(a, b, c))/(2*a);
}

function caracQuadratique(a, b, c){
    if (discriminant(a, b, c) < 0){
        return '2 complexe roots';
    }
    if (discriminant(a, b, c) = 0){
        return '1 real root';
    }
    if (discriminant(a, b, c) > 0){
        return '2 real roots';
    }
}
