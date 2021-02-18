;; Packet = (@src, @tgt)
(declare-datatypes () ((Packet (mk-packet (src Int) (tgt Int)))))
;; Address Range = (@low, @high)
(declare-datatypes () ((AddrRange (mk-addr-range (low Int) (high Int)))))
;; Rule = allow/block packets w.r.t. from address range and to address range
(declare-datatypes () ((Rule (mk-rule (from AddrRange) (to AddrRange) (allow Bool)))))

;; True if packet p matches the from and to adresses in rule r, False otherwise
(define-fun matches-addr ((p Packet) (r Rule)) Bool
    (and (<= (low (from r)) (src p))
         (<= (src p) (high (from r)))
         (<= (low (to r)) (tgt p))
         (<= (tgt p) (high (to r)))
    )
)

;; True if packet p is allowed by rule r, False otherwise
(define-fun allowed ((p Packet) (r Rule)) Bool
    (and (matches-addr p r)
         (allow r)
    )
)

;; True if packet p is blocked by rule r, False otherwise
(define-fun blocked ((p Packet) (r Rule)) Bool
    (and (matches-addr p r)
         (not (allow r))
    )
)

;; Allow all packets [10;50] -> [127;255]
(define-fun r1 () Rule
    (mk-rule (mk-addr-range 10 50) (mk-addr-range 127 255) true)
)

;; Block all packets [40;80] -> [250;512]
(define-fun r2 () Rule
    (mk-rule (mk-addr-range 40 80) (mk-addr-range 250 512) false)
)

;; Packet p go through iff allowed by one of {r1,r2} and blocked by none of them
(define-fun firewall1 ((p Packet)) Bool
    (and (or (allowed p r1) (allowed p r2))
         (not (blocked p r1))
         (not (blocked p r2))
    )
)

;; Check if packet 12 -> 230 is allowed by firewall1
(push)
(echo "------- Is packet (12,230) allowed by firewall1?")
(assert (firewall1 (mk-packet 12 230)))
(check-sat)
(pop)

;; Check if some packet can go through firewall1
(push)
(echo "------- Is there a packet that can go through firewall1?")
(declare-const p Packet)
(assert (firewall1 p))
(check-sat)
(get-model)
(pop)

;; Check if firewall1 is inconsistent: some packet is allowed by rule r1 and
;; blocked by rule r2 (or conversely)
(push)
(echo "------- Are there inconsistencies between r1 and r2?")
(declare-const p Packet)
(assert
    (and (allowed p r1)
         (blocked p r2)
    )
)
(check-sat)
(get-model)
(pop)

;; Define firewall2 and check if it implements the same policy as firewall1
(push)
;; Allow packets [10;50] -> [127;250]
(define-fun r3 () Rule
    (mk-rule (mk-addr-range 10 50) (mk-addr-range 127 250) true)
)

;; Allow packets [10;40] -> [250;255]
(define-fun r4 () Rule
    (mk-rule (mk-addr-range 10 40) (mk-addr-range 250 255) true)
)

;; Packets go through if one of {r3,r4} allow and none of them block
(define-fun firewall2 ((p Packet)) Bool
    (and (or (allowed p r3) (allowed p r4))
         (not (blocked p r3))
         (not (blocked p r4))
    )
)

;; Inconsistencies between firewall1 and firewall2?
(declare-const p Packet)
(echo "------- Equivalence of firewall1 and firewall2?")
(assert (not (iff (firewall1 p) (firewall2 p))))
(check-sat)
(get-model)
(pop)

;; Define firewall3 and check if it implements the same policy as firewall1
(push)
;; Allow packets [10;39] -> [127;255]
(define-fun r5 () Rule
    (mk-rule (mk-addr-range 10 39) (mk-addr-range 127 255) true)
)

;; Allow packets [40;50] -> [127;249]
(define-fun r6 () Rule
    (mk-rule (mk-addr-range 40 50) (mk-addr-range 127 249) true)
)

;; Packets go through if one of {r5,r6} allow and none of them block
(define-fun firewall3 ((p Packet)) Bool
    (and (or (allowed p r5) (allowed p r6))
         (not (blocked p r5))
         (not (blocked p r6))
    )
)

;; Inconsistencies between firewall1 and firewall3?
(declare-const p2 Packet)
(echo "------- Equivalence of firewall1 and firewall3?")
(assert (not (iff (firewall1 p2) (firewall3 p2))))
(check-sat)
(pop)
