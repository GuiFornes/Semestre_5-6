(declare-fun P ((Int)) Bool
)

(declare-fun Q ((Int)) Bool
)

(assert (not (iff (forall ((x Int)) (and (P x) (Q x))) (and (forall ((x Int)) (P x)) (forall ((x Int)) (Q x))))))

(check-sat)
