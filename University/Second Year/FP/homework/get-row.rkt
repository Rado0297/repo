#lang racket
(require rackunit)
(require rackunit/text-ui)
(require (only-in "./make-matrix.rkt" make-matrix))
(provide get-row)

; Искаме да можем да взимаме к-тия ред на дадена матрица.

(define (get-row matrix k)
  (if (= 0 k) (car matrix)
      (get-row (cdr matrix) (- k 1))
  )
)

(define tests
  (test-suite "Get row tests"
    (check-equal? (get-row (make-matrix (range 1 7) 2 3) 1) '(4 5 6))
    (check-equal? (get-row (make-matrix (range 1 101) 5 10) 3) (range 31 41))
  )
)

(run-tests tests 'verbose)