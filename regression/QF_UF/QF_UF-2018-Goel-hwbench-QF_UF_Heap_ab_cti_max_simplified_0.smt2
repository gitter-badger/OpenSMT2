(set-logic QF_UF)
(declare-sort u3 0)
(declare-sort u4 0)
(declare-sort u1 0)
(declare-sort u2 0)
(declare-fun Concat1 (Bool u1) u2)
(declare-fun Concat2 (u3 u4) u2)
(declare-fun y0 () Bool)
(declare-fun y1 () Bool)
(declare-fun y2 () Bool)
(declare-fun n00 () u4)
(declare-fun n01 () u3)
(declare-fun n02 () u1)
(declare-fun n03 () u2)
(declare-fun n11 () u3)
(declare-fun n10 () u2)
(declare-fun n40 () u2)
(declare-fun nitems () u3)
(declare-fun w18 () u2)
(declare-fun w1 () u2)
(declare-fun w3 () u2)

(assert (distinct n01 n11))
(assert (distinct n03 n10 n40))
(assert (= w18 (Concat2 nitems n00)))
(assert (= y0 (= n03 w18)))
(assert (= w1 (Concat1 y0 n02)))
(assert (= w3 (Concat1 false n02)))
(assert (= n03 w3))
(assert (= y1 (not (= n10 w1))))
(assert (= y2 (not (= n40 w18))))
(check-sat)
(exit)
