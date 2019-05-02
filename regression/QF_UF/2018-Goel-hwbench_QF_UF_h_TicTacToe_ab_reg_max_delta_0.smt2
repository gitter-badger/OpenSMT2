(set-logic QF_UF)
(declare-sort utt$2 0)
(declare-fun Concat (Bool Bool) utt$2)
(declare-fun y0 () utt$2)
(declare-fun y1 () utt$2)
(declare-fun y2 () utt$2)
(declare-fun b1 () Bool)
(declare-fun b2 () Bool)
(declare-fun b3 () Bool)
(assert (not (= y1 y2)))
(assert (not b1))
(assert (= b3 (ite b2 false b1)))
(assert (= y2 (Concat b3 false)))
(assert (= y1 (Concat false false)))
(check-sat)
(exit)