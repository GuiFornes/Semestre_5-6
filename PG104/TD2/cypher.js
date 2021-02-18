////////// Exercice  1  //////////
 
function cypher (str, offset) {
    let res = "";
    const codeA  = "a".charCodeAt(0); // character code of "a"
    const extent = 26;                // number of letters in alphabet
    const realoffset = ((offset % extent) + extent) % extent;
    for (let i = 0; i < str.length; i++) {
        const code   = str.charCodeAt(i);
        if ((code >= codeA) && (code <= codeA + extent)) {
            const newcode = ((code-codeA+realoffset) % extent) + codeA;
            res += String.fromCharCode(newcode);
        } else {
            res += str[i];
        }
    }
    return res;
}
 
cypher("abcde", 1);  // -> "bcdef"
cypher("bcdef", -1); // -> "abcde"
cypher("abcde", 13); // -> "nopqr"
cypher("nopqr", 13); // -> "abcde"

function make_cypher(key){
    //const key = 13;
    function hidden_cypher(str) {
        return cypher(str, key);
    }
    function hidden_decoder(str) {
        return cypher(str, 26-key);
    }
    return [ hidden_cypher, hidden_decoder ];
}
let [ code, decode ] = make_cypher(Math.floor(Math.random() * 26));

let my_string = "les carottes sont cuites";
let my_encoded_string = code(my_string);
let my_decoded_string = decode(my_encoded_string);
console.log(`${my_string} -> ${my_encoded_string} -> ${my_decoded_string}`);

////////// Exercice  2  //////////
function pgcd(a, b) {
    if ( b > a )
        return pgcd(b, a);
    if ( b == 0 )
        return a;
    return pgcd(b, a%b);
}
console.log(`pgcd(25, 15) = ${pgcd(25, 15)} \npgcd(128, 31) = ${pgcd(128, 31)}\npgcd(5, 0) = ${pgcd(5, 0)}\npgcd(0, 5) = ${pgcd(0, 5)}`);


////////// Exercice  3  //////////

//sum(x, y) == sum(x+1, y) + x
function sumInteger(x, y) {
    if ( x > y )
        return 0;
    if ( x < y )
        return x + sumInteger(x+1, y);
    return y;
}
console.log(sumInteger(1, 5)); // -> 15
console.log(sumInteger(5, 1)); // -> 0

function sumSquares(x, y) {
    if ( x > y )
        return 0;
    if ( x < y )
        return x*x + sumSquares(x+1, y);
    return y*y;
}
console.log(sumSquares(1, 5)); // -> 55
console.log(sumSquares(5, 1)); // -> 0

function sumGeneric(x, y, f) {
    if ( x > y )
        return 0;
    if ( x < y )
        return f(x) + sumGeneric(x+1, y, f);
    return f(y);
}

console.log(sumGeneric(1, 4, function(t){return t+1;})); //
////////// Exercice  4  //////////
function powerLinear(x, n) {
    if ( n > 1 )
        return powerLinear(x, n-1)*x;
    return x;
}
console.log(powerLinear(2, 10)); // -> 1024
console.log(powerLinear(7, 18)); // -> 1628413597910449

function powerLogarithmic(x, n) {
    if ( n == 1 )
        return x;
    if (n%2==1)
        return x*powerLogarithmic(x, n-1);
    return powerLogarithmic(x, n/2)**2;
}
console.log(powerLogarithmic(2, 10)); // -> 1024
console.log(powerLogarithmic(7, 18)); // -> 1628413597910449
////////// Exercice  5  //////////
//const myEven = (x) => !(x % 2);
//const myOdd = (x) => (x % 2);

function myOdd(x) {
    if ( x == 0 )
        return false;
    else
        return myEven(x-1);
}

function myEven(x) {
    if ( x == 0 )
        return true;
    else
        return myOdd(x-1);
}
console.log(myEven(8));
console.log(myOdd(5));
////////// Exercice  6  //////////
/*
 
convert(666) ;; -> "1010011010"
 
convert2Base(666, 2)  ;; -> '1010011010'
convert2Base(666, 3)  ;; -> '220200'
convert2Base(666, 16) ;; -> '29A'
 
////////// Exercice  7  //////////
 */
