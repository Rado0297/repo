#lang racket
(require rackunit)
(require rackunit/text-ui)

; Искаме да вземем последния елемент на даден списък

(define (len-helper xs res)
  (if (null? xs) res
      (len-helper (cdr xs) (+ 1 res)))
)

(define (length xs)
  (len-helper xs 0)
)

(define (helper list start)
  (if (= (length list) start) (cdr list)
      (helper (car list) (+ 1 start))
  )
)

(define (last xs)
  (helper xs 0)
)

(define tests
  (test-suite "List ref tests"
    (check-equal? (last '(5 9 2)) 2)
    (check-equal? (last '(1 8 6 2 3)) 3)
    (check-equal? (last '(1)) 1)
    (check-equal? (last '(2 3)) 3)
  )
)

(run-tests tests 'verbose)