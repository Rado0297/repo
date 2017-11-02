#lang racket
(require "helpers.rkt")
(require rackunit)
(require rackunit/text-ui)
;1.3 - Съчинете процедура, която по дадени три числа, намира сумата от квадратите на по-големите две от тях.
; За по-удобно, може да разбиете задачата на по-малки такива.

(define (squares-sum-bigger-two a b c)
  (if (and (> a b) (> b c)) (+ (* a a) (* b b)) 0)
  (if (and (> b a) (> a c)) (+ (* a a) (* b b)) 0)

  (if (and (> a c) (> c b)) (+ (* a a) (* c c)) 0)
  (if (and (> c a) (> a b)) (+ (* a a) (* c c)) 0)

  (if (and (> b c) (> c a)) (+ (* b b) (* c c)) 0)
  (if (and (> c b) (> b a)) (+ (* b b) (* c c)) 0)
)

(define tests
  (test-suite
    "Sum of squares tests"

    (let ((a (random 10))
          (b (random 10))
          (c (random 10)))
      
    (check-true (all-equal? (map (lambda (args) (apply squares-sum-bigger-two args))
                                (permute (list a b c)))))
)))

(run-tests tests 'verbose)