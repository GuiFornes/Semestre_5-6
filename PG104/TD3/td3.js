////////// Exercice  1  //////////
//Computes the addition between a and b
//in a tail-recursive manner
function addition(a, b) {
    if (b==0)
        return a;
    return addition(a+1, b-1);
}
console.log(addition(15, 23)); // -> 38
console.log(addition(15, 0)); // -> 15
//Computes the multiplication of 'a' and 'b'
//in a tail-recursive manner
//
//multiplication(a, b, acc) = * si b == 0, -> acc
//                            * sinon -> a + multiplication(a, b-1, acc + a)
function multiplication(a, b) {
    //private
    function multiplicationInt(a, b, acc) {
        //console.log(`a=${a}, b=${b}, acc=${acc}`);
        if (b == 0)
            return acc;
        else
            return multiplicationInt(a, b-1, acc+a);
    }
    return multiplicationInt(a, b, 0);
}
console.log(multiplication(3, 7)); // -> 21
console.log(multiplication(3, 0)); // -> 0
////////// Exercice  2  //////////

function fibo(n) {
    if (n==1 || n==2)
        return 1;
    else
        return fibo(n-1) + fibo(n-2);
}
console.log(fibo(5)); // -> 5
console.log(fibo(10)); // -> 5

function fiboGen(n, a, b) {
    if (n == 1)
        return a;
    if (n == 2)
        return b;
    else
        return fiboGen(n-1, a, b) + fiboGen(n-2, a, b);
}
console.log(fiboGen(10, 1, 1))
function fiboGenTR(n, a, b) {
    if (n == 1)
        return a;
    if (n == 2)
        return b;
    else
        //return fiboGen(n-1, a, b) + fiboGen(n-2, a, b);
        return fiboGenTR(n-1, b, a+b);
}
console.log(fiboGenTR(100, 1, 1))
////////// Exercice  3  //////////

function fact(n, p) {
    if (n<=1n)
	return p;
    else
	return fact(n-1n, n*p);
}
 
////////// Exercice  4  //////////

const memo = {};
 
const set = [7,3];
const v   = 10;
const key = `${v}[${set}]`;
memo[key] = true;
console.log(memo); // -> { '10[7,3]': true }

function subsetSum(S, v) {
    if ( S.length == 0 )
        return false;
    for (let i = 0; i < S.length ; i++){
        let temp = S[i];
        S = S.slice(i+1);
        if (v-temp == 0)
            return true;
        return subsetSum(S, v-temp);
    }
    return false;
}
console.log(subsetSum([ 1, 3, 7, 1 ], 10));
