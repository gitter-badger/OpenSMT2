(set-logic QF_BV)
(declare-fun v0 () (_ BitVec 4))
(declare-fun v1 () (_ BitVec 4))
(assert (or (= (_ extract 1 1 v0) (_ extract 1 1 v1)) (not (= (_ extract 1 1 v0) (_ extract 1 1 v1)))))
(check-sat)
