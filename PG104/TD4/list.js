// Functions on pointed pairs
function cons(_car, _cdr) { return { car: _car, cdr: _cdr }; }
const nil = {};
function car(cons)        { return cons['car']; }
function cdr(cons)        { return cons['cdr']; }

// Functions on lists
function head(l)    { return car(l); }
function tail(l)    { return cdr(l); }
function isEmpty(l) { return l === nil; }

////////// Exercice  1  //////////
function listIota(a, b) {
    if (a>=b)
        return nil;
    else
        return cons(a, listIota(a+1, b));
}

console.log(listIota(1,4)); // -> cons(1, cons(2, cons(3, nil)))
console.log(listIota(4,1)); // -> nil

function listDisp(l) {
    function listDispInt(l){

    if (isEmpty(l))
        return "";
    else if (isEmpty(tail(l))) //list of length = 1
        return `${head(l)}`;
    else
        return `${head(l)}, ${listDispInt(tail(l))}`;
    }
    return `[${listDispInt(l)}]`;
}

console.log(listDisp(nil));            // -> "[]"
console.log(listDisp(listIota(1, 4))); // -> "[1,2,3]"

////////// Exercice  2  //////////

function listLength(l) {
    if ( isEmpty(l) )
        return 0;
    else
        return 1 + listLength(tail(l));
}
console.log(listLength(nil));            // -> 0
console.log(listLength(listIota(1, 6))); // -> 5

////////// Exercice  3  //////////

function listAbsRec(l) {
    if ( isEmpty(l) ) {
        return nil;
    } else if (head(l) < 0){
        return cons(-head(l), listAbsRec(tail(l)));
    } else
        return cons(head(l), listAbsRec(tail(l)));
}
console.log(listDisp(listAbsRec(cons(1, cons(-2, nil))))); // -> cons(1, cons(2, nil))

////////// Exercice  4  //////////
function listAppend(l1, l2) {
    if ( isEmpty(l1) ){
        return l2;
    } else {
        return cons(head(l1), listAppend(tail(l1), l2));
    }
}
console.log(listDisp(listAppend(listIota(1, 3), listIota(1, 4)))); // -> [1,2,1,2,3]

function listAppendTR(l1, l2, aux) {
    if ( isEmpty(l1) && isEmpty(aux) ){
        return l2;
    } else if ( !isEmpty(l1) ){
        return listAppendTR(tail(l1), l2, cons(head(l1), aux));
    } else {
        return listAppendTR(l1, cons(head(aux), l2), tail(aux));
    }
}
console.log(listDisp(listAppendTR(listIota(1, 3), listIota(1, 4), nil))); // -> [1,2,1,2,3]

////////// Exercice  5  //////////

function listRotateLeft(l) {
    return listAppend(tail(l), cons(head(l), nil));
}
console.log(listDisp(listRotateLeft(listIota(1,5))));  // [1,2,3,4] -> [2,3,4,1]

//listRotateRight(listIota(1,5)); // [1,2,3,4] -> [4,1,2,3]

////////// Exercice  6  //////////
function listSortGen(l, cmp){
    //l = cons(l, nil);
    function insert(l, e, cmp) {
        if (isEmpty(l)){
            return cons(e, nil);
        } else if (cmp(head(l), e)){
            return cons(e, l);
        } else {
            return cons(head(l), insert(tail(l) , e, cmp));
        }
    }
    let out = nil;
    function listSortInsertNumbers(l, out, cmp){
        if ( isEmpty(l) ){
            return out;
        } else {
            out = insert(out, head(l), cmp);
            console.log(l, out);
            return listSortInsertNumbers(tail(l), out, cmp);
        }
    }
    return listSortInsertNumbers(l, out, cmp);
}

function sup(x, y) {
    return x>y;
}

function inf(x, y) {
    return x<y;
}
console.log(listDisp(listSortGen(cons(15, cons(4, cons(84, cons(-2, nil)))), sup)));
//console.log(listDisp(listSortGen(cons(15, cons(4, cons(84, -2))), inf)));
/*
function insert(l, e) {
    if (isEmpty(l)){
        return cons(e, nil);
    } else if (head(l)>e){
        return cons(e, l);
    } else {
        return cons(head(l), insert(tail(l) , e));
    }
}
console.log(listDisp(insert(listIota(1,5), 3)));

function listSortInsertNumbers(l, out){
    if ( isEmpty(l) ){
        return out;
    } else {
        out = insert(out, head(l));
        return listSortInsertNumbers(tail(l), out);
    }
}
//console.log(listDisp(listSortInsertNumbers(listIota(1,5))));
console.log(listDisp(listSortInsertNumbers(listRotateLeft(listIota(1,5)), nil)));
*/
////////// Exercice  7  //////////

/*
const left  = cons(1, cons(6, cons(8, cons(47, cons(87, nil)))));
const right = cons(3, cons(8, cons(9, cons(21, cons(50, nil)))));
listMerge(left, right); // -> [1,3,6,8,8,9,21,47,50,87]

const l4 = cons(3,cons(8,cons(9,cons(21,cons(50,nil)))));
getFirstHalf(l4); // -> [3,8,9]
get2ndHalf(l4);   //-> [21,50]

////////// Exercice  8  //////////
*/
