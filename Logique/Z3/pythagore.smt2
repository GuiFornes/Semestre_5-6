(declare-const x Int)
(declare-const y Int)
(define-fun somme_carree ((a Int)(b Int)) Int
       (+ (^ a 2) (^ b 2))
)

(define-fun cmp ((a Int)(b Int)(c Int)) Bool
       (> (somme_carree a b) c)
)

(assert (forall ((a Int)(b Int))
    (exists ((c Int))
        (cmp a b c)
        )
    )
)

(check-sat)
;(get-model)
